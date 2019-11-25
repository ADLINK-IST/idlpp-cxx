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
/****************************************************************
 * Interface definition for semaphores                          *
 ****************************************************************/

/** \file os_semaphore.h
 *  \brief Thread synchronisation - semaphores
 */

#ifndef OS_SEMAPHORE_H
#define OS_SEMAPHORE_H

#include "os_defs.h"

#if defined (__cplusplus)
extern "C" {
#endif

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif

OS_API os_result os_sem_init (os_sem_t * sem, os_uint32 value);
OS_API os_result os_sem_destroy (os_sem_t * sem);
OS_API os_result os_sem_post (os_sem_t * sem);
OS_API os_result os_sem_wait (os_sem_t * sem);

#undef OS_API
#if defined (__cplusplus)
}
#endif
#endif /* OS_SEMAPHORE_H */
