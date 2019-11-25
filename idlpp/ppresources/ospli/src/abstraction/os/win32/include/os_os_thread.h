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

#ifndef OS_WIN32_THREAD_H
#define OS_WIN32_THREAD_H


#if defined (__cplusplus)
extern "C" {
#endif

typedef unsigned long DWORD;
typedef void * HANDLE;

typedef struct os_threadInfo_s
{
    DWORD threadId;
    HANDLE handle;
} os_threadInfo;

typedef os_threadInfo os_os_threadId;

OS_API extern os_os_threadId id_none;

#define OS_THREAD_ID_NONE id_none


#if defined (__cplusplus)
}
#endif

#endif /* OS_WIN32_THREAD_H */
