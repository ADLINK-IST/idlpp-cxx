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

#ifndef OS_DARWIN_RWLOCK_H
#define OS_DARWIN_RWLOCK_H

#if defined (__cplusplus)
extern "C" {
#endif

/* Here we use <> instead of "" because we want to include
 * the top level header file and not the local one.*/
#include "os_os_mutex.h"

typedef os_os_mutex os_os_rwlock;

#if defined (__cplusplus)
}
#endif

#endif /* OS_DARWIN_RWLOCK_H */
