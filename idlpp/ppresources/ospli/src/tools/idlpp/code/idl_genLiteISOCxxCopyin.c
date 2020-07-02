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
 * This module generates Lite C++ CopyIn functions. It handles input types
 * that match the IDL/C++ mapping as specified by the OMG and writes the
 * data into data types as applicable for Lite.
 */

#include "idl_program.h"
#include "idl_scope.h"
#include "idl_genLiteISOCxxCopyin.h"
#include "idl_genISOCxx2Helper.h"
#include "idl_genSplHelper.h"
#include "idl_genLiteHelper.h"
#include "idl_genLanguageHelper.h"
#include "idl_tmplExp.h"
#include "idl_catsDef.h"
#include "idl_stacDef.h"
#include "idl_keyDef.h"

#include "c_typebase.h"
#include "os_heap.h"
#include "os_stdlib.h"
#include "os_abstract.h"

/** Text indentation level (4 spaces per indent) */
static c_long loopIndent;
    /** Index for array loop variables, incremented for each array dimension */
static c_long varIndex;

static c_char *
idl_seqAllocBuffer(
    idl_typeSeq typeSeq,
    const c_char *length,
    char *buffer,
    size_t bsize)
{
    idl_typeSpec nextType = idl_typeSeqType(typeSeq);

    char* tmp_string = idl_scopedLiteTypeName(nextType);
    snprintf(buffer, bsize, "(%s == 0) ? 0 : (%s *)dds_alloc(%s * sizeof(%s))",
            length,
            tmp_string,
            length,
            tmp_string);
    os_free(tmp_string);

    return buffer;
}


static void
idl_arrayElements (
    idl_scope scope,
    idl_typeArray typeArray,
    const char *from,
    const char *to,
    c_bool indirect,
    c_long indent,
    void *userData);

static void idl_seqElements (const char *name, idl_typeDef typeDef, c_long indent, void *userData);
static void idl_seqLoopCopy (idl_typeSpec typeSpec, const char *from, const char *to, c_long loop_index, c_long indent, void *userData);

/** @brief callback function called on opening the IDL input file.
 *
 * Generate code to include standard include files.
 *
 * @param scope Current scope (not used)
 * @param name Name of the IDL input file (not used)
 * @return Next action for this file (idl_explore)
 */
