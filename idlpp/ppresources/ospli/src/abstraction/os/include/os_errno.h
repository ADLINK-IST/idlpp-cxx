/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2013 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef OS_ERRNO_H
#define OS_ERRNO_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "os_defs.h"

#if (defined(WIN32) || defined(WINCE))
#include <winerror.h>
#elif (defined(LWIP_SOCKET) && defined(LWIP_PROVIDE_ERRNO))
#include <lwip/errno.h>
#endif

#include <errno.h> /* Required on Windows platforms too */

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif

#if !defined(EINVAL)
#define EINVAL (22)
#endif /* EINVAL */

/** \brief Get error code set by last operation that failed
 *
 * @return Error code
 */
OS_API os_int
os_getErrno (
    void);

/** \brief Set error code to specified value
 *
 * @return void
 * @param err Error code
 */
OS_API void
os_setErrno (
    os_int err);

/**
 * \brief Get string representation for specified error code
 *
 * @return Pointer to string allocated in thread specific memory
 * @param err Error number
 */
OS_API const os_char *
os_strError (
    os_int err);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* OS_ERRNO_H */
