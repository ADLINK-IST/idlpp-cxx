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
#ifndef OS_WIN32_INCS_H
#define OS_WIN32_INCS_H

#if defined (__cplusplus)
extern "C" {
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#if defined(_WIN32_WINNT) && _WIN32_WINNT < 0x0502
/* Minimum Windows Server 2003 SP1, Windows XP SP2 == _WIN32_WINNT_WS03 (0x0502) */
#error _WIN32_WINNT should be at least _WIN32_WINNT_WS03 (0x0502)
#endif

#include <winsock2.h>
#include <Windows.h>
#include <iphlpapi.h>

#if defined (__cplusplus)
}
#endif

#endif /* OS_WIN32_INCS_H */