static idl_action
idl_fileOpen (
    idl_scope scope,
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    if (idl_getIsISOCpp())
    {
        idl_fileOutPrintf(idl_fileCur(), "#include <org/eclipse/cyclonedds/core/EntityRegistry.hpp>\n");
    }

    idl_fileOutPrintf (idl_fileCur(), "\n");

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
idl_moduleOpen (
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
 * For structures a copyIn routine named __<scope-elements>_<structure-name>__copyIn
 * will be prepared. The signature of this copyIn routine is:
 * @verbatim
    void copyIn (,
        const void *from,
        void *to);
    @endverbatim
 *
 * The copyIn routine signature is generated based upon the input
 * parameters which specify the scope and it's name.
 *
 * @param scope Current scope (and scope of the structure definition)
 * @param name Name of the structure
 * @param structSpec Specification of the struct holding the amount of members (not used)
 * @return Next action for this struct (idl_explore)
 */
static idl_action
idl_structureOpen (
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

    idl_fileOutPrintf (idl_fileCur(), "void\n");
    idl_fileOutPrintf (idl_fileCur(), "__%s__copyIn(\n", scopedTypeName);

    idl_fileOutPrintf (idl_fileCur(), "    const void *_from,\n");
    idl_fileOutPrintf (idl_fileCur(), "    void *_to)\n");

    idl_fileOutPrintf (idl_fileCur(), "{\n");
    idl_fileOutPrintf (idl_fileCur(), "    const class %s *from;\n", scopedCxxTypeName);
    idl_fileOutPrintf (idl_fileCur(), "    %s *to;\n\n", scopedTypeName);
    idl_fileOutPrintf (idl_fileCur(), "    from = (const class %s *)_from;\n", scopedCxxTypeName);
    idl_fileOutPrintf (idl_fileCur(), "    to = (%s *)_to;\n\n", scopedTypeName);

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
 * The function finalizes the copyIn routine for the structure by
 * generating the closing bracket ('}').
 *
 * @param name Name of the structure (not used)
 */
static void
idl_structureClose (
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    idl_fileOutPrintf (idl_fileCur(), "\n");
    idl_fileOutPrintf (idl_fileCur(), "}\n");
    idl_fileOutPrintf (idl_fileCur(), "\n");
}

/** @brief Generate copy statement for elements of basic type.
 *
 * The function generates for the provided basic type a copyIn
 * statement. The identification of the source and destination
 * elements must be provided by the caller.
 *
 * Basic type elements.
 *
 * @param scope Scope of the element
 * @param name Name of the element
 * @param typeBasic Specification of the type of the element
 * @param from_id Identification of the source
 * @param Identification of the destination
 */
static void
idl_basicMemberType (
    idl_scope scope,
    const char *name,
    idl_typeBasic typeBasic,
    const char *from_id,
    const char *to_id)
{
    c_ulong maxlen;
    c_char* cid;

    OS_UNUSED_ARG(scope);

    cid = idl_ISOCxx2Id(name);

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
    case idl_boolean:
    case idl_octet:
        idl_fileOutPrintf (idl_fileCur(), "    %s%s = (%s)(%s%s());\n",
                to_id,
                cid,
                idl_getLiteBasicTypeName(typeBasic),
                from_id,
                cid);
        break;
    case idl_string:
        maxlen = idl_typeBasicMaxlen(typeBasic);
        if (maxlen == 0) {
#if 0
            idl_fileOutPrintf(idl_fileCur(), "    %s%s = dds_string_dup(%s%s);\n",
                    to_id,
                    cid,
                    from_id,
                    cid);
#else
            idl_fileOutPrintf(idl_fileCur(), "    %s%s = (char *)((%s%s()).c_str());\n",
                    to_id,
                    cid,
                    from_id,
                    cid);
#endif

        } else {
            idl_fileOutPrintf(idl_fileCur(), "    strncpy (%s%s, %s%s().c_str(), %d);\n",
                    to_id,
                    cid,
                    from_id,
                    cid,
                    maxlen + 1);
        }
        break;
    default:
        printf ("idl_basicMemberType: Unexpected basic type\n");
        break;
    }

    os_free(cid);
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
 * - If the type is \b idl_tstruct or \b idl_tunion, the copyIn routine of that struct
 *   or union type is called.
 * - If the type is \b idl_tarray the array copy context is set and the service
 *   to copy arrays is called.
 * - If the type is \b idl_tseq, the sequence copy context is setup and the
 *   service to copy sequences is called.
 *
 * @param scope Current scope
 * @param name Name of the structure member
 * @param typeSpec Type specification of the structure member
 */
static void
idl_structureMemberOpenClose (
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char buffer[256];
    c_char *scopedTargetName;
    c_char* cid;
    c_long indent = 1;
    c_char *scopedCxxTypeName = idl_ISOCxx2TypeFromTypeSpec(typeSpec);
    c_char* scopedTypeName = idl_scopedTypeName(typeSpec);

    cid = idl_ISOCxx2Id(name);

    /* Expected types: idl_tbasic, idl_ttypedef, idl_tenum, idl_tstruct, idl_tunion, idl_tarray, idl_tseq */

    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(typeSpec) == idl_tbasic) {
        idl_basicMemberType (scope, name, idl_typeBasic(typeSpec), "from->", "to->");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_ttypedef) {
        /* QAC EXPECT 3416; No side effect here */
        if ((idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec))) == idl_tstruct) ||
                (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec))) == idl_tseq)) {
            idl_fileOutPrintf (idl_fileCur(), "    {\n");
            IDL_PRINTLINE (indent);
            idl_fileOutPrintf (idl_fileCur(), "        extern void __%s__copyIn(const %s *, %s *);\n",
            		scopedTypeName,
                    scopedCxxTypeName,
                    scopedTypeName);
            idl_fileOutPrintf (idl_fileCur(), "        __%s__copyIn(&from->%s(), &to->%s);\n",
            		scopedTypeName,
                    cid,
                    cid);
            idl_fileOutPrintf (idl_fileCur(), "    }\n");
        } else {
            /* Calls itself for the actual type in case of typedef */
            /* QAC EXPECT 3670; We wan't to use recursion, the recursion is finite */
            idl_structureMemberOpenClose (
                    scope,
                    name,
                    idl_typeDefActual(idl_typeDef(typeSpec)),
                    userData);

        }
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tenum) {
        idl_fileOutPrintf (idl_fileCur(), "    to->%s = (%s)from->%s();\n",
            cid,
            scopedTypeName,
            cid);
        /* QAC EXPECT 3416; No side effect here */
    } else if ((idl_typeSpecType(typeSpec) == idl_tstruct) ||
               (idl_typeSpecType(typeSpec) == idl_tunion)) {
        idl_fileOutPrintf (idl_fileCur(), "    {\n");
        IDL_PRINTLINE (indent);
        idl_fileOutPrintf (idl_fileCur(), "        extern void __%s__copyIn(const void *, void *);\n",
        		scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "        __%s__copyIn(&from->%s(), &to->%s);\n",
        		scopedTypeName,
            cid,
            cid);
        idl_fileOutPrintf (idl_fileCur(), "    }\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tarray) {
        c_char dest[256];
        c_char src[256];
        varIndex = 0;
        snprintf(dest, (size_t)sizeof(dest), "to->%s", name);
        snprintf(src, (size_t)sizeof(src), "from->%s()", name);
        idl_fileOutPrintf (idl_fileCur(), "    {\n");
        IDL_PRINTLINE (indent);

        idl_arrayElements (scope, idl_typeArray(typeSpec), src, dest, FALSE, indent, userData);
        idl_fileOutPrintf (idl_fileCur(), "    }\n");

        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tseq) {
        c_char *cxxTypeName, *scopedCxxTypeName;
        const c_char *bufferTp;
        idl_typeSpec nextType;

        nextType = idl_typeSeqType(idl_typeSeq(typeSpec));
        scopedTargetName = idl_scopedLiteTypeName(nextType);

        os_asprintf (&cxxTypeName, "_%s_seq", name);
        scopedCxxTypeName = idl_scopeStack(idl_typeUserScope(idl_typeUser(typeSpec)), "::", cxxTypeName);

        switch (idl_typeSpecType(nextType)) {
        case idl_tstruct:
        case idl_tunion:
            bufferTp = scopedTargetName;
            break;
        default:
            bufferTp = "uint8_t";
            break;
        };

        idl_fileOutPrintf (idl_fileCur(), "    {\n");
        if (idl_isContiguous(idl_typeSpecDef(nextType))) {
                IDL_PRINTLINE (indent);
                idl_fileOutPrintf (idl_fileCur(), "        const %s *src = &from->%s();\n\n", scopedCxxTypeName, cid);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._maximum = (uint32_t)(*src).max_size();\n", cid);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._length  = (uint32_t)(*src).size();\n", cid);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._buffer  = (%s *)&((*src)[0]);\n", cid, bufferTp);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._release = false;\n", cid);
        } else {
                IDL_PRINTLINE (indent);
                idl_fileOutPrintf (idl_fileCur(), "        const %s *src = &from->%s();\n", scopedCxxTypeName, cid);
                idl_fileOutPrintf (idl_fileCur(), "        %s *dest0;\n", scopedTargetName);
                idl_fileOutPrintf (idl_fileCur(), "        uint32_t length0;\n\n");
                idl_fileOutPrintf (idl_fileCur(), "        length0 = (uint32_t)(*src).size();\n");
                idl_fileOutPrintf (idl_fileCur(), "        dest0 = %s;\n",
                        idl_seqAllocBuffer(idl_typeSeq(typeSpec), "length0", buffer, sizeof(buffer)));
                idl_seqLoopCopy (nextType, "*src", "dest0", 1, 2, userData);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._maximum = (uint32_t)(*src).max_size();\n", cid);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._length  = length0;\n", cid);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._buffer  = (%s *) dest0;\n", cid, bufferTp);
                idl_fileOutPrintf (idl_fileCur(), "        to->%s._release = false;\n", cid);
        }
        idl_fileOutPrintf (idl_fileCur(), "    }\n");

        os_free(scopedCxxTypeName);
        os_free(cxxTypeName);

    } else {
        /* Do nothing, only to prevent dangling else-ifs QAC reports */
    }
    /* QAC EXPECT 5103; Code is clearly separated in a number of cases of which each is maintainable */

    os_free(cid);
    os_free(scopedTypeName);
    os_free(scopedCxxTypeName);
}

