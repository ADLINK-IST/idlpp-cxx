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

/** \file os/linux/code/os_rwlock.c
 *  \brief Linux multiple reader writer lock
 *
 * Implements multiple reader writer lock for Linux
 * by including the POSIX implementation
 */

#include <os_defs.h>
#include "os_rwlock.h"
#include "os_mutex.h"

#include "../posix/code/os_rwlock.c"
#include "../common/code/os_rwlock_attr.c"

