/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2013 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

/* Make sure we get the XSI compliant version of strerror_r */
#undef _POSIX_C_SOURCE
#undef _XOPEN_SOURCE
#undef _GNU_SOURCE
#define _POSIX_C_SOURCE 200112L

#include <string.h>

#include "os_defs.h"
#include "os_errno.h"
#include "os_stdlib.h"
#include "os_thread.h"

#include "os_errno.h"
#include "../common/include/os_errno.h"

os_int
os_getErrno (void)
{
    return errno;
}

void
os_setErrno (os_int err)
{
    errno = err;
}

os_int
os_strerror_r (os_int err, os_char *str, os_size_t len)
{
    return strerror_r(err, str, len);
}