/** @brief Generate the loop variables for the array copy.
 *
 * Generate the loop variables for the array copy. Per dimension a
 * loop variable named i# is required, where # represents the dimension.
 * (I.e. first dimension handled by i0, second by i1, etc.)
 * @verbatim
   int i0; // dimension-first
   int i1; // dimension-first+1
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
idl_arrayLoopVariables (
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
   for (i0 = 0; i0 < <size-dimension-first>; i0++) {
       for (i1 = 0; i1 < <size-dimension-first+1>; i1++) {
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
idl_arrayLoopCopyOpen (
    idl_typeArray typeArray,
    c_long indent)
{
    loopIndent++;
    idl_printIndent(loopIndent + indent);
    idl_fileOutPrintf(idl_fileCur(), "for (i%d = 0; i%d < %d; i%d++) {\n",
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
    [i0][i1]..[i#]
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 */
static void
idl_arrayLoopCopyIndex (
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
    [i0][i1]..[i#]
   @endverbatim
 *
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 */
static void
idl_arrayLoopCopyIndexString (
    c_char *indexString,
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
        return_val =  idl_indexSize (idl_typeArray(idl_typeArrayType(typeArray)))+1;
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
    c_long indent,
    idl_scope scope,
    void *userData)
{
    c_char buffer[256];
    idl_typeSpec nextType;
    c_long total_indent;
    c_ulong maxlen;
    c_char* scopedTypeName, *scopedCxxTypeName;

    loopIndent++;
    switch (idl_typeSpecType(typeSpec)) {
    case idl_tstruct:
    case idl_tunion:
        varIndex = 0;
        IDL_PRINTLINE (loopIndent + indent);
        idl_printIndent(loopIndent + indent);
        idl_fileOutPrintf(idl_fileCur(), "extern void __%s__copyIn(const void *, void *);\n\n",
                idl_scopedTypeName(typeSpec));

        idl_printIndent (loopIndent + indent);
        idl_fileOutPrintf (idl_fileCur(),"__%s__copyIn(&(%s)",
                idl_scopedTypeName(typeSpec), from);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), ", &(%s)", to);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), ");\n");
        break;
    case idl_ttypedef:
        {
            idl_typeSpec actualType = idl_typeDefActual(idl_typeDef(typeSpec));

            switch (idl_typeSpecType(actualType)) {
            case idl_tbasic:
                if (idl_typeBasicType(idl_typeBasic(actualType)) == idl_string) {
                    maxlen = idl_typeBasicMaxlen(idl_typeBasic(actualType));
                    if (maxlen == 0) {
                        IDL_PRINTLINE (loopIndent + indent);
                        idl_printIndent(loopIndent + indent);
                        idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
                        idl_arrayLoopCopyIndex(typeArray);
                        idl_fileOutPrintf(idl_fileCur(), " = dds_string_dup(((%s))", from);
                        idl_arrayLoopCopyIndex(typeArray);
                        idl_fileOutPrintf(idl_fileCur(), ");\n");
                    } else {
                        IDL_PRINTLINE (loopIndent + indent);
                        idl_printIndent(loopIndent + indent);
                        idl_fileOutPrintf(idl_fileCur(), "strncpy ((%s)", to);
                        idl_arrayLoopCopyIndex(typeArray);
                        idl_fileOutPrintf(idl_fileCur(), ", (%s)", from);
                        idl_arrayLoopCopyIndex(typeArray);
                        idl_fileOutPrintf(idl_fileCur(), ".c_str (), %d);\n", maxlen + 1);
                    }
                } else {
                    /* Only alternative non-contiguous primitive type is boolean */
                    assert(idl_typeBasicType (idl_typeBasic(actualType)) == idl_boolean);
                    IDL_PRINTLINE (loopIndent + indent);
                    idl_printIndent(loopIndent + indent);
                    idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), " = (uint8_t) (%s)", from);
                    idl_arrayLoopCopyIndex(typeArray);
                    idl_fileOutPrintf(idl_fileCur(), ";\n");
                }
                break;
            case idl_tstruct:
            case idl_tunion:
                IDL_PRINTLINE (loopIndent + indent-1);
                idl_printIndent (loopIndent + indent);
                idl_fileOutPrintf(idl_fileCur(), "extern void __%s__copyIn(const void *, void *);\n\n",
                    idl_scopedTypeName(typeSpec));
                idl_printIndent(loopIndent + indent);
                idl_fileOutPrintf (idl_fileCur(),"__%s__copyIn(&(%s)",
                    idl_scopedTypeName(typeSpec),
                    from);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf (idl_fileCur(), ", &(%s)",
                    to);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf (idl_fileCur(), ");\n");
                indent--;
                break;
            break;
            case idl_tseq:
            case idl_tarray:
                scopedTypeName = idl_scopedTypeName(typeSpec);
                scopedCxxTypeName = idl_scopeStack(idl_typeUserScope(idl_typeUser(typeSpec)), "::", idl_typeSpecName(typeSpec));
                IDL_PRINTLINE (loopIndent + indent-1);
                idl_printIndent (loopIndent + indent);
                idl_fileOutPrintf(idl_fileCur(), "extern void __%s__copyIn(", scopedTypeName);
                idl_fileOutPrintf(idl_fileCur(), "const %s *,", scopedCxxTypeName);

                idl_fileOutPrintf(idl_fileCur(), "%s *);\n\n", scopedTypeName);
                idl_printIndent(loopIndent + indent);
                idl_fileOutPrintf (idl_fileCur(),"__%s__copyIn((const %s *)&(%s)",
					scopedTypeName,
					scopedCxxTypeName,
					from);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf (idl_fileCur(), ", (%s *)&(%s)", scopedTypeName,
                to);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf (idl_fileCur(), ");\n");
                os_free(scopedCxxTypeName);
                os_free(scopedTypeName);
                break;
            default:
                printf ("idl_arrayLoopCopyBody: Unexpected type\n");
                /* QAC EXPECT 3416; No side effect here */
                assert (0);
                break;
            }
        }
        break;
    case idl_tbasic:
        /* This may only be string */
        /* QAC EXPECT 3416; No side effect here */
        if (idl_typeBasicType (idl_typeBasic(typeSpec)) == idl_string) {
            maxlen = idl_typeBasicMaxlen(idl_typeBasic(typeSpec));
            if (maxlen == 0) {
                IDL_PRINTLINE (loopIndent + indent);
                idl_printIndent(loopIndent + indent);
                idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf(idl_fileCur(), " = dds_string_dup((%s)", from);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf(idl_fileCur(), ".c_str ());\n");
            } else {
                IDL_PRINTLINE (loopIndent + indent);
                idl_printIndent(loopIndent + indent);
                idl_fileOutPrintf(idl_fileCur(), "strncpy ((%s)", to);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf(idl_fileCur(), ", (%s)", from);
                idl_arrayLoopCopyIndex(typeArray);
                idl_fileOutPrintf(idl_fileCur(), ".c_str (), %d);\n", maxlen + 1);
            }
        } else {
            /* Only alternative non-contiguous primitive type is boolean */
            assert(idl_typeBasicType (idl_typeBasic(typeSpec)) == idl_boolean);
            IDL_PRINTLINE (loopIndent + indent);
            idl_printIndent(loopIndent + indent);
            idl_fileOutPrintf(idl_fileCur(), "(%s)", to);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), " = (uint8_t) (%s)", from);
            idl_arrayLoopCopyIndex(typeArray);
            idl_fileOutPrintf(idl_fileCur(), ";\n");
        }

        break;
    case idl_tseq:
        nextType = idl_typeSeqType(idl_typeSeq(typeSpec));
        maxlen = idl_typeSeqMaxSize(idl_typeSeq(typeSpec));

        total_indent = indent+idl_indexSize(typeArray);

        char source[256];

        snprintf(source, (size_t)sizeof(source), "(%s)", from);
        idl_arrayLoopCopyIndexString(source, typeArray);
        scopedTypeName = idl_scopedTypeName(nextType);

        IDL_PRINTLINE (total_indent);
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    uint32_t length0;\n");
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    %s *dest0;\n\n",
                scopedTypeName);
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    length0 = (uint32_t)(%s)", from);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), ".length();\n");
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    dest0 = %s;\n",
                idl_seqAllocBuffer(idl_typeSeq(typeSpec), "length0", buffer, sizeof(buffer)));
        idl_seqLoopCopy (nextType, source, "dest0", 1, loopIndent+1, userData);
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    (%s)", to);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), "._maximum = (uint32_t)(%s)", from);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), ".max_size();\n");
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    (%s)", to);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), "._length  = (uint32_t)(%s)", from);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(),  ".size();\n");
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    (%s)", to);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), "._buffer = dest0;\n");
        idl_printIndent (total_indent);
        idl_fileOutPrintf (idl_fileCur(), "    (%s)", to);
        idl_arrayLoopCopyIndex(typeArray);
        idl_fileOutPrintf (idl_fileCur(), "._release = false;\n");
        os_free(scopedTypeName);

        break;
    default:
        /* QAC EXPECT 3416; No side effect here */
        assert (0);
        break;
    }
    loopIndent--;
    /* QAC EXPECT 5101, 5103: Complexity is limited, by independent cases, per case the number of lines is lower  */
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
idl_arrayLoopCopyClose (
    idl_typeArray typeArray,
    c_long indent)
{
    idl_printIndent (loopIndent + indent);
    loopIndent--;
    idl_fileOutPrintf (idl_fileCur(), "}\n");
    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(idl_typeArrayType(typeArray)) == idl_tarray) {
        /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
        idl_arrayLoopCopyClose (idl_typeArray(idl_typeArrayType(typeArray)), indent);
    }
}

