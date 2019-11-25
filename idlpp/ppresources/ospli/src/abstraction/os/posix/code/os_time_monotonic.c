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
#include "os_defs.h"

/** \brief Get high resolution, monotonic time.
 *
 * Sufficiently recent versions of GNU libc and the Linux kernel support
 * monotonic clocks. In case monotonic clocks are NOT supported the 
 * real-time clock is used as fallback. This ensures that the products
 * still works as long as no time jumps occur.
 *
 * \return high resolution, monotonic time if monotonic clocks are supported.
 * \return real-time, otherwise
 */
os_time
os_timeGetMonotonic (
    void
    )
{
    os_time t;
    struct timespec tv;

#ifdef _POSIX_MONOTONIC_CLOCK

    /* The CLOCK_MONOTONIC is the best (and most accurate) monotonic clock for
     * obtaining time with near real-time progression, since it may be slewed
     * based on NTP adjustments on some Linux providing more stable time
     * progression (assuming that the Caesium clocks are better at timekeeping
     * than the quartz crystal in an average PC). */
    (void) clock_gettime (CLOCK_MONOTONIC, &tv);

#else

    /* Unfortunately no monotonic clock is supported for this POSIX platform.
     * Fall-back to the CLOCK_REALTIME instead. Unfortunately this means that
     * time jumps are not supported. */
    (void) clock_gettime (CLOCK_REALTIME, &tv);

#endif

    t.tv_sec = tv.tv_sec;
    t.tv_nsec = tv.tv_nsec;

    return t;
}

/** \brief Get elapsed time.
 *
 * This is implemented by means of the CLOCK_BOOTTIME clock which is available
 * since Linux 2.6.39, but is Linux specific. If it is not available, the
 * monotonic clock will be used as a fall-back.
 *
 * \return elapsed time since some unspecified fixed past time
 * \return os_timeGetMonotonic() otherwise
 */
os_time
os_timeGetElapsed (
    void
    )
{
#ifdef CLOCK_BOOTTIME
    os_time t;
    struct timespec tv;

    /* The CLOCK_BOOTTIME includes time spent during suspend, but is
     * Linux specific. */
    (void) clock_gettime (CLOCK_BOOTTIME, &tv);

    t.tv_sec = tv.tv_sec;
    t.tv_nsec = tv.tv_nsec;

    return t;
#else
    return os_timeGetMonotonic();
#endif /* CLOCK_MONOTONIC_BOOTTIME */
}
