/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
/**
 * @file
 * This module generates the Lite C++ CopyOut functions. It handles input types
 * that match the Lite C format and  writes the data into
 * data types that match the IDL/C++ mapping as specified by the OMG.
 */

#include "idl_program.h"
#include "idl_scope.h"
#include "idl_genLiteISOCxxCopyout.h"
#include "idl_genISOCxx2Helper.h"
#include "idl_genLiteHelper.h"
#include "idl_genLanguageHelper.h"
#include "idl_tmplExp.h"
#include "idl_genSplHelper.h"
#include "idl_catsDef.h"
#include "idl_stacDef.h"
#include "idl_keyDef.h"

#include "c_typebase.h"
#include "os_heap.h"
#include "os_stdlib.h"
#include "os_abstract.h"

#include <stdio.h>

/** Text indentation level (4 spaces per indent) */
static c_long loopIndent;
/** Index for array loop variables, incremented for each array dimension */
static c_long varIndex;
/** Indicates if the generation of a type should be skipped until the following type */
static c_bool skip;
/** Preset discriminator assignment action */
static c_char set_discriminator[256];

static void
idl_arrayDimensions(
    idl_typeArray typeArray,
    os_boolean resolveTypedefs);

static void
idl_arrayElements(
    idl_typeArray typeArray,
    const char *from,
    const char *to,
    c_long indent);

static void
idl_seqLoopCopy(
    idl_typeSpec typeSpec,
    const char *from,
    const char *to,
    c_long loop_index,
    c_long indent);

/** @brief callback function called on opening the IDL input file.
 *
 * No code is generated
 *
 * @param scope Current scope (not used)
 * @param name Name of the IDL input file (not used)
 * @return Next action for this file (idl_explore)
 */
static idl_action
idl_fileOpen(
    idl_scope scope,
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    return idl_explore;
}

/** @brief callback function called on module definition in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
   =>   module <module-name> {
            <module-contents>
        };
   @endverbatim
 *
 * No action is required for IDL modules.
 *
 * @param scope Current scope (and scope of the module definition)
 * @param name Name of the defined module
 * @return Next action for this module (idl_explore)
 */
static idl_action
idl_moduleOpen(
    idl_scope scope,
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    return idl_explore;
}

/** @brief callback function called on structure definition in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
   =>   struct <structure-name> {
            <structure-member-1>;
            ...              ...
            <structure-member-n>;
        };
   @endverbatim
 *
 * For structures a copyOut routine named __<scope-elements>_<structure-name>__copyOut
 * will be prepared. The signature of this copyOut routine is:
 * @verbatim
    void copyOut (const void *_from, void *_to);
    @endverbatim
 *
 * The copyOut routine signature is generated based upon the input
 * parameters which specify the scope and it's name.
 * This routine generates local variables which match the type of the source
 * and destination:
 * @verbatim
   void
   copyOut (const void *_from, void *_to)
   {
       const struct _<scope-elements>_<structure-name> *from = (const _<scope-elements>_<structure-name> *)_from;
       <scope-elements>::<structure-name> *to = (<scope-elements>::<structure-name> *)to;
    @endverbatim
 *
 * @param scope Current scope (and scope of the structure definition)
 * @param name Name of the structure
 * @param structSpec Specification of the struct holding the amount of members (not used)
 * @return Next action for this struct (idl_explore)
 */
static idl_action
idl_structureOpen(
    idl_scope scope,
    const char *name,
    idl_typeStruct structSpec,
    void *userData)
{
    c_char *scopedCxxTypeName = idl_ISOCxx2TypeFromTypeSpec(idl_typeSpec(structSpec));
    c_char *scopedTypeName = idl_scopedTypeName(idl_typeSpec(structSpec));

    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    skip = FALSE;

    idl_fileOutPrintf(idl_fileCur(), "void\n__%s__copyOut(\n", scopedTypeName);
    idl_fileOutPrintf(idl_fileCur(), "    const void *_from,\n");
        idl_fileOutPrintf(idl_fileCur(), "    void *_to)\n");
    idl_fileOutPrintf(idl_fileCur(), "{\n");
    idl_fileOutPrintf(idl_fileCur(), "    %s *to = (%s *)_to;\n", scopedCxxTypeName, scopedCxxTypeName);
    idl_fileOutPrintf(idl_fileCur(), "    const %s *from = (const %s *)_from;\n\n", scopedTypeName, scopedTypeName);

    os_free(scopedTypeName);
    os_free(scopedCxxTypeName);

    return idl_explore;
}

/** @brief callback function called on end of a structure definition in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
        struct <structure-name> {
            <structure-member-1>
            ...              ...
            <structure-member-n>
   =>   };
   @endverbatim
 *
 * The function finalizes the copyOut routine for the structure by
 * generating the closing bracket ('}').
 *
 * @param name Name of the structure (not used)
 */
static void
idl_structureClose(
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(name);

    if (skip) {
        return;
    }

    idl_fileOutPrintf(idl_fileCur(), "}\n");
    idl_fileOutPrintf(idl_fileCur(), "\n");
}

/** @brief Generate copy statement for elements of basic type.
 *
 * The function generates for the provided basic type a copyOut
 * statement. The identification of the source and destination
 * elements must be provided by the caller.
 *
 * Note that structures can be reused when part of a sequence.
 *
 * Basic type elements, apart from string types, are assigned
 * immediately. Strings are duplicated calling DDS::string_dup.
 * DDS::string_dup will first free the string if a string was
 * already assigned and duplicate the string from the database.
 *
 * @param scope Scope of the element
 * @param name Name of the element
 * @param typeBasic Specification of the type of the element
 * @param from_id Identification of the source
 * @param Identification of the destination
 */
static void
idl_basicMemberType(
    idl_scope scope,
    const char *name,
    idl_typeBasic typeBasic,
    const char *from_id,
    const char *to_id,
    c_long indent)
{
    c_ulong maxlen;
    c_char *cxxIdName = idl_ISOCxx2Id(name);
    char* tmp_string = idl_scopedLiteTypeName(idl_typeSpec(typeBasic));

    OS_UNUSED_ARG(scope);

    switch (idl_typeBasicType(typeBasic)) {
    case idl_short:
    case idl_ushort:
    case idl_long:
    case idl_ulong:
    case idl_longlong:
    case idl_ulonglong:
    case idl_float:
    case idl_double:
    case idl_char:
    case idl_octet:
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "%s.%s() = (%s)%s%s;\n",
            to_id,
            cxxIdName,
            tmp_string,
            from_id,
            cxxIdName);
    break;
    case idl_boolean:
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "%s.%s() = (%s)(%s%s != 0);\n",
            to_id,
            cxxIdName,
            tmp_string,
            from_id,
            cxxIdName);
        break;
    case idl_string:
        maxlen = idl_typeBasicMaxlen(typeBasic);
        if (maxlen == 0) {
            idl_printIndent(indent);
            idl_fileOutPrintf (idl_fileCur(), "%s.%s() = %s%s ? %s%s : \"\";\n",
                    to_id,
                    cxxIdName,
                    from_id,
                    cxxIdName,
                    from_id,
                    cxxIdName);
        } else {
            idl_printIndent(indent);
            idl_fileOutPrintf (idl_fileCur(), "%s.%s() = %s%s;\n",
                    to_id,
                    cxxIdName,
                    from_id,
                    cxxIdName);
        }
    break;
    }
    os_free(cxxIdName);
    os_free(tmp_string);
}

/** @brief callback function called on definition of a structure member in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
        struct <structure-name> {
   =>       <structure-member-1>;
   =>       ...              ...
   =>       <structure-member-n>;
        };
   @endverbatim
 *
 * Depending on the type of the structure member, a copy strategy is used:
 * - If the type is \b idl_tbasic, \b idl_basicMemberType is called to generate the
 *   copy code.
 * - If the type is \b idl_typedef the copy strategy depends on the referred type.
 *   When this type is \b idl_tarray or \b idl_tseq a type specific copy routine
 *   is called. When type is something else, this routine is called recursively with
 *   with the referred type.
 * - If the type is \b idl_tenum, the element is immediately assigned.
 * - If the type is \b idl_tstruct or \b idl_tunion, the copyOut routine of that struct
 *   or union type is called.
 * - If the type is \b idl_tarray the array copy context is set and the service
 *   to copy arrays is called.
 * - If the type is \b idl_tseq, the sequence copy context is setup and the
 *   service to copy sequences is called.
 *
 * Note that structures can be reused when part of a sequence.
 * The managed sequence of CORBA/C++ is held responsible to correctly handle this.
 *
 * @param scope Current scope
 * @param name Name of the structure member
 * @param typeSpec Type specification of the structure member
 */