/** @brief Generate copy loops for array.
 *
 * For each array dimension generate a loop copy action.
 * An array copy action is construct of:
 * - a loop variable (idl_arrayLoopVariables)
 * - a loop statement (idl_arrayLoopCopyOpen)
 * - copying the array element (idl_arrayLoopCopyBody)
 * - closing the loop statement (idl_arrayLoopCopyClose)
 *
 * This results in the following pattern for copying arrays per element:
 * @verbatim
   int i0;
   int i1;
   ..
   int i#;

   for (i0 = 0; i0 < <size-dimension-first>; i0++) {
       for (i1 = 0; i1 < <size-dimension-first+1>; i1++) {
           ..
               for (i# = 0; i# < <size-dimension-last>; i#++) {
                    // copy array element
                    to[i0][i1]..[i#] = from[i0][i1]..[i#].in() // for string
                    __<type>__copyIn (&from[i0][i1]..[i#], &to[i0][i1]..[i#]) // for struct, union
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
idl_arrayLoopCopy (
    idl_typeArray typeArray,
    const char *from,
    const char *to,
    c_long indent,
    idl_scope scope,
    void *userData)
{
    loopIndent = 0;
    idl_arrayLoopVariables(typeArray, indent);
    idl_arrayLoopCopyOpen(typeArray, indent);
    idl_arrayLoopCopyBody(typeArray, idl_typeArrayActual(typeArray), from, to, indent, scope, userData);
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
 * @param typeArray The type specification for the array which holds
 * the basic type as wel as the size for each dimension. The first dimension
 * is on top of that stack.
 * @param from Identification of the source to copy from
 * @param to Identification of the destination to copy to
 * @param indirect Indentifies if the provided to and from are pointers of not
 * @param indent Indentation of the output
 */
