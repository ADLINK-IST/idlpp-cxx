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
#ifndef OS_DARWIN_DEFS_H
#define OS_DARWIN_DEFS_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "os_os_abstract.h"
#include "os_os_types.h"

#include "os_os_alloca.h"
#include "os_os_mutex.h"
#include "os_os_rwlock.h"
#include "os_os_cond.h"
#include "os_os_thread.h"
#include "os_os_semaphore.h"
#include "os_os_stdlib.h"
#include "os_os_process.h"
#include "os_os_if.h"
#include "os_os_utsname.h"

#define OS_SOCKET_USE_FCNTL 1
#define OS_SOCKET_USE_IOCTL 0
#define OS_HAS_UCONTEXT_T
#define OS_HAS_TSD_USING_THREAD_KEYWORD 1

#if defined (__cplusplus)
}
#endif

#endif /* OS_DARWIN_DEFS_H */

