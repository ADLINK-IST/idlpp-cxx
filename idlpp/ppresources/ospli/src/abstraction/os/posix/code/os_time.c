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

/** \file os/posix/code/os_time.c
 *  \brief Time management
 *
 * Implements posix based time management functions
 */

#include <time.h>
#include "os_errno.h"

/*  \brief Get the current time
 */
static os_time
os__timeDefaultTimeGet(void)
{
    struct timespec t;
    os_time rt;

    /* POSIX specifies that all implementations of clock_gettime(...)
     * support the system-wide real-time clock, which is identified
     * by CLOCK_REALTIME, so the result of the call below can safely
     * be ignored. */
    (void) clock_gettime (CLOCK_REALTIME, &t);

    rt.tv_sec = t.tv_sec;
    rt.tv_nsec = t.tv_nsec;

    return rt;
}

/** \brief Suspend the execution of the calling thread for the specified time
 *
 * \b os_nanoSleep suspends the calling thread for the required
 * time by calling \b nanosleep. First it converts the \b delay in
 * \b os_time definition into a time in \b struct \b timeval definition.
 * In case the \b nanosleep is interrupted, the call is re-entered with
 * the remaining time.
 */
os_result
os_nanoSleep (
    os_time delay)
{
    struct timespec t;
    struct timespec r;
    int result;
    os_result rv;

    if( delay.tv_sec >= 0 && delay.tv_nsec >= 0) {
        /* Time should be normalized */
        assert (delay.tv_nsec < 1000000000);
        t.tv_sec = delay.tv_sec;
        t.tv_nsec = delay.tv_nsec;
        result = nanosleep (&t, &r);
        while (result && os_getErrno() == EINTR) {
            t = r;
            result = nanosleep (&t, &r);
        }
        if (result == 0) {
            rv = os_resultSuccess;
        } else {
            rv = os_resultFail;
        }
    } else {
        rv = os_resultFail;
    }
    return rv;
}