static void
idl_structureMemberOpenClose(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char dest[256];
    c_long indent = 1;
    char* tmp_string;
    c_char *cxxName = idl_ISOCxx2Id(name);

    if (skip) {
        return;
    }

    snprintf(dest, (size_t)sizeof(dest), "(*to)");

    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(typeSpec) == idl_tbasic) {
        idl_basicMemberType(scope, name, idl_typeBasic(typeSpec), "from->", dest, indent);
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_ttypedef) {
        /* QAC EXPECT 3416; No side effect here */
        IDL_PRINTLINE(indent);
        if ((idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec))) == idl_tstruct) ||
                (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec))) == idl_tunion) ||
                (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec))) == idl_tarray) ||
                (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec))) == idl_tseq)) {
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "{\n");
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    extern void __%s__copyOut(const void *, void *);\n",
                     idl_scopedTypeName(typeSpec));

            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    __%s__copyOut((const void *)&from->%s, (void *)&(%s).%s());\n",
                    idl_scopedTypeName(typeSpec),
                    cxxName,
                    dest,
                    cxxName);
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "}\n");
        } else {
            /* Calls itself for the actual type in case of typedef */
            idl_structureMemberOpenClose(
                    scope,
                    name,
                    idl_typeDefActual(idl_typeDef(typeSpec)),
                    userData);
        }
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tenum) {
        IDL_PRINTLINE(indent);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "%s.%s() = (%s)from->%s;\n",
            dest,
            cxxName,
            idl_ISOCxx2TypeFromTypeSpec(typeSpec),
            cxxName);
        /* QAC EXPECT 3416; No side effect here */
    } else if ((idl_typeSpecType(typeSpec) == idl_tstruct) ||
               (idl_typeSpecType(typeSpec) == idl_tunion)) {
        IDL_PRINTLINE(indent);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "{\n");
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    extern void __%s__copyOut(const void *, void *);\n",
            idl_scopedTypeName(typeSpec));
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    __%s__copyOut((const void *)&from->%s, (void *)&(%s).%s());\n",
            idl_scopedTypeName(typeSpec),
            cxxName,
            dest,
            cxxName);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "}\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tarray) {
            c_char destin[512];
            idl_typeSpec subType;

            subType = idl_typeArrayActual(idl_typeArray(typeSpec));
            snprintf(destin, (size_t)sizeof(destin), "%s.%s().data()", dest, name);
            tmp_string = idl_scopedLiteTypeName(subType);

            IDL_PRINTLINE(indent);
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "{\n");
            idl_printIndent(indent);
            if (idl_typeSpecType(subType) == idl_tseq) {
                c_char sname[32];
                snprintf(sname, (size_t) sizeof(sname), "_%s_seq", cxxName);
                idl_fileOutPrintf (idl_fileCur(), "    typedef %s _SrcType",
                        tmp_string);
//                idl_fileOutPrintf (idl_fileCur(), "    typedef %s _SrcType",
//                        idl_scopeStack(idl_typeUserScope(idl_typeUser(subType)), "::", sname));
            } else {
                idl_fileOutPrintf (idl_fileCur(), "    typedef %s _SrcType", tmp_string);
            }

            idl_arrayDimensions(idl_typeArray(typeSpec), OS_FALSE);
            idl_fileOutPrintf(idl_fileCur(), ";\n");
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    const _SrcType *src = &from->%s;\n\n", cxxName);
            idl_arrayElements(idl_typeArray(typeSpec), "src", destin, indent);
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "}\n");

            os_free(tmp_string);

        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tseq) {
        c_char *cxxTypeName, *scopedCxxTypeName;

        idl_typeSpec nextType = idl_typeSeqType(idl_typeSeq(typeSpec));

        tmp_string = idl_scopedLiteTypeName(nextType);
        os_asprintf(&cxxTypeName, "_%s_seq", name);
        scopedCxxTypeName = idl_scopeStack(idl_typeUserScope(idl_typeUser(typeSpec)), "::", cxxTypeName);

        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "{\n");
        IDL_PRINTLINE(indent);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    long size0;\n");
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    const %s **src = (const %s **)&((from->%s)._buffer);\n",
                tmp_string,
                tmp_string,
                cxxName);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    %s *dst = &(%s.%s());\n\n",
                scopedCxxTypeName,
                dest,
                cxxName);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    size0 = (long)(from->%s)._length;\n",
                cxxName);
        idl_seqLoopCopy(nextType, "src", "dst", 1, indent+1);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "}\n");

        os_free(scopedCxxTypeName);
        os_free(cxxTypeName);
        os_free(tmp_string);

    } else {
        /* Do nothing, only to prevent dangling else-ifs QAC reports */
    }
    os_free(cxxName);
}

/** @brief Generate the array dimensions.
 *
 * Generate the dimensions of the array:
 * @verbatim
   [<size-dimension-first>][<size-dimension-first+1>]..[<size-dimension-last>]
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 */
static void
idl_arrayDimensions(
    idl_typeArray typeArray,
    os_boolean resolveTypedefs)
{
    idl_typeSpec subType;

    idl_fileOutPrintf (idl_fileCur(), "[%d]", idl_typeArraySize(typeArray));
    subType = idl_typeArrayType(typeArray);
    while(resolveTypedefs && idl_typeSpecType(subType) == idl_ttypedef)
    {
        subType = idl_typeDefResolveFully(subType);
    }
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(subType) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayDimensions(idl_typeArray(subType), resolveTypedefs);
    }
}

/** @brief Generate the loop variables for the array copy.
 *
 * Generate the loop variables for the array copy. Per dimension a
 * loop variable named i# is required, where # represents the dimension.
 * (I.e. first dimension handled by i1, second by i2, etc.)
 * @verbatim
   int i1; // dimension-first
   int i2; // dimension-first+1
   ..
   int i#; // dimension-last
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param indent Indentation of the output
 */
static void
idl_arrayLoopVariables(
    idl_typeArray typeArray,
    c_long indent)
{
    loopIndent++;
    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "    int i%d;\n", loopIndent-1);
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayLoopVariables(idl_typeArray(idl_typeArrayType(typeArray)), indent);
    } else {
        idl_fileOutPrintf(idl_fileCur(), "\n");
    }
    loopIndent--;
}

/** @brief Generate copy loop for an array.
 *
 * Generate the for statement for copying an array.
 * The variable \b loopIndent indicates the actual loop variable for this dimension.
 * The variable indent indicates the positional index for the loop.
 * @verbatim
   for (i1 = 0; i1 < <size-dimension-first>; i1++) {
       for (i2 = 0; i2 < <size-dimension-first+1>; i2++) {
           ..
               for (i# = 0; i# < <size-dimension-last>; i#++) {
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param indent Indentation of the output
 */
static void
idl_arrayLoopCopyOpen(
    idl_typeArray typeArray,
    c_long indent)
{
    loopIndent++;
    idl_printIndent(loopIndent + indent);
    idl_fileOutPrintf(idl_fileCur(), "for (i%d = 0; (i%d < %d); i%d++) {\n",
        loopIndent-1,
        loopIndent-1,
        idl_typeArraySize(typeArray),
        loopIndent-1);
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayLoopCopyOpen(idl_typeArray(idl_typeArrayType(typeArray)), indent);
    }
}

/** @brief Generate array index for copying array elements.
 *
 * Generate array index to the default output file.
 *
 * @verbatim
    [i1][i2]..[i#]
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 */
static void
idl_arrayLoopCopyIndex(
    idl_typeArray typeArray)
{
    varIndex++;
    idl_fileOutPrintf(idl_fileCur(), "[i%d]", varIndex-1);
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayLoopCopyIndex(idl_typeArray(idl_typeArrayType(typeArray)));
    }
    varIndex--;
}

