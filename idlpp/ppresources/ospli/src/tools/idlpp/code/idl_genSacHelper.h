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
#ifndef IDL_GENSACHELPER_H
#define IDL_GENSACHELPER_H

#include "c_typebase.h"

#include "idl_program.h"

c_char *idl_scopedSacTypeIdent (const idl_typeSpec typeSpec);

c_char *idl_sacTypeFromTypeSpec (const idl_typeSpec typeSpec);

char *idl_sequenceElementIdent (const idl_typeSpec typeSpec);

char *idl_sequenceIdent (const idl_typeSeq typeSeq);

char *idl_sequenceIdentScoped (const idl_scope scope, const idl_typeSeq typeSeq);

c_bool idl_sequenceSupportFunctionsExist (const idl_scope scope,
                                          const idl_typeSeq typeSeq, const char *elementName);

#endif /* IDL_GENSACHELPER_H */
