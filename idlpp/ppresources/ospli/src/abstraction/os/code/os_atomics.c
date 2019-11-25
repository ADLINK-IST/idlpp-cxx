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

#define PA_HAVE_INLINE 0 /* override automatic determination of inlining */
#define PA_INLINE        /* no "inline" in function defs (not really needed) */
#define PA_ATOMICS_OMIT_FUNCTIONS 0 /* force inclusion of functions defs */

#if defined(__arm__) && defined(__freertos__) && defined(__GNUC__)
/* __sync_synchronized (required by Xilinx 2017.3) is provided by GCC, but
   only for Linux targets. See https://gcc.gnu.org/wiki/Atomic. */
#include "os_atomics.h"
void __sync_synchronize(void) { pa_fence(); }
#endif

#include "os_atomics.h"