/** @brief Generate array index for copying array elements.
 *
 * Generate array index to string.
 *
 * @verbatim
    [i1][i2]..[i#]
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 */
static void
idl_arrayLoopCopyIndexString(
    char *indexString,
    idl_typeArray typeArray)
{
    c_char arrIndex[16];

    varIndex++;
    snprintf(arrIndex, (size_t)sizeof(arrIndex), "[i%d]", varIndex-1);
    os_strncat(indexString, arrIndex, (size_t)sizeof(arrIndex));
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayLoopCopyIndexString(indexString, idl_typeArray(idl_typeArrayType(typeArray)));
    }
    varIndex--;
}

/** @brief Determine the number of dimensions of the identified array
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @return The number of dimensions of the array
 */
static c_long
idl_indexSize(
    idl_typeArray typeArray)
{
    c_long return_val = 1;

    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        return_val = idl_indexSize(idl_typeArray(idl_typeArrayType(typeArray)))+1;
    }
    return return_val;
}

/** @brief Generate copy body for an array element.
 *
 * Generate the body for copying an array element.
 *
 * Depending on the actual type of the array, one of the following strategies will
 * be followed.
 * - If the actual type is \b idl_tstruct or \b idl_tunion call the copy routine
 *   for the struct or union.
 * - If the actual type is \b idl_ttypedef depending on the actual type of the typedef,
 *   for \b idl_tstruct, \b idl_tunion, \b idl_tarray and \b idl_tseq call the copy
 *   routine for the type. If the actual type is \b idl_tbasic (only if it is a string),
 *   the string is duplicated.
 * - If the actual type is \b idl_tbasic (only a string is expected) a loop
 *   to copy the strings is created.
 * - If the actual type is \b idl_tseq (only a string is expected) a loop
 *   to copy the sequence is created.
 *
 * Because the array is member of a structure or union case of a union, reuse
 * of the array is possible and replacement of strings and sequence buffers
 * must be supported.
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param from Identification of the source to copy from
 * @param to Identification of the destination to copy to
 * @param indent Indentation of the output
 */
static void
idl_arrayLoopCopyBody(
    idl_typeArray typeArray,
    idl_typeSpec typeSpec,
    const char *from,
    const char *to,
    c_long indent)
{
    idl_typeSpec nextType;
    c_char source[256];
    c_char destin[256];
    c_long total_indent;

    char* tmp_string = 0;

    loopIndent++;
    switch (idl_typeSpecType(typeSpec)) {
    case idl_tstruct:
    case idl_tunion:
        IDL_PRINTLINE (indent);
        idl_printIndent(loopIndent + indent);
        varIndex = 0;
        idl_fileOutPrintf(idl_fileCur(), "extern void __%s__copyOut(const void *, void *);\n",
            idl_scopedTypeName(typeSpec));
        idl_printIndent(loopIndent + indent);
        idl_fileOutPrintf(idl_fileCur(), "__%s__copyOut((const void *)&(*%s)",
            idl_scopedTypeName(typeSpec),
            from);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf(idl_fileCur(), ", (void *)&(%s)", to);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf(idl_fileCur(), ");\n");
    break;
    case idl_ttypedef:
        IDL_PRINTLINE (loopIndent + indent);
        idl_printIndent(loopIndent + indent);
        switch (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec)))) {
            case idl_tstruct:
            case idl_tunion:
            case idl_tarray:
            case idl_tseq:
                idl_fileOutPrintf(idl_fileCur(), "extern void __%s__copyOut(const void *, void *);\n",
                        idl_scopedTypeName(typeSpec));
                idl_printIndent(loopIndent + indent);
                idl_fileOutPrintf(idl_fileCur(), "__%s__copyOut((const void *)&(*%s)",
                        idl_scopedTypeName(typeSpec), from);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf(idl_fileCur(), ", (void *)&(%s)", to);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf(idl_fileCur(), ");\n");
            break;
            case idl_tbasic:
                /* QAC EXPECT 3416; No side effect here */
                if (idl_typeBasicType(idl_typeBasic(idl_typeDefActual(idl_typeDef(typeSpec)))) == idl_string) {
                    idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), " = ((%s", from);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), ") ? ");
                    idl_fileOutPrintf(idl_fileCur(), "((%s)", from);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), ") : \"\");\n");
                } else {
                    /* Only alternative non-contiguous primitive type is boolean. */
                    assert(idl_typeBasicType(idl_typeBasic(idl_typeDefActual(idl_typeDef(typeSpec)))) == idl_boolean);
                    idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), " = (bool) (%s", from);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), ");\n");
                }
            break;
            case idl_tenum:
                idl_fileOutPrintf(idl_fileCur(), "%s = %s;\n", to, from);
            break;
            default:
                printf("idl_arrayLoopCopyBody: Unexpected type\n");
                assert(0);
            break;
        }
    break;
    case idl_tbasic:
        IDL_PRINTLINE (loopIndent + indent);
        idl_printIndent(loopIndent + indent);
        /* This may only be string */
        /* QAC EXPECT 3416; No side effect here */
        if (idl_typeBasicType(idl_typeBasic(typeSpec)) == idl_string) {
            idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), " = ((*%s)", from);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), " ? ");
            idl_fileOutPrintf(idl_fileCur(), "((*%s)", from);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), ") : \"\");\n");
        } else {
            /* Only alternative non-contiguous primitive type is boolean. */
            assert(idl_typeBasicType(idl_typeBasic(typeSpec)) == idl_boolean);
            idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), " = (bool) (%s", from);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), ");\n");
        }
    break;
    case idl_tseq:
        total_indent = indent + idl_indexSize(typeArray);
        IDL_PRINTLINE(total_indent);
        nextType = idl_typeSeqType(idl_typeSeq(typeSpec));
        snprintf(destin, (size_t)sizeof(destin), "(%s)", to);
        idl_arrayLoopCopyIndexString(destin, typeArray);
        idl_printIndent(total_indent);
        idl_fileOutPrintf(idl_fileCur(), "    size_t size0;\n");
        idl_printIndent(total_indent);
        snprintf(source, (size_t)sizeof(source), "&(%s)", from);
        idl_arrayLoopCopyIndexString(source, typeArray);
        tmp_string = idl_scopedLiteTypeName(typeSpec);
        idl_fileOutPrintf(idl_fileCur(), "    %s *src0 = (%s *)%s;\n\n",
                tmp_string,
                tmp_string,
                source);
        os_free(tmp_string);
        idl_printIndent(total_indent);
        idl_fileOutPrintf(idl_fileCur(),"    size0 = (*src0)._length;\n");

        total_indent++;
        idl_printIndent(total_indent);
        idl_fileOutPrintf(idl_fileCur(), "{\n");
        idl_printIndent(total_indent);
        tmp_string = idl_scopedLiteTypeName(nextType);
        idl_fileOutPrintf(idl_fileCur(), "    const %s **src1 = (const %s **)&(*src0)._buffer;\n",
                tmp_string,
                tmp_string);
        os_free(tmp_string);
        idl_printIndent(total_indent);
        idl_fileOutPrintf(idl_fileCur(), "\n");

        idl_seqLoopCopy(nextType, "src1", destin, 1, total_indent+1);
        idl_printIndent(total_indent);
        idl_fileOutPrintf(idl_fileCur(), "}\n");
        total_indent--;
    break;
    default:
        assert (0);
    break;
    }
    loopIndent--;
}

/** @brief Generate array loop copy closing code.
 *
 * For each dimension a closing bracket '}' will be generated at the
 * correct indent level.
 *
 * @verbatim
               }
           ..
       }
   }
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param indent Indentation of the loop.
 */
static void
idl_arrayLoopCopyClose(
    idl_typeArray typeArray,
    c_long indent)
{
    idl_printIndent(loopIndent + indent);
    loopIndent--;
    idl_fileOutPrintf(idl_fileCur(), "}\n");
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayLoopCopyClose(idl_typeArray(idl_typeArrayType(typeArray)), indent);
    }
}

/** @brief Generate copy loops for array.
 *
 * For each all array dimensions generate a loop copy action.
 * An array copy action is construct of:
 * - a loop variable (idl_arrayLoopVariables)
 * - a loop statement (idl_arrayLoopCopyOpen)
 * - copying the array element (idl_arrayLoopCopyBody)
 * - closing the loop statement (idl_arrayLoopCopyClose)
 *
 * This results in the following pattern for copying arrays per element:
 * @verbatim
   int i1;
   int i2;
   ..
   int i#;

   for (i1 = 0; i1 < <size-dimension-first>; i1++) {
       for (i2 = 0; i2 < <size-dimension-first+1>; i2++) {
           ..
               for (i# = 0; i# < <size-dimension-last>; i#++) {
                    // copy array element
                     &to[i1][i2]..[i#] = DDS::string_dup (from[i1][i2]..[i#]) // for string
                    __<type>__copyOut (&from[i1][i2]..[i#], &to[i1][i2]..[i#]) // for struct, union
                    .. // for sequence, see sequence copy construction
               }
           }
       ..
   }
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param from Identification of the source to copy from
 * @param to Identification of the destination to copy to
 * @param indent Indentation of the output
 */
