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

#ifndef PA_WIN32_ABSTRACT_H
#define PA_WIN32_ABSTRACT_H

#ifdef __BIG_ENDIAN
#define PA__BIG_ENDIAN
#else
#define PA__LITTLE_ENDIAN
#endif

#ifdef _WIN64
#define PA__64BIT
#endif

#include "os_formatspec_win32_win64.h" /* common printf format specifiers */

#endif /* PA_WIN32_ABSTRACT_H */
