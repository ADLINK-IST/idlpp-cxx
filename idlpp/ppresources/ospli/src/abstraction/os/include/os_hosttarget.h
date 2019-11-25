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
#ifndef OS_HOSTTARGET_H
#define OS_HOSTTARGET_H
#include "os_macrostringify.h"

#ifdef OSPL_HOST
#define OSPL_HOST_STR OSPL_STRINGIFY(OSPL_HOST)
#else
#define OSPL_HOST_STR ""
#endif

#ifdef OSPL_TARGET
#define OSPL_TARGET_STR OSPL_STRINGIFY(OSPL_TARGET)
#else
#define OSPL_TARGET_STR ""
#endif

#endif