static void
idl_arrayLoopCopy(
    idl_typeArray typeArray,
    const char *from,
    const char *to,
    c_long indent)
{
    loopIndent = 0;
    idl_arrayLoopVariables(typeArray, indent);
    idl_arrayLoopCopyOpen(typeArray, indent);
    idl_arrayLoopCopyBody(typeArray, idl_typeArrayActual(typeArray), from, to, indent);
    idl_arrayLoopCopyClose(typeArray, indent);
}

/** @brief Generate code for copying an array.
 *
 * This function is the top level function for copying an array type.
 * This function determines the strategy to use, copying by plain
 * memory copy (for plain types), or copying element for element (for
 * types that contain references).
 *
 * The copy strategy depends on the actual type of the array:
 * - If the actual type is \b idl_tbasic, the depending if it is a
 *   string or another basic type, an element copy or a plain memory copy
 *   is used respectively.
 * - If the actual type is \b idl_tenum, a plain memory copy is used.
 * - If the actual type is \b idl_tstruct or \b idl_tunion, an element
 *   copy is used.
 * - If the actual type is \b idl_ttypedef, the strategy depends on the
 *   actual type of the typedef.
 * - If the actual type is \b idl_tseq, the array will be copied on
 *   element basis.
 *
 * @todo When the struct (not a union) does not contain a reference or union,
 * a plain memory copy could be used because the memory map is the same in CORBA
 * and OpenSpliceDDS
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param from Identification of the source to copy from
 * @param to Identification of the destination to copy to
 * @param indent Indentation of the output
 */
static void
idl_arrayElements(
    idl_typeArray typeArray,
    const char *from,
    const char *to,
    c_long indent)
{
    char *buf;
    char *cpyToTmp = NULL;
    const char *cpyTo;
    idl_typeSpec subType;
    idl_type idlType;

    cpyTo = to;

    subType = idl_typeArrayActual(typeArray);
    idlType = idl_typeSpecType(subType);
    /* if we are dealing with a member for which stac or cats was requested
     * and of which the type is a typedef, then we must bypass this typedef
     * completely and get to the actual type of the typedef
     */

    switch (idlType) {
    case idl_tbasic:
        /* QAC EXPECT 3416; No side effect here */
        IDL_PRINTLINE(indent);
        if (idl_isContiguous(idl_typeSpecDef(subType))) {
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    memcpy ((void*)%s, (void*)%s, sizeof (*%s));\n", cpyTo, from, from);
        } else {
            loopIndent = 0;
            idl_arrayLoopCopy(typeArray, from, to, indent);
        }
    break;
    case idl_tenum:
        IDL_PRINTLINE(indent);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    memcpy ((void*)%s, (void*)%s, sizeof (*%s));\n", cpyTo, from, from);
    break;
    case idl_tstruct:
    case idl_tunion:
        IDL_PRINTLINE(indent);
        loopIndent = 0;
        idl_arrayLoopCopy(typeArray, from, to, indent);
    break;
    case idl_ttypedef:
        /* QAC EXPECT 3416; No side effect here */
        IDL_PRINTLINE(indent);
        if (idl_typeSpecType(idl_typeDefActual(idl_typeDef(subType))) == idl_tbasic) {
            /* QAC EXPECT 3416; No side effect here */
            if (idl_typeBasicType(idl_typeBasic(idl_typeDefActual(idl_typeDef(subType)))) == idl_string) {
                loopIndent = 0;
                buf = os_malloc(strlen(from)+4);
                os_sprintf(buf, "(*%s)", from);
                idl_arrayLoopCopy(typeArray, buf, to, indent);
                os_free(buf);
            } else {
                idl_printIndent(indent);
                idl_fileOutPrintf(idl_fileCur(), "    memcpy ((void*)%s, (void*)%s, sizeof (%s));\n", cpyTo, from, cpyTo);
            }
            /* QAC EXPECT 3416; No side effect here */
        } else if (idl_typeSpecType(idl_typeDefActual(idl_typeDef(subType))) == idl_tenum) {
            idl_printIndent(indent);
            /** @internal
             * @bug I think the below is actually an SACPP bug. If so: it well demonstrates
             * the perils of cut & paste. This is not what I'm here for though. */
            idl_fileOutPrintf(idl_fileCur(), "    memcpy ((void*)%s, (void*)%s, sizeof (%s));\n", cpyTo, from, cpyTo);
        } else {
            loopIndent = 0;
            idl_arrayLoopCopy(typeArray, from, to, indent);
        }
    break;
    case idl_tseq:
        IDL_PRINTLINE(indent);
        idl_arrayLoopCopy(typeArray, from, to, indent);
    break;
    case idl_tarray:
        printf("idl_arrayElements: Unexpected type idl_tarray\n");
    break;
    }
    os_free(cpyToTmp);
}

/** @brief Function that generates index for addressing sequence elements.
 *
 * Generate code for addressing sequenece elements by means of the index
 * variables i0 .. in.
 *
 * The index is organized as follows:
 * @verbatim
   [i0][i1]..[in]
   @endverbatim
 *
 * @param indent Sequence recursion level
 * @return image addressing the current sequence element
 */
static char *
idl_seqIndex(
    c_long indent)
{
    c_char index[64];
    c_char is[64];
    c_long i;

    os_strncpy(index, "", (size_t)sizeof(index));
    for (i = 0; i < indent; i++) {
        snprintf(is, (size_t)sizeof(is), "[j%d]", i);
        /* Remaining size is (total size) - (current string size) - (sizeof('\0')). */
        os_strncat(index, is, (size_t)((sizeof(index) - strlen(index)) - 1));
    }
    return os_strdup(index);
}


/** @brief Function that generates code for copying sequences.
 *
 * Generate code for copying sequence types.
 *
 * The general pattern for copying sequences is as follows:
 * @verbatim
   unsigned int i0;
   long size0;
   <scoped-sequence-type-name> *src0 = (<scoped-sequence-type-name> *)<source-id>;

   size0 = (*src0)._length;
   (<destination-id>).length (size0);
   // Body to copy sequence contents from *src to <destination-id>
   @endverbatim
 *
 * Note that in C++ nested sequences are always anonymous. Thus sequence copy routines in C++
 * do need to nest the copy actions (in contrast with C).
 * The variable names used "i0", "size0", and "src0" within the nested
 * copy operations will have an increased index.
 *
 * This routine only generates the copying code for copying the sequence contents.
 * The context around it as depicted above is expected to be generated by the
 * calling function.
 * Motivation for this is that are many variations on the pattern depending on
 * the situation, for instance if it is an array of an sequence, an array copy loop
 * must be coded around it.
 *
 * The body to copy the sequence depends on the actual type of the sequence, however
 * the framework for copying is always the same:
 * @verbatim
   for (i0 = 0; i0 < (long)size0; i0++) {
       // Copy sequence element (type specific)
   }
   @endverbatim
 *
 * The element copyOut strategy is as follows:
 * - If the sequence element type is \b idl_tenum, direct assignment is used
 * - If the sequence element type is \b idl_tbasic, depending on whether it is
 *   a string or not, elements are duplicated via c_newString or otherwise
 *   immediately assigned
 * - If the sequence element type is \b idl_tstruct or \b idl_tunion the copyOut
 *   function for that struct or union is called.
 * - If the sequence element type is \b idl_ttypedef the strategy depends on the
 *   actual type of the typedef. For structs unions and arrays the copyOut routine
 *   for that type is called. For basic string type, the string is duplicated
 *   via c_stringNew. For other basic types and enumeration it is just assigned.
 * - If the sequence element type is \b idl_tseq, a new sequence copy operation
 *   is setup for the specific sequence type.
 *
 * Because the sequence can be member of a structure or union case of a union, reuse
 * of the sequence is possible and replacement of strings and sequence buffers
 * must be supported.
 *
 * Structure types (not unions) that do not contain any reference types (or unions)
 * are copied via a plain memory copy because the sequence elements are
 * located in consecutive memory with the same memory map for C++ CORBA and Lite.
 * These cases are identified by idl_isContiguous()
 *
 * @param typeSpec The specification of the actual type of the sequence
 * @param from Specifies the identification of the source
 * @param to Specifies the identification of the destination
 * @param loop_index Specifies the index if the variables when sequence copy
 * routines are nested. The top level sequence starts with index 0.
 * @param indent Specifies the indentation level
 */
