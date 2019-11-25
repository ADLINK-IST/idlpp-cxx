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
#pragma once

#if defined(LITE) && !defined(OS__SYNC_NOSHARED)
# define OS__SYNC_NO_SHARED 1
#endif

#include "os_sync.h"

#if defined (__cplusplus)
extern "C" {
#endif

typedef struct os_os_cond_s {
    os_syncCond cond;
    os_scopeAttr scope;
#ifndef NDEBUG
    UINT32 signature; /* Set to OS__COND_SIG if initialised */
#endif
} os_os_cond;

#if defined (__cplusplus)
}
#endif
