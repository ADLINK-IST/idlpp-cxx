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
 * Initialization / Deinitialization                            *
 ****************************************************************/

/** \file os/code/os_init.c
 *  \brief Initialization / Deinitialization
 *
 * Initialization / Deinitialization provides routines for
 * initializing the OS layer claiming required resources
 * and routines to deinitialize the OS layer, releasing
 * all resources still claimed.
 */

#include "os_init.h"
#include "os_version.h"

/* include OS specific initialization implementation 		*/
#include "code/os_init.c"

#ifndef LITE // LITE-1270 - Compiles for the OS specific include
const char *
os_versionString(void)
{
    return OSPL_VERSION_STR;
}
#endif // LITE-1270