static void
idl_seqLoopCopy(
    idl_typeSpec typeSpec,
    const char *from,
    const char *to,
    c_long loop_index,
    c_long indent)
{
    c_char source[32];
    idl_typeSpec nextType;
    char* tmp_string = 0;
    char* tmp_string2 = idl_scopedLiteTypeName(typeSpec);

   if (idl_isContiguous(idl_typeSpecDef(typeSpec))) {
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "(*%s).reserve(size%d);\n", to, loop_index-1);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "{\n");
        idl_printIndent(indent);

        idl_fileOutPrintf(idl_fileCur(), "    std::vector< %s>* cv = reinterpret_cast< std::vector< %s>* >(%s);\n",
                tmp_string2,
                tmp_string2,
                to);

        idl_printIndent(indent);

        idl_fileOutPrintf(idl_fileCur(), "    cv->insert(cv->end(), *%s, (*%s) + size%d);\n",
                from,
                from,
                loop_index-1);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "}\n");
        os_free (tmp_string2);
        return;
    }

    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "(*%s).resize(size%d);\n", to, loop_index-1);
    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "{\n");
    IDL_PRINTLINE(indent);
    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "    uint32_t j%d;\n", loop_index-1);

    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "    for (j%d = 0; j%d < size%d; j%d++) {\n",
        loop_index-1,
        loop_index-1,
        loop_index-1,
        loop_index-1);

    switch (idl_typeSpecType(typeSpec)) {
    case idl_tenum:
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "        (%s)%s = (%s)%s[j%d];\n",
            to,
            idl_seqIndex(loop_index),
            idl_scopedLiteTypeName(typeSpec),
            from,
            loop_index-1);
    break;
    case idl_tbasic:
        indent++;
        IDL_PRINTLINE(indent);
        idl_printIndent(indent);
        /* QAC EXPECT 3416; No side effect here */
        if (idl_typeBasicType(idl_typeBasic(typeSpec)) == idl_string) {
            idl_fileOutPrintf(idl_fileCur(), "    (*%s)[j%d] = (*%s)[j%d] ? (*%s)[j%d] : \"\";\n",
                    to, loop_index-1, from, loop_index-1, from, loop_index-1);
        } else {
            idl_fileOutPrintf(idl_fileCur(), "    (*%s)[j%d] = (%s)(*%s)[j%d];\n",
                    to,
                    loop_index-1,
                    tmp_string2,
                    from,
                    loop_index-1);
        }
        indent--;
    break;
    case idl_tstruct:
    case idl_tunion:
        indent++;
        IDL_PRINTLINE(indent);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    extern void __%s__copyOut(const void *from, void *to);\n",
            idl_scopedTypeName(typeSpec));
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    __%s__copyOut((const void *)&(*%s)[j%d], (void *)&(*%s)%s);\n",
            idl_scopedTypeName(typeSpec),
            from,
            loop_index-1,
            to,
            idl_seqIndex(loop_index));
        indent--;
    break;
    case idl_ttypedef:
        switch (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec)))) {
        case idl_tstruct:
        case idl_tunion:
        case idl_tarray:
            indent++;
            IDL_PRINTLINE(indent);
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    extern void __%s__copyOut(const void *, void *);\n",
                idl_scopedTypeName(typeSpec));
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    __%s__copyOut((const void *)&((*%s)[j%d]), (void *)&(%s)%s);\n",
                idl_scopedTypeName(typeSpec),
                from,
                loop_index-1,
                to,
                idl_seqIndex(loop_index));
            indent--;
        break;
        case idl_tbasic:
            /* QAC EXPECT 3416; No side effect here */
            if (idl_typeBasicType(idl_typeBasic(idl_typeDefActual(idl_typeDef(typeSpec)))) == idl_string) {
                IDL_PRINTLINE(indent);
                idl_printIndent(indent);
                idl_fileOutPrintf(idl_fileCur(), "    (*%s)%s = (*%s)[j%d] ? (*%s)[j%d] : \"\";\n",
                    to,
                    idl_seqIndex(loop_index),
                    from,
                    loop_index-1,
                    from,
                    loop_index-1);
            } else {
                IDL_PRINTLINE(indent);
                idl_printIndent(indent);
                idl_fileOutPrintf(idl_fileCur(), "    (%s)%s = (%s)(*%s)[j%d];\n",
                    to,
                    idl_seqIndex(loop_index),
                    tmp_string2,
                    from,
                    loop_index-1);
            }
        break;
        case idl_tenum:
            IDL_PRINTLINE(indent);
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    (%s)%s = (%s)(*%s)[j%d];\n",
                to,
                idl_seqIndex(loop_index),
                idl_scopedLiteTypeName(typeSpec),
                from,
                loop_index-1);
        break;
        case idl_tseq:
            indent++;
            IDL_PRINTLINE(indent);
            idl_printIndent(indent);
            nextType = idl_typeSeqType(idl_typeSeq(idl_typeDefActual(idl_typeDef(typeSpec))));
            tmp_string = idl_scopedLiteTypeName(nextType);
            idl_fileOutPrintf(idl_fileCur(), "    uint32_t size%d;\n", loop_index);
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    %s **buf%d = (%s **)&(*%s)%s._buffer;\n",
                tmp_string,
                loop_index,
                tmp_string,
                from,
                idl_seqIndex(loop_index));
            idl_fileOutPrintf(idl_fileCur(), "\n");
            idl_printIndent(indent);
            idl_fileOutPrintf(idl_fileCur(), "    size%d = (*%s)%s._length;\n",
                loop_index,
                from,
                idl_seqIndex(loop_index));
            snprintf(source, (size_t)sizeof(source), "buf%d", loop_index);
            idl_seqLoopCopy(nextType, source, to, loop_index+1, indent+1);
            indent--;
        break;
        default:
            printf("idl_arrayLoopCopyBody: Unexpected type\n");
            assert(0);
        }
    break;
    case idl_tseq:
        indent++;
        IDL_PRINTLINE(indent);
        nextType = idl_typeSeqType(idl_typeSeq(typeSpec));
        tmp_string = idl_scopedLiteTypeName(nextType);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    uint32_t size%d;\n", loop_index);
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    %s **buf%d = (%s **)&(*%s)[j%d]._buffer;\n",
            tmp_string,
            loop_index-1,
            tmp_string,
            from,
            loop_index-1);
        idl_fileOutPrintf(idl_fileCur(), "\n");
        idl_printIndent(indent);
        idl_fileOutPrintf(idl_fileCur(), "    size%d = (*%s)[j%d]._length;\n",
            loop_index,
            from,
            loop_index-1);

        snprintf(source, (size_t)sizeof(source), "buf%d", loop_index-1);
        idl_seqLoopCopy(nextType, source, to, loop_index+1, indent+1);
        indent--;
    break;
    default:
        assert (0);
    break;
    }
    if(tmp_string)
        os_free(tmp_string);
    os_free(tmp_string2);
    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "    }\n");

    idl_printIndent(indent);
    idl_fileOutPrintf(idl_fileCur(), "}\n");
    /* QAC EXPECT 5101, 5103: Complexity is limited, by independent cases, per case the number of lines is lower  */
}

/** @brief Function that set up the sequence copy context for a typedef.
 *
 * Generate code to setup the sequence copy context for a typedef.
 *
 * Because the sequence can be member of a structure or union case of a union, reuse
 * of the sequence is possible and replacement of strings and sequence buffers
 * must be supported.
 *
 * @todo Because it is only used by a typedef it would be more clear
 * to integrate it with the typedef. If it can be used for more contexts
 * the others should be removed and call this function.
 *
 * @param scope Current scope
 * @param name Specifies the name of the type
 * @param typeSeq Specifies the type of the sequence
 * @param indent Sequence recursion level
 */
