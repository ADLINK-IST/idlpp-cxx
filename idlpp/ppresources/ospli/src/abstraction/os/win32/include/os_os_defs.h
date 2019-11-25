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
#ifndef OS_WIN32_DEFS_H
#define OS_WIN32_DEFS_H

// Suppress spurious 'child' : inherits 'parent::member' via dominance warnings
#if defined (_MSC_VER)
    #pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__cplusplus)
extern "C" {
#endif

#define OS_SOCKET_USE_FCNTL 0
#define OS_SOCKET_USE_IOCTL 1
#define OS_HAS_UCONTEXT_T

#include "os_os_abstract.h"
#include "os_os_types.h"
#include "os_os_if.h"

#include "os_os_alloca.h"
#include "os_os_mutex.h"
#include "os_os_cond.h"
#include "os_os_thread.h"
#include "os_os_semaphore.h"
#include "os_os_stdlib.h"
#include "os_os_process.h"
#include "os_os_utsname.h"

#include "os_os_rwlock.h"

#if defined (__cplusplus)
}
#endif

#undef OS_API

#endif /* OS_WIN32_DEFS_H */
