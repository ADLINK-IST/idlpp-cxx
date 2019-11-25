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
#ifndef IDL_GENCORBACXXHELPER_H
#define IDL_GENCORBACXXHELPER_H

#include "idl_program.h"
#include "c_metabase.h"
#include "c_iterator.h"

struct CxxTypeUserData_s {
    os_iter idlpp_metaList;
    os_boolean no_type_caching;
    c_iter typeStack;
};

typedef struct CxxTypeUserData_s CxxTypeUserData;

typedef struct {
    c_type type;
    c_char *descriptor;
    c_ulong nrElements;
    size_t descriptorLength;
} idl_metaCxx;

idl_metaCxx *
idl_metaCxxNew(c_type type, c_char *descriptor);

void
idl_metaCxxSerialize2XML(
        void *_metaElmnt,
        void *args);

void idl_metaCxxAddType(
        idl_scope scope,
        const char *name,
        idl_typeSpec typeSpec,
        os_iter *metaList);

idl_program idl_genCorbaCxxHelperProgram (void);

#endif /* IDL_GENCORBACXXHELPER_H */
