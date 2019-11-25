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

/** \file os/common/code/os_time.c
 *  \brief Time management
 *
 * Implements posix based time management functions
 */

#include <time.h>

/** \brief Translate calendar time into readable string representation
 */
os_size_t
os_ctime_r (
    os_time *t,
    char *buf,
    os_size_t bufsz)
{
    os_size_t result = 0;
    time_t tt = t->tv_sec;

    assert(bufsz >= OS_CTIME_R_BUFSIZE);

    if (buf) {
        /* This should be common code. But unfortunately, VS2012 C Runtime contains
         * a bug that causes a crash when using %Z with a buffer that is too small:
         * https://connect.microsoft.com/VisualStudio/feedback/details/782889/
         * So, don't execute strftime with %Z when VS2012 is the compiler. */
#if !(_MSC_VER == 1700)
        result = strftime(buf, bufsz, "%a %b %d %H:%M:%S %Z %Y", localtime(&tt));
#endif

        if(result == 0) {
            /* If not enough room was available, the %Z (time-zone) is left out
             * resulting in the output as expected from ctime_r. */
            result = strftime(buf, bufsz, "%a %b %d %H:%M:%S %Y", localtime(&tt));
            assert(result);
        }
    }
    return result;
}
