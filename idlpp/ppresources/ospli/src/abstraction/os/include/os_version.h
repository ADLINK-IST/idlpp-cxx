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
#ifndef OS_VERSION_H
#define OS_VERSION_H

#include "os_macrostringify.h"

#ifndef OSPL_VERSION
#error OSPL_VERSION must be defined.
#endif

#define OSPL_VERSION_STR OSPL_STRINGIFY(OSPL_VERSION)

#endif
