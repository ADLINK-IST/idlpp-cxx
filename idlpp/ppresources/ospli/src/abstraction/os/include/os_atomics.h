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

#ifndef PA_ATOMICS_H
#define PA_ATOMICS_H

#include <stddef.h>
#include <limits.h>

#include "os_if.h"
#include "os_defs.h"
#include "os_abstract.h"
#include "os_inline.h"

#if defined (__cplusplus)
extern "C" {
#endif

/* Note: os_atomics_inlines.c overrules PA_HAVE_INLINE, PA_INLINE and
   PA_ATOMICS_OMIT_FUNCTIONS */

#if ! PA_HAVE_INLINE && ! defined PA_ATOMICS_OMIT_FUNCTIONS
#define PA_ATOMICS_OMIT_FUNCTIONS 1
#endif

#if ! PA_ATOMIC_SUPPORT && (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) >= 40100
#include "os_atomics_gcc.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined _WIN32
/* Windows.h causes HUGE problems when included too early, primarily
   because you can't include only a subset and later include the rest
*/
#undef PA_HAVE_INLINE
#undef PA_INLINE
#define PA_INLINE
#include "os_atomics_win32.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined __sun
#include "os_atomics_solaris.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined __INTEGRITY
#include "os_atomics_integrity.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined _VX_CPU_FAMILY
#include "os_atomics_vxworks.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined __GNUC__ && defined __i386
#include "os_atomics_gcc_x86.h"
#endif

#if ! PA_ATOMIC_SUPPORT &&                                              \
  ((defined __GNUC__ && defined __ppc) ||                               \
   (defined __vxworks && defined __PPC__))
/* VxWorks uses GCC but removed the __GNUC__ macro ... */
#include "os_atomics_gcc_ppc.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined __GNUC__ && defined __sparc__
#include "os_atomics_gcc_sparc.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined __GNUC__ && defined __arm__
#include "os_atomics_gcc_arm.h"
#endif

#if ! PA_ATOMIC_SUPPORT && defined __IAR_SYSTEMS_ICC__ && defined __ICCARM__
#include "os_atomics_iar_arm.h"
#endif

#if ! PA_ATOMIC_SUPPORT
#error "No support for atomic operations on this platform"
#endif

#if defined (__cplusplus)
}
#endif

#endif /* PA_ATOMICS_H */