static void
idl_arrayElements (
    idl_scope scope,
    idl_typeArray typeArray,
    const char *from,
    const char *to,
    c_bool indirect,
    c_long indent,
    void *userData)
{
    idl_typeSpec subType = idl_typeArrayActual(typeArray);

    if (indirect) {
        if (idl_isContiguous(idl_typeSpecDef(subType))) {
            idl_printIndent (indent);
            idl_fileOutPrintf (idl_fileCur(), "    memcpy (%s, %s, sizeof (*%s));\n", to, from, to);
        } else {
            char *dest;
            char *src;

            src = os_malloc(strlen(from) + 2);
            os_sprintf(src, "*%s", from);
            dest = os_malloc(strlen(to) + 2);
            os_sprintf(dest, "*%s", to);
            idl_arrayLoopCopy (typeArray, src, dest, indent, scope, userData);
            os_free(src);
            os_free(dest);
        }
    } else {

        if (idl_isContiguous(idl_typeSpecDef(subType))) {
            idl_printIndent (indent);
            idl_fileOutPrintf (idl_fileCur(), "    memcpy (&(%s), &(%s), sizeof (%s));\n", to, from, to);
        } else {
            idl_arrayLoopCopy (typeArray, from, to, indent, scope, userData);
        }
    }
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
idl_seqIndex (
    c_long indent)
{
    c_char index[64];
    c_char is[64];
    c_long i;

    index[0] = 0;
    for (i = 0; i < indent; i++) {
        snprintf (is, (size_t)sizeof(is), "[j%d]", i);
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
   long length0;
   <scoped-sequence-element-type-name> *dest0;

   length0 = (long)(*src0).length();
   dest0 = (<scoped-sequence>_allocbuf();
   // Body to copy sequence contents from <source-id> to dest0
   <destination-id> = dest0;
   @endverbatim
 *
 * Note that in C++, nested sequences are always anonymous. Thus sequence copy routines in
 * C++ need to nest the copy actions (in contrast with C).
 * The variable names used "i0", "length0", "dst0" and "src0", suggest otherwise.
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
   for (i0 = 0; i0 < (unsigned int)length0; i0++) {
       // Copy sequence element (type specific)
   }
   @endverbatim
 *
 * The element copyIn strategy is as follows:
 * - If the sequence element type is \b idl_tenum, direct assignment is used
 * - If the sequence element type is \b idl_tbasic, depending on whether it is
 *   a string or not, elements are duplicated via c_newString or otherwise
 *   immediately assigned
 * - If the sequence element type is \b idl_tstruct or \b idl_tunion the copyIn
 *   function for that struct or union is called.
 * - If the sequence element type is \b idl_ttypedef the strategy depends on the
 *   actual type of the typedef. For structs unions and arrays the copyIn routine
 *   for that type is called. For basic string type, the string is duplicated
 *   via c_stringNew. For other basic types and enumeration it is just assigned.
 * - If the sequence element type is \b idl_tseq, a new sequence copy operation
 *   is setup for the specific sequence type.
 *
 * Structure types (not unions) that do not contain any reference types are
 * copied via a plain memory copy because the sequence elements are located in
 * consequtive memory with the same memory map for C CORBA as well as Lite.
 * These are identified using idl_isContiguous().
 *
 * @param typeSpec The specification of the actual type of the sequence
 * @param from Specifies the identification of the source
 * @param to Specifies the identification of the destination
 * @param loop_index Specifies the index if the variables when sequence copy
 * routines are nested. The top level sequence starts with index 0.
 * @param indent Specifies the indentation level
 */
static void
idl_seqLoopCopy (
    idl_typeSpec typeSpec,
    const char *from,
    const char *to,
    c_long loop_index,
    c_long indent,
    void *userData)
{
    c_char buffer[256];
    c_char destin[32];
    c_char length[32];
    c_char *scopedName;
    idl_typeSpec nextType;
    c_ulong maxlen;
    char* tmp_string = idl_scopedLiteTypeName(typeSpec);

    if (idl_isContiguous(idl_typeSpecDef(typeSpec))) {
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "{\n");
        IDL_PRINTLINE (indent);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    const %s *buf%d;\n",
                tmp_string,loop_index-1);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    buf%d = (const %s *)(%s)%s.data();\n",
                loop_index-1, tmp_string, from, idl_seqIndex (loop_index-1));

        if(idl_typeSpecType (typeSpec) == idl_tenum){
            idl_printIndent (indent);
            idl_fileOutPrintf (idl_fileCur(), "    memcpy (%s,buf%d,length%d* sizeof(*%s));\n",
                to, loop_index-1, loop_index-1, to);
        } else {
            idl_printIndent (indent);
            idl_fileOutPrintf (idl_fileCur(), "    memcpy (%s,buf%d,length%d* sizeof(*%s));\n",
                to, loop_index-1, loop_index-1, to);
        }

        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "}\n");
        os_free (tmp_string);
        return;
    }

    idl_printIndent (indent);
    idl_fileOutPrintf (idl_fileCur(), "{\n");
    IDL_PRINTLINE (indent);
    idl_printIndent (indent);
    idl_fileOutPrintf (idl_fileCur(), "    uint32_t j%d;\n", loop_index-1);
    idl_printIndent (indent);
    idl_fileOutPrintf (idl_fileCur(), "    for (j%d = 0; j%d < length%d; j%d++) {\n",
        loop_index-1,
        loop_index-1,
        loop_index-1,
        loop_index-1);

    indent++;
    switch (idl_typeSpecType (typeSpec)) {
    case idl_tenum:
        maxlen = idl_typeEnumNoElements(idl_typeEnum(typeSpec));
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    %s[j%d] = (%s)(%s)%s;\n",
                to,
                loop_index-1,
                tmp_string,
                from,
                idl_seqIndex(loop_index));
        break;
    case idl_tbasic:
        /* QAC EXPECT 3416; No side effect here */
        if (idl_typeBasicType (idl_typeBasic(typeSpec)) == idl_string) {
            maxlen = idl_typeBasicMaxlen(idl_typeBasic(typeSpec));
            idl_printIndent (indent);
            if( maxlen != 0) {
                idl_fileOutPrintf (idl_fileCur(), "    strncpy (%s[j%d], ((%s)%s).c_str(), %d);\n",
                        to,
                        loop_index-1,
                        from,
                        idl_seqIndex(loop_index),
                        maxlen + 1);
            } else {
                idl_fileOutPrintf (idl_fileCur(), "    %s[j%d] = dds_string_dup(((%s)%s).c_str());\n",
                        to,
                        loop_index-1,
                        from,
                        idl_seqIndex(loop_index));
            }
        } else {
            /* Only alternative non-contiguous primitive type is boolean */
            assert(idl_typeBasicType (idl_typeBasic(typeSpec)) == idl_boolean);
            idl_fileOutPrintf (idl_fileCur(), "    %s[j%d] = (uint8_t) ((%s)%s);\n",
                    to,
                    loop_index-1,
                    from,
                    idl_seqIndex(loop_index));
        }
        break;
    case idl_tstruct:
    case idl_tunion:
        varIndex = 0;
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    extern void __%s__copyIn(const void *, void *);\n",
            idl_scopedTypeName(typeSpec));
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    __%s__copyIn(&(%s)%s, (%s *)&%s[j%d]);\n",
            idl_scopedTypeName(typeSpec),
            from,
            idl_seqIndex(loop_index),
            tmp_string,
            to,
            loop_index-1);
        break;
    case idl_ttypedef:
        idl_printIndent (indent);
        switch (idl_typeSpecType(idl_typeDefActual(idl_typeDef(typeSpec)))) {
        case idl_tstruct:
        case idl_tunion:
        case idl_tarray:
        case idl_tseq:
            idl_fileOutPrintf (idl_fileCur(), "    extern void __%s__copyIn(const %s *, %s *);\n",
                idl_scopedTypeName (typeSpec),
                tmp_string,
                idl_scopedTypeName (typeSpec));
            idl_printIndent (indent);
            idl_fileOutPrintf (idl_fileCur(), "    __%s__copyIn(&(%s)%s, (%s *)&%s[j%d]);\n",
                idl_scopedTypeName(typeSpec),
                from,
                idl_seqIndex(loop_index),
                tmp_string,
                to,
                loop_index-1);
            break;
        case idl_tenum:
            maxlen = idl_typeEnumNoElements(idl_typeEnum(idl_typeDefActual(idl_typeDef(typeSpec))));

            idl_printIndent (indent);
            idl_fileOutPrintf (idl_fileCur(), "    %s[j%d] = (%s)(%s)%s;\n",
                    to,
                    loop_index-1,
                    tmp_string,
                    from,
                    idl_seqIndex(loop_index));
            break;
        case idl_tbasic:
            if (idl_typeBasicType(idl_typeBasic(idl_typeDefActual(idl_typeDef(typeSpec)))) == idl_string) {
                maxlen = idl_typeBasicMaxlen(idl_typeBasic(idl_typeDefActual(idl_typeDef(typeSpec))));
                if(maxlen == 0){
                    idl_fileOutPrintf (idl_fileCur(), "    %s[j%d] = dds_string_dup(((%s)%s).c_str());\n",
                            to,
                            loop_index-1,
                            from,
                            idl_seqIndex(loop_index));
                } else {
                    idl_fileOutPrintf (idl_fileCur(), "    strncpy (%s[j%d], ((%s)%s).c_str(), %d);\n",
                            to,
                            loop_index-1,
                            from,
                            idl_seqIndex(loop_index),
                            maxlen + 1);
                }
            } else {
                /* Only alternative non-contiguous primitive type is boolean */
                assert(idl_typeBasicType (idl_typeBasic(typeSpec)) == idl_boolean);
                idl_printIndent (indent);
                idl_fileOutPrintf (idl_fileCur(), "    %s[j%d] = (uint8_t) ((%s)%s);\n",
                        to,
                        loop_index-1,
                        from,
                        idl_seqIndex(loop_index));
            }
            break;
        default:
            printf ("idl_seqLoopCopy: Unexpected type\n");
            assert (0);
            break;
        }
        break;
    case idl_tseq:
        nextType = idl_typeSeqType(idl_typeSeq(typeSpec));
        scopedName = idl_scopedTypeName(nextType);
        maxlen = idl_typeSeqMaxSize(idl_typeSeq(typeSpec));

        snprintf (destin, (size_t)sizeof(destin), "dest%d", loop_index);

        IDL_PRINTLINE (indent);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    uint32_t length%d;\n", loop_index);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    %s *dest%d;\n\n", scopedName, loop_index);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    length%d = (uint32_t)(%s)%s.size();\n", loop_index, from, idl_seqIndex(loop_index));
        idl_printIndent (indent);
        sprintf(length, "length%d", loop_index);
        idl_fileOutPrintf (idl_fileCur(), "    dest%d = %s;\n",
                loop_index,
                idl_seqAllocBuffer(idl_typeSeq(typeSpec), length, buffer, sizeof(buffer)));
        idl_seqLoopCopy (nextType, from, destin, loop_index+1, indent+1, userData);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    dest%d[j%d]._length = length%d;\n",
                loop_index-1, loop_index-1, loop_index);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    dest%d[j%d]._maximum = (uint32_t)(%s)%s.max_size();\n",
                loop_index-1, loop_index-1, from, idl_seqIndex(loop_index));
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    dest%d[j%d]._buffer = dest%d;\n",
                loop_index-1, loop_index-1, loop_index);
        idl_printIndent (indent);
        idl_fileOutPrintf (idl_fileCur(), "    dest%d[j%d]._release = FALSE;\n",
                loop_index-1, loop_index-1);

        os_free(scopedName);
        break;
    default:
        assert (0);
        break;
    }
    indent--;
    idl_printIndent (indent);
    idl_fileOutPrintf (idl_fileCur(), "    }\n");
    idl_printIndent (indent);
    idl_fileOutPrintf (idl_fileCur(), "}\n");
    os_free(tmp_string);
}

