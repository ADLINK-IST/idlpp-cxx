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

/** \file os/darwin/code/os_sharedmem.c
 *  \brief Darwin shared memory management
 *
 * Implements shared memory management for Darwin by
 * including the POSIX, SVR4 and heap implementation
 */

#include <assert.h>

#include "os_defs.h"

#include <../posix/code/os_sharedmem_file.c>
#include <../svr4/code/os_sharedmem_seg.c>
#include <../common/code/os_sharedmem_heap.c>

/* Darwin sigismember, sigaddset, &c. has issues */
OSPL_DIAG_OFF(sign-conversion)
#include <../common/code/os_sharedmem.c>
OSPL_DIAG_ON(sign-conversion)

void
os_sharedAttrInit (
    os_sharedAttr *sharedAttr)
{
    assert (sharedAttr != NULL);
    sharedAttr->lockPolicy = OS_LOCK_DEFAULT;
    sharedAttr->sharedImpl = OS_MAP_ON_SEG;
    /*sharedAttr->sharedImpl = OS_MAP_ON_FILE;*/
    sharedAttr->userCred.uid = 0;
    sharedAttr->userCred.gid = 0;
    /*sharedAttr->map_address = (void *)0x300000000;*/
#ifdef __x86_64__
    sharedAttr->map_address = (void *) 0x100000000000ll;
#else
    sharedAttr->map_address = (void *)0x60000000;
#endif
}
