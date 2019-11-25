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
#ifndef OS_LINUX_DEFS_H
#define OS_LINUX_DEFS_H

#if defined (__cplusplus)
extern "C" {
#endif

#include <../linux/include/os_os_abstract.h>
#include "os_os_types.h"

#include <../linux/include/os_os_alloca.h>
#include <../posix/include/os_os_mutex.h>
#include <../posix/include/os_os_rwlock.h>
#include <../posix/include/os_os_cond.h>
#include <../posix/include/os_os_thread.h>
#include <../posix/include/os_os_semaphore.h>
#include <../linux/include/os_os_stdlib.h>
#include <../linux/include/os_os_process.h>
#include <../linux/include/os_os_if.h>
#include <../linux/include/os_os_utsname.h>

#define OS_SOCKET_USE_FCNTL 1
#define OS_SOCKET_USE_IOCTL 0
#define OS_HAS_UCONTEXT_T

#ifdef OS_ELINOS42
#define OSPL_STACK_MAX 2097152
#endif




#if defined (__cplusplus)
}
#endif

#endif /* OS_LINUX_DEFS_H */

