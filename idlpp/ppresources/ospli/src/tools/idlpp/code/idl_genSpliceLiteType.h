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
#ifndef IDL_GENSPLICELITETYPE_H
#define IDL_GENSPLICELITETYPE_H

#include "idl_program.h"

idl_program idl_genSpliceLiteTypeProgram (void);

void
idl_genSpliceLiteTypeSetTestMode (
    c_bool val);

void
idl_genSpliceLiteTypeSetIncludeFileName (
    os_char* val);

void
idl_genSpliceLiteTypeUseVoidPtrs (
    c_bool val);

#endif /* IDL_GENSPLICELITETYPE_H */
