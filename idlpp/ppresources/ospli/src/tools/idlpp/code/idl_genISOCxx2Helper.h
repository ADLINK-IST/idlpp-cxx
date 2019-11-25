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
#ifndef IDL_GENISOCXX2HELPER_H
#define IDL_GENISOCXX2HELPER_H

#include "c_typebase.h"

#include "idl_scope.h"
#include "idl_program.h"

c_char *idl_ISOCxx2Id(const char *identifier);

c_char *idl_scopeStackISOCxx2(idl_scope scope, const char *scopeSepp, const char *name);

c_char *idl_ISOCxx2TypeFromTypeSpec(idl_typeSpec typeSpec);

c_char *idl_ISOCxx2TypeFromCType(c_type t);

c_char *idl_ISOCxx2DefaultValueFromCType(c_type t);

c_char *idl_ISOCxx2ValueFromCValue(c_type t, c_value v);

c_char *idl_ISOCxx2InTypeFromCType(c_type t);

c_bool idl_ISOCxx2IsRefType(c_type t);

c_value idl_ISOCxx2LowestUnionDefaultValue(c_type t);

#endif /* IDL_GENISOCXX2HELPER_H */