static void
idl_seqElements(
    idl_scope scope,
    const char *name,
    idl_typeSeq typeSeq,
    c_long indent)
{
    char* tmp_string;
    idl_typeSpec typeSpec = idl_typeSeqType(typeSeq);
    idl_typeSpec nextType = idl_typeSeqType(typeSeq);
    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);

    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);

    IDL_PRINTLINE(indent);
    idl_fileOutPrintf(idl_fileCur(), "    long size0;\n");
    tmp_string = idl_scopedLiteTypeName(typeSpec);
    idl_fileOutPrintf(idl_fileCur(), "    const %s **src = (const %s **)&(from->_buffer);\n",
        tmp_string,
        tmp_string);
    os_free(tmp_string);
    idl_fileOutPrintf(idl_fileCur(), "\n");
    idl_fileOutPrintf(idl_fileCur(), "    size%d = from->_length;\n", indent);

    idl_seqLoopCopy(nextType, "src", "to", 1, indent+1);
}



/** @brief callback function called on definition of a named type in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
   =>   typedef <type-name> <name>;
   @endverbatim
 *
 * For typedef's the action to copy the data is dependent on the actual type.
 * - If the actual type is \b idl_tstruct or \b idl_tunion, a named copy routines
 *   is generated. The copyOut routines calls the copyOut routine of the struct or union.
 * - If the actual type is \b idl_tarray, a named copyOut routine is generated.
 *   For that copyOut routine, array copy code is generated.
 * - If the actual type is \b idl_tseq, a named copyOut routine is generated.
 *   For that copyOut routine, sequence copy code is generated.
 *
 * Type definitions of basic type are immediately copied from within the generated
 * struct or union copyOut routine. No named copy routine is required.
 *
 * @param scope Current scope
 * @param name Specifies the name of the type
 * @param defSpec Specifies the type of the named type
 */
static void
idl_typedefOpenClose(
    idl_scope scope,
    const char *name,
    idl_typeDef defSpec,
    void *userData)
{
    c_char *scopedTypeName = idl_scopedTypeName(idl_typeSpec(defSpec));
    idl_typeSpec targetType = idl_typeDefActual(defSpec);
    c_char *scopedCxxTargetName = idl_ISOCxx2TypeFromTypeSpec(targetType);
    c_char *scopedTargetName = idl_scopedTypeName(targetType);

    switch (idl_typeSpecType(idl_typeDefActual(defSpec))) {
    case idl_tstruct:
    case idl_tunion:
        idl_fileOutPrintf(idl_fileCur(), "void\n");
        idl_fileOutPrintf(idl_fileCur(), "__%s__copyOut(\n", scopedTypeName);
         idl_fileOutPrintf(idl_fileCur(), "    const void *_from,\n");
         idl_fileOutPrintf(idl_fileCur(), "    void *_to)\n");
         idl_fileOutPrintf(idl_fileCur(), "{\n");
         idl_fileOutPrintf (idl_fileCur(), "    extern void __%s__copyOut(const void *, void *);\n", scopedTargetName);
         idl_fileOutPrintf(idl_fileCur(), "    __%s__copyOut(_from, _to);\n", scopedTargetName);

        idl_fileOutPrintf(idl_fileCur(), "}\n");
        idl_fileOutPrintf(idl_fileCur(), "\n");
    break;
    case idl_tarray:
        idl_fileOutPrintf(idl_fileCur(), "void\n");
        idl_fileOutPrintf(idl_fileCur(), "__%s__copyOut(\n", scopedTypeName);
        idl_fileOutPrintf(idl_fileCur(), "    const void *_from,\n");
        idl_fileOutPrintf(idl_fileCur(), "    void *_to)\n");
        idl_fileOutPrintf(idl_fileCur(), "{\n");
        idl_fileOutPrintf(idl_fileCur(), "    const %s *from = (const %s *)_from;\n", scopedTypeName, scopedTypeName);
        idl_fileOutPrintf(idl_fileCur(), "    %s *to = (%s *)_to;\n", scopedCxxTargetName, scopedCxxTargetName);
        idl_arrayElements(idl_typeArray(idl_typeDefActual(defSpec)), "from", "to->data()", 0);
        idl_fileOutPrintf(idl_fileCur(), "}\n");
        idl_fileOutPrintf(idl_fileCur(), "\n");
    break;
    case idl_tseq:
        idl_fileOutPrintf(idl_fileCur(), "void\n");
        idl_fileOutPrintf(idl_fileCur(), "__%s__copyOut(\n", scopedTypeName);
        idl_fileOutPrintf(idl_fileCur(), "    const void *_from,\n");
        idl_fileOutPrintf(idl_fileCur(), "    void *_to)\n");
        idl_fileOutPrintf(idl_fileCur(), "{\n");
        idl_fileOutPrintf(idl_fileCur(), "    const %s *from = (const %s *)_from;\n", scopedTypeName, scopedTypeName);
        idl_fileOutPrintf(idl_fileCur(), "    %s *to = (%s *)_to;\n", scopedCxxTargetName, scopedCxxTargetName);
        idl_seqElements(scope, name, idl_typeSeq(idl_typeDefActual(defSpec)), 0);
        idl_fileOutPrintf(idl_fileCur(), "}\n");
        idl_fileOutPrintf(idl_fileCur(), "\n");
    break;
    default:
    break;
    }
    os_free(scopedTargetName);
    os_free(scopedCxxTargetName);
    os_free(scopedTypeName);

}

/** @brief callback function called on definition of a union in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
   =>   union <union-name> switch(<switch-type>) {
            case label1.1; .. case label1.n;
                <union-case-1>;
            case label2.1; .. case label2.n;
                ...        ...
            case labeln.1; .. case labeln.n;
                <union-case-n>;
            default:
                <union-case-m>;
        };
   @endverbatim
 *
 * For unions a copyOut routine named __<scope-elements>_<union-name>__copyOut
 * will be prepared. The signature of this copyOut routine is:
 * @verbatim
   void copyOut (const void *_from, void *_to);
   @endverbatim
 *
 * The copyOut routine signature is generated based upon the input
 * parameters which specify the scope and it's name.
 *
 * Note that unions can be reused when part of a sequence.
 * The managed sequence and managed union in CORBA C++ are held responsible for managing this.
 *
 * The copyOut routine will first copy the source and destination addresses
 * to type specific variables. Then the routine will preset a discriminant copy action
 * from the source to the target union.
 * The diferent variant of the union are handled by an switch statement
 * that is generated by this function.
 * @verbatim
   struct _<scope-elements>_<union-name> *from = (struct _<scope-elements>_<union-name> *)_from;
   <scope-elements>::<union-name> *to = (<scope-elements>::<union-name> *)_to;

   void <scope-elements>_<union-name>__free (void *object);

   if (from->_d != to->_d) {
       <scope-elements>_<union-name>__free (_to);
       memset (to, 0, sizeof (<scope-elements>_<union-name>));
   }
   switch (to->_d) {
   case <x1>:                   // handled by idl_unionLabelOpenClose
        // copy union case      // handled by idl_unionCaseOpenClose
        break;                  // handled by idl_unionCaseOpenClose
   case <xn>:                   // handled by idl_unionLabelOpenClose
        // copy union case      // handled by idl_unionCaseOpenClose
        break;                  // handled by idl_unionCaseOpenClose
   default:                     // handled by idl_unionLabelOpenClose
        // copy union case      // handled by idl_unionCaseOpenClose
        break;                  // handled by idl_unionCaseOpenClose
   }                            // handled by idl_unionClose
   @endverbatim
 *
 * @param scope Current scope
 * @param name Name of the union
 * @param unionSpec Specifies the number of union cases and the union switch type
 * @return Next action for this union (idl_explore)
 */
