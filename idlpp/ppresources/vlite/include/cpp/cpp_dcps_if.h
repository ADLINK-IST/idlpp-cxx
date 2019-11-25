/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2017 ADLINK
 *   Technology Limited, its affiliated companies and licensors. 
 *   All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifdef OS_API
#undef OS_API
#endif

#ifdef _WIN32
#ifndef OS_API_EXPORT
#define OS_API_EXPORT __declspec(dllexport)
#endif
#ifndef OS_API_IMPORT
#define OS_API_IMPORT __declspec(dllimport)
#endif
#else
#define OS_API_EXPORT
#define OS_API_IMPORT
#endif

#ifdef _WIN32
#ifdef LITE_BUILD_DCPSCPP
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
#else
#define OS_API
#endif