/** @brief Function that set up the sequence copy context for a typedef.
 *
 * Generate code to setup the sequence copy context for a typedef.
 *
 * @todo Because it is only used by a typedef it would be more clear
 * to integrate it with the typedef. If it can be used for more contexts
 * the others should be removed and call this function.
 *
 * @param name Specifies the name of the type
 * @param typeSeq Specifies the type of the sequence
 * @param indent Sequence recursion level
 */
static void
idl_seqElements (
    const char *name,
    idl_typeDef typeDef,
    c_long indent,
    void *userData)
{
    c_char buffer[256];
    c_char *scopedName;
    idl_typeSeq typeSeq;
    idl_typeSpec nextType;

    OS_UNUSED_ARG(indent);

    typeSeq = idl_typeSeq(idl_typeDefActual(typeDef));
    nextType = idl_typeSeqType(idl_typeSeq(typeSeq));
    scopedName = idl_scopedLiteTypeName(nextType);

    IDL_PRINTLINE (indent);
    idl_fileOutPrintf (idl_fileCur(), "    {\n");
    idl_fileOutPrintf (idl_fileCur(), "        const %s *src = from;\n", name);

    idl_fileOutPrintf (idl_fileCur(), "        %s *dest0;\n", scopedName);
    idl_fileOutPrintf (idl_fileCur(), "        uint32_t length0;\n\n");
    idl_fileOutPrintf (idl_fileCur(), "        length0 = (uint32_t)(*src).size();\n");
    idl_fileOutPrintf (idl_fileCur(), "        dest0 = %s;\n",
            idl_seqAllocBuffer(typeSeq, "length0", buffer, sizeof(buffer)));
    idl_seqLoopCopy (nextType, "*src", "dest0", 1, 2, userData);
    idl_fileOutPrintf (idl_fileCur(), "        to->_maximum = (uint32_t)(*src).max_size();\n");
    idl_fileOutPrintf (idl_fileCur(), "        to->_length  = length0;\n");
    idl_fileOutPrintf (idl_fileCur(), "        to->_buffer  = dest0;\n");
    idl_fileOutPrintf (idl_fileCur(), "        to->_release = false;\n");

    idl_fileOutPrintf (idl_fileCur(), "    }\n");

    os_free(scopedName);
}

/** @brief callback function called on definition of a named type in the IDL input file.
 *
 * Generate code for the following IDL construct:
 * @verbatim
   =>   typedef <type-name> <name>;
   @endverbatim
 *
 * For typedef's the action to copy the data is dependend on the actual type.
 * - If the actual type is \b idl_tstruct or \b idl_tunion, a named copy routines
 *   is generated. The copyIn routines calls the copyIn routine of the struct or union.
 * - If the actual type is \b idl_tarray, a named copyIn routine is generated.
 *   For that copyIn routine, array copy code is generated.
 * - If the actual type is \b idl_tseq, a named copyIn routine is generated.
 *   For that copyIn routine, sequence copy code is generated.
 *
 * Type definitions of basic type are immediately copied from within the generated
 * struct or union copyIn routine. No named copy routine is required.
 *
 * @param scope Current scope
 * @param name Specifies the name of the type
 * @param defSpec Specifies the type of the named type
 */
