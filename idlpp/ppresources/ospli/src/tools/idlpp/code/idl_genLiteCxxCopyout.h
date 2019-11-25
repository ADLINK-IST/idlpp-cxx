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
#ifndef IDL_GENLITECXXCOPYOUT_H
#define IDL_GENLITECXXCOPYOUT_H

#include "idl_program.h"

typedef struct idl_lite_copyout_args {
    c_bool top_level;
} idl_lite_copyout_args;


idl_program idl_genLiteCxxCopyoutProgram (void);

#endif /* IDL_GENLITECXXCOPYOUT_H */