static idl_action
idl_unionOpen(
    idl_scope scope,
    const char *name,
    idl_typeUnion unionSpec,
    void *userData)
{
    c_char *scopedName = idl_scopedTypeName(idl_typeSpec(unionSpec));
    c_char *scopedNameCxx = idl_ISOCxx2TypeFromTypeSpec(idl_typeSpec(unionSpec));
    c_char *cxxSwitchTypeName = idl_ISOCxx2TypeFromTypeSpec(idl_typeUnionSwitchKind(unionSpec));

    OS_UNUSED_ARG(userData);

    idl_fileOutPrintf(idl_fileCur(), "void\n");
    idl_fileOutPrintf(idl_fileCur(), "__%s__copyOut(\n", scopedName);
    idl_fileOutPrintf(idl_fileCur(), "    const void *_from,\n");
    idl_fileOutPrintf(idl_fileCur(), "    void *_to)\n");
    idl_fileOutPrintf(idl_fileCur(), "{\n");
    idl_fileOutPrintf(idl_fileCur(), "    const struct %s *from = (const struct %s *)_from;\n", scopedName, scopedName);
    idl_fileOutPrintf(idl_fileCur(), "    %s *to = (%s *)_to;\n", scopedNameCxx, scopedNameCxx);
    /* prepare assignment of discriminant used within unionClose */
    if (  ((idl_typeSpecType(idl_typeUnionSwitchKind(unionSpec)) == idl_tbasic) &&
              (idl_typeBasicType(idl_typeBasic(idl_typeUnionSwitchKind(unionSpec))) == idl_boolean))
       || ((idl_typeSpecType(idl_typeUnionSwitchKind(unionSpec)) == idl_ttypedef) &&
              (idl_typeBasicType(idl_typeBasic(idl_typeDefActual(idl_typeDef(idl_typeUnionSwitchKind(unionSpec))))) == idl_boolean)) )
    {
      /* prevent MSVC warning going from C 'bool' to bool */
        snprintf(set_discriminator, sizeof(set_discriminator), "to->_d((%s)(from->_d != 0));", cxxSwitchTypeName);
    }
    else
    {
      /* otherwise always this */
        snprintf(set_discriminator, sizeof(set_discriminator), "to->_d((%s)from->_d);", cxxSwitchTypeName);
    }
    idl_fileOutPrintf(idl_fileCur(), "    switch (from->_d) {\n");
    os_free(cxxSwitchTypeName);
    os_free(scopedNameCxx);
    os_free(scopedName);
    return idl_explore;
}

/** @brief callback function called on closure of a union in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
        union <union-name> switch(<switch-type>) {
            case label1.1; .. case label1.n;
                <union-case-1>;
            case label2.1; .. case label2.n;
                ...        ...
            case labeln.1; .. case labeln.n;
                <union-case-n>;
            default:
                <union-case-m>;
   =>   };
   @endverbatim
 *
 * The function finalizes the copyOut routine for the union.
 * The preset discriminant copy action will be written as well
 * as closeing brackets ('}') for the switch statement
 * and the copy function itself.
 *
 * @param name Name of the union
 */
static void
idl_unionClose (
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    idl_fileOutPrintf(idl_fileCur(), "    }\n");
    idl_fileOutPrintf(idl_fileCur(), "    %s\n", set_discriminator);
    idl_fileOutPrintf(idl_fileCur(), "}\n");
    idl_fileOutPrintf(idl_fileCur(), "\n");
}

static void
idl_unionCaseBasic(
    idl_scope scope,
    const char *cxxIdName,
    idl_typeBasic typeBasic,
    const char *from_id,
    const char *to_id)
{
    const c_char *cxxTypeName = idl_getLiteBasicTypeName(typeBasic);

    OS_UNUSED_ARG(scope);

    switch (idl_typeBasicType(typeBasic)) {
    case idl_short:
    case idl_ushort:
    case idl_long:
    case idl_ulong:
    case idl_longlong:
    case idl_ulonglong:
    case idl_float:
    case idl_double:
    case idl_char:
    case idl_octet:
    case idl_boolean:
        idl_fileOutPrintf(idl_fileCur(), "        %s%s((%s)%s%s);\n",
            to_id,
            cxxIdName,
            cxxTypeName,
            from_id,
            cxxIdName);
    break;
    case idl_string:
        idl_fileOutPrintf(idl_fileCur(), "        %s%s(%s%s ? %s%s : \"\");\n",
            to_id,
            cxxIdName,
            from_id,
            cxxIdName,
            from_id,
            cxxIdName);
    break;
    }
}

static void
idl_unionCaseType(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *memberName, *scopedTypeName, *cxxTypeName;

    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(userData);

    memberName = idl_ISOCxx2Id(name);
    scopedTypeName = idl_scopedTypeName(typeSpec);
    cxxTypeName = idl_ISOCxx2TypeFromTypeSpec(typeSpec);

    idl_fileOutPrintf (idl_fileCur(), "    {\n");
    idl_fileOutPrintf (idl_fileCur(), "        extern void __%s__copyOut(const void *_from, void *_to);\n",
        scopedTypeName);
    idl_fileOutPrintf (idl_fileCur(), "        %s *tmp = new %s();\n", cxxTypeName, cxxTypeName);
    idl_fileOutPrintf (idl_fileCur(), "        __%s__copyOut(&from->_u.%s, tmp);\n", scopedTypeName, memberName);
    idl_fileOutPrintf (idl_fileCur(), "        to->%s(*tmp);\n", memberName);
    idl_fileOutPrintf (idl_fileCur(), "        delete tmp;\n");
    idl_fileOutPrintf (idl_fileCur(), "    }\n");

    os_free(cxxTypeName);
    os_free(memberName);
    os_free(scopedTypeName);
}

static void
idl_unionCaseArray(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *cxxTypeName;
    c_char *memberName = idl_ISOCxx2Id(name);
    (void)os_asprintf(&cxxTypeName, "_%s", memberName);
    cxxTypeName = idl_ISOCxx2TypeFromTypeSpec(typeSpec);
    idl_typeSpec subType = idl_typeArrayActual(idl_typeArray(typeSpec));
    char *tmp_string = idl_scopedLiteTypeName(subType);

    OS_UNUSED_ARG(userData);

    varIndex = 0;
    idl_fileOutPrintf(idl_fileCur(), "    {\n");
    if (idl_typeSpecType(subType) == idl_tseq) {
        c_char sname[32];
        snprintf(sname, (size_t) sizeof(sname), "_%s_seq", memberName);
        idl_fileOutPrintf (idl_fileCur(), "    typedef %s _SrcType",
                tmp_string);
//                idl_fileOutPrintf (idl_fileCur(), "    typedef %s _SrcType",
//                        idl_scopeStack(idl_typeUserScope(idl_typeUser(subType)), "::", sname));
    } else {
        idl_fileOutPrintf (idl_fileCur(), "    typedef %s _SrcType", tmp_string);
    }
    idl_arrayDimensions(idl_typeArray(typeSpec), OS_FALSE);
    idl_fileOutPrintf(idl_fileCur(), ";\n");
    idl_fileOutPrintf (idl_fileCur(), "        %s *tmp = new %s();\n", cxxTypeName, cxxTypeName);
    idl_fileOutPrintf(idl_fileCur(), "         const _SrcType *src = &from->_u.%s;\n\n", memberName);
    idl_arrayElements(idl_typeArray(typeSpec), "src", "tmp->data()", loopIndent);
    idl_fileOutPrintf (idl_fileCur(), "        to->%s(*tmp);\n", memberName);
    idl_fileOutPrintf (idl_fileCur(), "        delete tmp;\n");
    idl_fileOutPrintf(idl_fileCur(), "    }\n");

    os_free(tmp_string);
    os_free(cxxTypeName);
    os_free(memberName);
}

static void
idl_unionCaseSequence(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *memberName, *scopedTypeName;
    c_char *cxxTypeName;
    idl_typeSpec seqTypeSpec;

    OS_UNUSED_ARG(userData);

    seqTypeSpec = idl_typeSeqType(idl_typeSeq(typeSpec));
    scopedTypeName = idl_scopedLiteTypeName(seqTypeSpec);
    cxxTypeName = idl_ISOCxx2TypeFromTypeSpec(typeSpec);
    memberName = idl_ISOCxx2Id(name);

    idl_fileOutPrintf(idl_fileCur(), "    {\n");
    idl_fileOutPrintf(idl_fileCur(), "        const %s **src = (const %s **)&(from->_u.%s._buffer);\n",
            scopedTypeName, scopedTypeName, memberName);
    idl_fileOutPrintf(idl_fileCur(), "        uint32_t size0 = (size_t) from->_u.%s._length;\n", memberName);
    idl_fileOutPrintf(idl_fileCur(), "        %s *tmp = new %s();\n\n",
            cxxTypeName, cxxTypeName);

    idl_seqLoopCopy (seqTypeSpec, "src", "tmp", 1, 2);
    idl_fileOutPrintf(idl_fileCur(), "        to->%s(*tmp);\n", memberName);
    idl_fileOutPrintf(idl_fileCur(), "        delete tmp;\n");
    idl_fileOutPrintf(idl_fileCur(), "    }\n");

    os_free(memberName);
    os_free(cxxTypeName);
    os_free(scopedTypeName);
}