static void
idl_typedefOpenClose (
    idl_scope scope,
    const char *name,
    idl_typeDef defSpec,
    void *userData)
{
    c_char *scopedTypeName = idl_scopedTypeName(idl_typeSpec(defSpec));
	c_char *scopedCxxTypeName = idl_ISOCxx2TypeFromTypeSpec(idl_typeSpec(defSpec));
    idl_typeSpec targetType = idl_typeDefActual(defSpec);
	c_char *scopedCxxTargetName = idl_ISOCxx2TypeFromTypeSpec(targetType);
    c_char *scopedTargetName = idl_scopedTypeName(targetType);

    OS_UNUSED_ARG(name);

    switch (idl_typeSpecType(idl_typeDefActual(defSpec))) {
    case idl_tstruct:
    case idl_tunion:
        idl_fileOutPrintf (idl_fileCur(), "void\n");
        idl_fileOutPrintf (idl_fileCur(), "__%s__copyIn(\n", scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "    const void *from,\n");
        idl_fileOutPrintf (idl_fileCur(), "    void *to)\n");
        idl_fileOutPrintf (idl_fileCur(), "{\n");
        idl_fileOutPrintf (idl_fileCur(), "    extern void __%s__copyIn(const void *, void *);\n", scopedTargetName);
        idl_fileOutPrintf (idl_fileCur(), "    __%s__copyIn(from, to);\n", scopedTargetName);
        idl_fileOutPrintf (idl_fileCur(), "}\n");
        idl_fileOutPrintf (idl_fileCur(), "\n");
        break;
    case idl_tarray:
        idl_fileOutPrintf (idl_fileCur(), "void\n");
        idl_fileOutPrintf (idl_fileCur(), "__%s__copyIn(\n", scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "    const %s *from,\n", scopedCxxTypeName);
        idl_fileOutPrintf (idl_fileCur(), "    %s *to)\n", scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "{\n");
        idl_arrayElements (scope, idl_typeArray(idl_typeDefActual(defSpec)), "from", "to", TRUE, 0, userData);
        idl_fileOutPrintf (idl_fileCur(), "}\n");
        idl_fileOutPrintf (idl_fileCur(), "\n");
        break;
    case idl_tseq:
        idl_fileOutPrintf (idl_fileCur(), "void\n");
        idl_fileOutPrintf (idl_fileCur(), "__%s__copyIn(\n", scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "    const %s *from,\n", scopedCxxTypeName);
        idl_fileOutPrintf (idl_fileCur(), "    %s *to)\n", scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "{\n");
        idl_seqElements (scopedCxxTypeName, defSpec, 0, userData);
        idl_fileOutPrintf (idl_fileCur(), "}\n");
        idl_fileOutPrintf (idl_fileCur(), "\n");
        break;
    default:
        break;
    }
    os_free(scopedTargetName);
    os_free(scopedCxxTargetName);
    os_free(scopedCxxTypeName);
    os_free(scopedTypeName);
}

static idl_action
idl_unionOpen (
    idl_scope scope,
    const char *name,
    idl_typeUnion defSpec,
    void *userData)
{
    c_char *scopedCxxTypeName = idl_ISOCxx2TypeFromTypeSpec(idl_typeSpec(defSpec));
    c_char *scopedTypeName = idl_scopedTypeName(idl_typeSpec(defSpec));
    c_char *unionTypeName = NULL;

    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    /* Generate function header. */
    idl_fileOutPrintf (idl_fileCur(), "void\n");
    idl_fileOutPrintf (idl_fileCur(), "__%s__copyIn(\n", scopedTypeName);
    idl_fileOutPrintf (idl_fileCur(), "    const void *_from,\n");
    idl_fileOutPrintf (idl_fileCur(), "    void *_to)\n");
    idl_fileOutPrintf (idl_fileCur(), "{\n");
    idl_fileOutPrintf (idl_fileCur(), "    const class %s *from = (const class %s *)_from;\n",
    		scopedCxxTypeName, scopedCxxTypeName);
    idl_fileOutPrintf (idl_fileCur(), "    %s *to = (%s *)_to;\n\n",
    		scopedTypeName, scopedTypeName);

    unionTypeName = idl_scopedLiteTypeName(idl_typeUnionSwitchKind(defSpec));
	idl_fileOutPrintf (idl_fileCur(), "    to->_d = (%s)from->_d();\n", unionTypeName);

    idl_fileOutPrintf (idl_fileCur(), "    switch (to->_d) {\n");

    os_free(unionTypeName);
    os_free(scopedTypeName);
    os_free(scopedCxxTypeName);

    return idl_explore;
}

static void
idl_unionClose (
    const char *name,
    void *userData)
{
    OS_UNUSED_ARG(name);
    OS_UNUSED_ARG(userData);

    idl_fileOutPrintf (idl_fileCur(), "    }\n");
    idl_fileOutPrintf (idl_fileCur(), "}\n");
    idl_fileOutPrintf (idl_fileCur(), "\n");

    //caseIndex = -1; // don't know if i need this one yet!
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
    c_ulong maxlen;

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
        idl_fileOutPrintf(idl_fileCur(), "        %s%s = (%s)%s%s();\n",
            to_id,
            cxxIdName,
            cxxTypeName,
            from_id,
            cxxIdName);
    break;
    case idl_string:
        maxlen = idl_typeBasicMaxlen(typeBasic);
        if (maxlen == 0) {
            idl_fileOutPrintf(idl_fileCur(), "        %s%s = (char *) %s%s().c_str();\n",
                to_id,
                cxxIdName,
                from_id,
                cxxIdName);
        } else {
            idl_fileOutPrintf(idl_fileCur(), "    strncpy (%s%s, %s%s().c_str(), %d);\n",
                    to_id,
                    cxxIdName,
                    from_id,
                    cxxIdName,
                    maxlen + 1);
        }
    break;
    }
}

static void
idl_unionCaseArray(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *src, *dest;

    OS_UNUSED_ARG(userData);

    (void)os_asprintf(&src, "from->%s()", name);
    (void)os_asprintf(&dest, "to->_u.%s", name);

    varIndex = 0;
    idl_fileOutPrintf(idl_fileCur(), "    {\n");
    idl_arrayElements(scope, idl_typeArray(typeSpec), src, dest, OS_FALSE, loopIndent, userData);
    idl_fileOutPrintf(idl_fileCur(), "    }\n");

    os_free(dest);
    os_free(src);
}