/** @brief callback function called on definition of a union case in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
        union <union-name> switch(<switch-type>) {
            case label1.1; .. case label1.n;
   =>           <union-case-1>;
            case label2.1; .. case label2.n;
   =>           ...        ...
            case labeln.1; .. case labeln.n;
   =>           <union-case-n>;
            default:
   =>           <union-case-m>;
        };
   @endverbatim
 *
 * Depending on the type of the union case, a copy strategy is used:
 * - If the type is \b idl_tbasic, for a string the string is duplicated
 *   via DDS::string_dup, for other basic  \b idl_typeBasicType is called.
 * - If the type is \b idl_typedef the copy strategy depends on the refered type.
 *   When this type is \b idl_tarray or \b idl_tseq a type specific copy routine
 *   is called. When type is something else, this routine is called recursively with
 *   with the refered type.
 * - If the type is \b idl_tenum, the element is immediately assigned.
 * - If the type is \b idl_tstruct or \b idl_tunion, the copyOut routine of that struct
 *   or union type is called.
 * - If the type is \b idl_tarray the array copy context is set and the service
 *   to generate code for copying arrays is called.
 * - If the type is \b idl_tseq, the sequence copy context is setup and the
 *   service to generate code for copying sequences is called.
 *
 * Note that unions can be reused when part of a sequence.
 * For that reason, replacement of strings and sequence buffers must be supported
 *
 * @param scope Current scope (the union the union case is defined in)
 * @param name Name of the union case
 * @param typeSpec Specifies the type of the union case
 */
static void
idl_unionCaseOpenClose(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *memberName = idl_ISOCxx2Id(name);
    c_char *scopedNameCxx = idl_ISOCxx2TypeFromTypeSpec(typeSpec);

    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(typeSpec) == idl_tbasic) {
        idl_unionCaseBasic(scope, name, idl_typeBasic(typeSpec), "from->_u.", "to->");
        idl_fileOutPrintf (idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_ttypedef) {
        if (idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tarray ||
            idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tseq ||
            idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tstruct ||
            idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tunion)
        {
            idl_unionCaseType(scope, name, typeSpec, userData);
            idl_fileOutPrintf (idl_fileCur(), "    break;\n");
        } else {
            /* Calls itself for the actual type in case of typedef */
            /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
            idl_unionCaseOpenClose (
                scope,
                name,
                idl_typeDefRefered(idl_typeDef(typeSpec)),
                userData);
        }
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tenum) {
        idl_fileOutPrintf(idl_fileCur(), "        to->%s((%s)from->_u.%s);\n",
            memberName, scopedNameCxx, memberName);
        idl_fileOutPrintf (idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tstruct ||
               idl_typeSpecType(typeSpec) == idl_tunion) {
        idl_unionCaseType(scope, name, typeSpec, userData);
        idl_fileOutPrintf (idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tarray) {
        loopIndent++;
        idl_unionCaseArray(scope, name, typeSpec, userData);
        loopIndent--;
        idl_fileOutPrintf (idl_fileCur(), "    break;\n");
    } else if (idl_typeSpecType(typeSpec) == idl_tseq) {
        idl_unionCaseSequence(scope, name, typeSpec, userData);
        idl_fileOutPrintf (idl_fileCur(), "    break;\n");
    } else {
        /* Do nothing, only to prevent dangling else-ifs QAC reports */
    }

    os_free(scopedNameCxx);
    os_free(memberName);
}

static c_char *
idl_valueFromLabelVal(
    idl_scope ownScope,
    idl_labelVal labelVal)
{
    static c_char labelName [1000];

    /* QAC EXPECT 3416; No side effect here */
    if (idl_labelValType(labelVal) == idl_lenum) {
        snprintf(labelName, sizeof(labelName), "%s", idl_labelEnumVal(idl_labelEnum(labelVal)));
    } else {
        switch (idl_labelValueVal(idl_labelValue(labelVal)).kind) {
        case V_CHAR:
            snprintf(labelName, sizeof(labelName), "%u", idl_labelValueVal(idl_labelValue(labelVal)).is.Char);
        break;
        case V_SHORT:
            snprintf(labelName, sizeof(labelName), "%d", idl_labelValueVal(idl_labelValue(labelVal)).is.Short);
        break;
        case V_USHORT:
            snprintf(labelName, sizeof(labelName), "%u", idl_labelValueVal(idl_labelValue(labelVal)).is.UShort);
        break;
        case V_LONG:
            snprintf(labelName, sizeof(labelName), "%d", idl_labelValueVal(idl_labelValue(labelVal)).is.Long);
        break;
        case V_ULONG:
            snprintf(labelName, sizeof(labelName), "%u", idl_labelValueVal(idl_labelValue(labelVal)).is.ULong);
        break;
        case V_LONGLONG:
            snprintf(labelName, sizeof(labelName), "%"PA_PRId64, idl_labelValueVal(idl_labelValue(labelVal)).is.LongLong);
        break;
        case V_ULONGLONG:
            snprintf(labelName, sizeof(labelName), "%"PA_PRIu64, idl_labelValueVal(idl_labelValue(labelVal)).is.ULongLong);
        break;
        case V_BOOLEAN:
            /* QAC EXPECT 3416; No side effect here */
            if ((int)idl_labelValueVal(idl_labelValue(labelVal)).is.Boolean == TRUE) {
                snprintf(labelName, sizeof(labelName), "true");
            } else {
                snprintf(labelName, sizeof(labelName), "false");
            }
        break;
        default:
            printf("idl_valueFromLabelVal: Unexpected label type\n");
        break;
        }
    }
    return labelName;
    /* QAC EXPECT 5101; Because of the switch statement the real complexity is rather low, no need to change */
}

static void
idl_unionLabelOpenClose(
    idl_scope ownScope,
    idl_labelVal labelVal,
    void *userData)
{
    OS_UNUSED_ARG(ownScope);
    OS_UNUSED_ARG(userData);

    /* QAC EXPECT 3416; No side effect here */
    if (idl_labelValType(labelVal) == idl_ldefault) {
        idl_fileOutPrintf(idl_fileCur(), "    default:\n");
    } else {
        idl_fileOutPrintf(idl_fileCur(), "    case %s:\n", idl_valueFromLabelVal(ownScope, labelVal));
    }
    /* QAC EXPECT 5101, 5103: Complexity is limited, by independent cases, per case the number of lines is lower  */
}


/**
 * Standard control structure to specify that inline
 * type definitions are to be processed prior to the
 * type itself in contrast with inline.
 */
static idl_programControl idlControl = {
        idl_prior
    };

/** @brief return the program control structure for the CORBA C++ CopyOut generation functions.
 */
static idl_programControl *
idl_getControl(
    void *userData)
{
    OS_UNUSED_ARG(userData);
    return &idlControl;
}

/**
 * Specifies the callback table for the Lite C++ CopyIn generation functions.
 */
static struct idl_program
idl_genLiteISOCxxCopyout = {
    idl_getControl,
    idl_fileOpen,
    NULL, /* idl_fileClose */
    idl_moduleOpen,
    NULL, /* idl_moduleClose */
    idl_structureOpen,
    idl_structureClose,
    idl_structureMemberOpenClose,
    NULL, /* idl_enumerationOpen */
    NULL, /* idl_enumerationClose */
    NULL, /* idl_enumerationElementOpenClose */
    idl_unionOpen,
    idl_unionClose,
    idl_unionCaseOpenClose,
    NULL, /* idl_unionLabelsOpenClose */
    idl_unionLabelOpenClose,
    idl_typedefOpenClose,
    NULL, /* idl_boundedStringOpenClose */
    NULL, /* idl_sequenceOpenClose */
    NULL, /* idl_constantOpenClose */
    NULL, /* idl_artificialDefaultLabelOpenClose */
    NULL  /* userData */
};

/** @brief return the callback table for the Lite C++ CopyIn generation functions.
 */
idl_program
idl_genLiteISOCxxCopyoutProgram(void)
{
    return &idl_genLiteISOCxxCopyout;
}