static void
idl_unionCaseSequence(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *memberName, *scopedTypeName;
    c_char *cxxSeqTypeName, *scopedCxxSeqTypeName;
    c_char buf[256];
    idl_typeSpec seqTypeSpec;

    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(userData);

    seqTypeSpec = idl_typeSeqType(idl_typeSeq(typeSpec));
    scopedTypeName = idl_scopedLiteTypeName(seqTypeSpec);
    (void)os_asprintf(&cxxSeqTypeName, "_%s_seq", name);
    scopedCxxSeqTypeName = idl_scopeStack (idl_typeUserScope(idl_typeUser(typeSpec)),"::",cxxSeqTypeName);
    memberName = idl_ISOCxx2Id(name);

    idl_fileOutPrintf (idl_fileCur(), "    {\n");
    idl_fileOutPrintf (idl_fileCur(), "        const %s *src = &from->%s();\n", scopedCxxSeqTypeName, memberName);
    idl_fileOutPrintf (idl_fileCur(), "        to->_u.%s._maximum = (uint32_t)(*src).max_size();\n", memberName);
    idl_fileOutPrintf (idl_fileCur(), "        to->_u.%s._release = false;\n", memberName);

    if (((idl_typeSpecType(seqTypeSpec) == idl_tbasic) &&
         (idl_typeBasicType(idl_typeBasic(seqTypeSpec)) != idl_string)) ||
        (idl_typeSpecType(seqTypeSpec) == idl_tenum))
    {
        idl_fileOutPrintf (idl_fileCur(), "        to->_u.%s._length = (uint32_t)(*src).size();\n", memberName);
        idl_fileOutPrintf (idl_fileCur(), "        to->_u.%s._buffer = (uint8_t *)&((*src)[0]);\n", memberName);
    } else {
        idl_fileOutPrintf (idl_fileCur(), "        uint32_t length0;\n\n");
        idl_fileOutPrintf (idl_fileCur(), "        %s *dest0;\n", scopedTypeName);
        idl_fileOutPrintf (idl_fileCur(), "        length0 = (uint32_t)(*src).size();\n");
        idl_fileOutPrintf (idl_fileCur(), "        dest0 = %s;\n",
             idl_seqAllocBuffer(idl_typeSeq(typeSpec), "length0", buf, sizeof(buf)));
        idl_seqLoopCopy (seqTypeSpec, "*src", "dest0", 1, 2, userData);
        idl_fileOutPrintf (idl_fileCur(), "        to->_u.%s._length = length0;\n", memberName);
        idl_fileOutPrintf (idl_fileCur(), "        to->_u.%s._buffer = (uint8_t *)dest0;\n", memberName);
    }
    idl_fileOutPrintf (idl_fileCur(), "    }\n");

    os_free(scopedTypeName);
    os_free(scopedCxxSeqTypeName);
    os_free(cxxSeqTypeName);
    os_free(memberName);
}

static void
idl_unionCaseType(
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *memberName, *scopedTypeName, *scopedCxxTypeName;

    OS_UNUSED_ARG(scope);
    OS_UNUSED_ARG(userData);

    memberName = idl_ISOCxx2Id(name);
    scopedTypeName = idl_scopedTypeName(typeSpec);
    scopedCxxTypeName = idl_ISOCxx2TypeFromTypeSpec(typeSpec);

    if (idl_typeSpecType(typeSpec) == idl_ttypedef) {
        idl_fileOutPrintf (idl_fileCur(), "        extern void __%s__copyIn(const %s *, %s *);\n",
        		scopedTypeName,
                scopedCxxTypeName,
                scopedTypeName);
    } else {
        idl_fileOutPrintf (idl_fileCur(), "        extern void __%s__copyIn(const void *, void *);\n",
        		scopedTypeName);
    }

    idl_fileOutPrintf (idl_fileCur(), "        __%s__copyIn(&from->%s(), &to->_u.%s);\n",
        scopedTypeName, memberName, memberName);

    os_free(scopedCxxTypeName);
    os_free(memberName);
    os_free(scopedTypeName);
}

static void
idl_unionCaseOpenClose (
    idl_scope scope,
    const char *name,
    idl_typeSpec typeSpec,
    void *userData)
{
    c_char *memberName, *scopedName;

    memberName = idl_ISOCxx2Id(name);
    scopedName = idl_scopedTypeName(typeSpec);

    /* QAC EXPECT 3416; No side effect here */
    if (idl_typeSpecType(typeSpec) == idl_tbasic) {
        /* QAC EXPECT 3416; No side effect here */
        idl_unionCaseBasic(scope, memberName, idl_typeBasic(typeSpec), "from->", "to->_u.");
        idl_fileOutPrintf(idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_ttypedef) {
        if (idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tarray ||
            idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tseq ||
            idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tstruct ||
            idl_typeSpecType(idl_typeDefRefered(idl_typeDef(typeSpec))) == idl_tunion)
        {
            idl_unionCaseType(scope, name, typeSpec, userData);
            idl_fileOutPrintf(idl_fileCur(), "    break;\n");
        } else {
            /* Calls itself for the actual type in case of typedef */
            /* QAC EXPECT 3670; Recursive calls is a good practice, the recursion depth is limited here */
            idl_unionCaseOpenClose (
                scope,
                name,
                idl_typeDefRefered(idl_typeDef(typeSpec)),
                userData);
            /* Compensate for recursion, where caseIndex will now be incremented twice. */
        }
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tenum) {
        idl_fileOutPrintf(idl_fileCur(), "        to->_u.%s = (%s)from->%s();\n",
            memberName, scopedName, memberName);
        idl_fileOutPrintf(idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tstruct ||
               idl_typeSpecType(typeSpec) == idl_tunion)
    {
        idl_unionCaseType(scope, name, typeSpec, userData);
        idl_fileOutPrintf(idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tarray) {
    	loopIndent++;
        idl_unionCaseArray(scope, name, typeSpec, userData);
        loopIndent--;
        idl_fileOutPrintf(idl_fileCur(), "    break;\n");
        /* QAC EXPECT 3416; No side effect here */
    } else if (idl_typeSpecType(typeSpec) == idl_tseq) {
        idl_unionCaseSequence(scope, name, typeSpec, userData);
        idl_fileOutPrintf(idl_fileCur(), "    break;\n");
    } else {
        /* Do nothing, only to prevent dangling else-ifs QAC reports */
    }
    /* QAC EXPECT 5101, 5103: Complexity is limited, by independent cases, per case the number of lines is lower  */

    os_free(scopedName);
    os_free(memberName);
}

static c_char *
idl_valueFromLabelVal(
    idl_labelVal labelVal)
{
    static c_char labelName [1000];

    /* QAC EXPECT 3416; No side effect here */
    if (idl_labelValType(idl_labelVal(labelVal)) == idl_lenum) {
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
                snprintf(labelName, sizeof(labelName), "TRUE");
            } else {
                snprintf(labelName, sizeof(labelName), "FALSE");
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
        idl_fileOutPrintf(idl_fileCur(), "    case %s:\n", idl_valueFromLabelVal(labelVal));
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

/** @brief return the program control structure for the CORBA C++ CopyIn generation functions.
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
idl_genLiteISOCxxCopyin = {
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
idl_genLiteISOCxxCopyinProgram (
    void)
{
    return &idl_genLiteISOCxxCopyin;
}
