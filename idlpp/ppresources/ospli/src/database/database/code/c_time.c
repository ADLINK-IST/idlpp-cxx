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

#include "c_time.h"
#include "os_time.h"
#include "os_report.h"

const c_time C_TIME_ZERO         = {0, 0};
const c_time C_TIME_INFINITE     = {0x7fffffff, 0x7fffffffU};
const c_time C_TIME_MIN_INFINITE = {-0x7fffffff,  0x7fffffffU};
const c_time C_TIME_INVALID      = {-1,  0xffffffffU};

c_time
c_timeNormalize(
    c_time t)
{
    if (t.seconds == C_TIME_INFINITE.seconds) {
        return C_TIME_INFINITE;
    } else  {
        if (t.seconds == C_TIME_MIN_INFINITE.seconds) {
            return C_TIME_MIN_INFINITE;
        }
    }

    while (t.nanoseconds >= 1000000000) {
        t.seconds += 1;
        if (t.seconds == C_TIME_INFINITE.seconds) {
            return C_TIME_INFINITE;
        }
        t.nanoseconds -= 1000000000;
    }

    return t;
}

c_equality
c_timeCompare(
    c_time t1,
    c_time t2)
{
    assert (CHECK_TIME(
                C_TIME_TIMEKIND_EQUALS(t1, t2) /* Equal times can always be compared */
                        || (C_TIME_ISRELATIVE(t1) && C_TIME_ISRELATIVE(t2)) /* Both relative */
                        || (C_TIME_ISABSOLUTE(t1) && C_TIME_ISINFINITE(t2))
                        || (C_TIME_ISINFINITE(t1) && C_TIME_ISABSOLUTE(t2))
                )
           );
    assert ((C_TIME_NANOS(t1.nanoseconds) < 1000000000) ||
            (t1.nanoseconds == C_TIME_INFINITE.nanoseconds));
    assert ((C_TIME_NANOS(t2.nanoseconds) < 1000000000) ||
            (t2.nanoseconds == C_TIME_INFINITE.nanoseconds));

    if ((C_TIME_NANOS(t1.nanoseconds) >= 1000000000) &&
        ((t1.nanoseconds != C_TIME_INFINITE.nanoseconds) ||
         ((t1.seconds != C_TIME_INFINITE.seconds) &&
          (t1.seconds != C_TIME_MIN_INFINITE.seconds) )))
    {
        OS_REPORT(OS_ERROR,
                    "c_timeCompare",0,"Illegal time t1; <%d.%u>",
                    t1.seconds,
                    t1.nanoseconds);
    }
    if ((C_TIME_NANOS(t2.nanoseconds) >= 1000000000) &&
        ((t2.nanoseconds != C_TIME_INFINITE.nanoseconds) ||
         ((t2.seconds != C_TIME_INFINITE.seconds) &&
          (t2.seconds != C_TIME_MIN_INFINITE.seconds)) ))
    {
        OS_REPORT(OS_ERROR,
                    "c_timeCompare",0,"Illegal time t2; <%d.%u>",
                    t2.seconds,
                    t2.nanoseconds);
    }
    if (t1.seconds > t2.seconds) return C_GT;
    if (t1.seconds < t2.seconds) return C_LT;
    if (C_TIME_NANOS(t1.nanoseconds) > C_TIME_NANOS(t2.nanoseconds)) return C_GT;
    if (C_TIME_NANOS(t1.nanoseconds) < C_TIME_NANOS(t2.nanoseconds)) return C_LT;
    return C_EQ;
}

c_time
c_timeAdd(
    c_time t1,
    c_time t2)
{
    c_time tr;

    /* The only valid additions are C_TIME_ABSOLUTE_TIME + C_TIME_RELATIVE_TIME
     * or C_TIME_RELATIVE_TIME + C_TIME_RELATIVE_TIME. */
    assert (CHECK_TIME(
               (C_TIME_ISABSOLUTE(t1) && C_TIME_ISRELATIVE(t2)) ||
                (C_TIME_ISRELATIVE(t1) && C_TIME_ISABSOLUTE(t2)) ||
                (C_TIME_ISRELATIVE(t1) && C_TIME_ISRELATIVE(t2)))
           );
    assert ((C_TIME_NANOS(t1.nanoseconds) < 1000000000) ||
            (t1.nanoseconds == C_TIME_INFINITE.nanoseconds));
    assert ((C_TIME_NANOS(t2.nanoseconds) < 1000000000) ||
            (t2.nanoseconds == C_TIME_INFINITE.nanoseconds));

    /* Don't accept adding opposite sign infinites */
    assert(!(c_timeIsInfinite(t1) && c_timeIsMinInfinite(t2)));
    assert(!(c_timeIsMinInfinite(t1) && c_timeIsInfinite(t2)));

    if (t1.nanoseconds == C_TIME_INFINITE.nanoseconds) {
        if ((t1.seconds == C_TIME_INFINITE.seconds) ||
            (t1.seconds == C_TIME_MIN_INFINITE.seconds))
        {
            return t1; /* result stays infinite. */
        } else {
            OS_REPORT(OS_ERROR,
                        "c_timeAdd",0,"Illegal time t1; <%d.%u>",
                        t1.seconds,
                        t1.nanoseconds);
            assert(t1.seconds == C_TIME_INFINITE.seconds);
        }
    }
    if (t2.nanoseconds == C_TIME_INFINITE.nanoseconds) {
        if ((t2.seconds == C_TIME_INFINITE.seconds) ||
            (t2.seconds == C_TIME_INFINITE.seconds))
        {
            return t2; /* result stays infinite. */
        } else {
            OS_REPORT(OS_ERROR,
                        "c_timeAdd",0,"Illegal time t2; <%d.%u>",
                        t2.seconds,
                        t2.nanoseconds);
            assert(t2.seconds == C_TIME_INFINITE.seconds);
        }
    }
    if (t2.seconds > 0) {
        if (C_TIME_INFINITE.seconds - t2.seconds <= t1.seconds) { 
            /* is identical to
             * 'C_TIME_INFINITE.seconds <= t1.seconds + t2.seconds' 
             * In other words the sum is larger than infinite,
             * so results must be infinite.
             */
            return C_TIME_INFINITE;
        }
    } else {
        if (C_TIME_MIN_INFINITE.seconds - t2.seconds >= t1.seconds) {
            /* is identical to 
             * '-(C_TIME_MIN_INFINITE.seconds <= t1.seconds + t2.seconds)' 
             * In other words the sum is smaller than min infinite,
             * so results must be min infinite.
             */
            return C_TIME_MIN_INFINITE;
        }
    }

    tr.seconds = t1.seconds + t2.seconds;
    tr.nanoseconds = C_TIME_NANOS(t1.nanoseconds) + C_TIME_NANOS(t2.nanoseconds);
    tr = c_timeNormalize(tr);

    C_TIME_SET_KIND(tr, C_TIME_TIMEKIND_EQUALS(t1, t2) ? C_TIME_GET_KIND(t1) : (C_TIME_ISABSOLUTE(t1) ? C_TIME_GET_KIND(t1) : C_TIME_GET_KIND(t2)));

    return tr;
}

c_time
c_timeSub(
    c_time t1,
    c_time t2)
{
    c_time tr;
    c_long nsecsResult;

    /* All is OK, except mixed REALTIME and MONOTONIC or ELAPSED */
    assert (CHECK_TIME(
                C_TIME_TIMEKIND_EQUALS(t1, t2) ||
                (C_TIME_ISABSOLUTE(t1) && C_TIME_ISRELATIVE(t2)) ||
                (C_TIME_ISRELATIVE(t1) && C_TIME_ISABSOLUTE(t2)))
           );
    assert ((C_TIME_NANOS(t1.nanoseconds) < 1000000000) ||
            (t1.nanoseconds == C_TIME_INFINITE.nanoseconds));
    assert ((C_TIME_NANOS(t2.nanoseconds) < 1000000000) ||
            (t2.nanoseconds == C_TIME_INFINITE.nanoseconds));

    /* Don't accept substracting equal sign infinites */
    assert(!(c_timeIsInfinite(t1) && c_timeIsInfinite(t2)));
    assert(!(c_timeIsMinInfinite(t1) && c_timeIsMinInfinite(t2)));

    if (t1.nanoseconds == C_TIME_INFINITE.nanoseconds) {
        if ((t1.seconds == C_TIME_INFINITE.seconds) ||
            (t1.seconds == C_TIME_MIN_INFINITE.seconds)) {
            return t1; /* result stays infinite. */
        } else {
            OS_REPORT(OS_ERROR,
                        "c_timeSub",0,"Illegal time t1; <%d.%u>",
                        t1.seconds,
                        t1.nanoseconds);
            assert(t1.seconds == C_TIME_INFINITE.seconds);
        }
    } else if (C_TIME_NANOS(t1.nanoseconds) >= 1000000000) {
        OS_REPORT(OS_ERROR,
                    "c_timeSub",0,"Illegal time t1; <%d.%u>",
                    t1.seconds,
                    t1.nanoseconds);
        assert(C_TIME_NANOS(t1.nanoseconds) < 1000000000);
    }
    if (t2.nanoseconds == C_TIME_INFINITE.nanoseconds) {
        if ((t2.seconds == C_TIME_INFINITE.seconds) ||
            (t2.seconds == C_TIME_MIN_INFINITE.seconds)) {
            return t2; /* result stays infinite. */
        } else {
            OS_REPORT(OS_ERROR,
                        "c_timeSub",0,"Illegal time t2; <%d.%u>",
                        t2.seconds,
                        t2.nanoseconds);
            assert(t2.seconds == C_TIME_INFINITE.seconds);
        }
    } else if (C_TIME_NANOS(t2.nanoseconds) >= 1000000000) {
        OS_REPORT(OS_ERROR,
                    "c_timeSub",0,"Illegal time t2; <%d.%u>",
                    t2.seconds,
                    t2.nanoseconds);
        assert(C_TIME_NANOS(t2.nanoseconds) < 1000000000);
    }
        
    if (t2.seconds > 0) {
        if (C_TIME_MIN_INFINITE.seconds + t2.seconds >= t1.seconds) { 
            /* is identical to 
             * 'C_TIME_MIN_INFINITE.seconds >= t1.seconds - t2.seconds' 
             * In other words the sum is smaller than min infinite,
             * so results must be min infinite.
             */
            return C_TIME_MIN_INFINITE;
        }
    } else {
        if (C_TIME_INFINITE.seconds + t2.seconds <= t1.seconds) {
            /* is identical to
             * '-(C_TIME_INFINITE.seconds >= t1.seconds - t2.seconds)' 
             * In other words the sum is larger than infinite,
             * so results must be infinite.
             */
            return C_TIME_INFINITE;
        }
   }

    tr.seconds = t1.seconds - t2.seconds;

    if (tr.seconds == C_TIME_INFINITE.seconds) {
        return C_TIME_INFINITE;
    } else  {
        if (tr.seconds == C_TIME_MIN_INFINITE.seconds) {
            return C_TIME_MIN_INFINITE;
        }
    }

    nsecsResult = (c_long) C_TIME_NANOS(t1.nanoseconds) - (c_long) C_TIME_NANOS(t2.nanoseconds);

    if (nsecsResult < 0) {
        tr.seconds--;
        if (tr.seconds == C_TIME_MIN_INFINITE.seconds) {
            return C_TIME_MIN_INFINITE;
        }
       nsecsResult += 1000000000;
    }
    tr.nanoseconds = (c_ulong) nsecsResult;
    c_timeNormalize(tr);
    C_TIME_SET_KIND(tr, C_TIME_TIMEKIND_EQUALS(t1, t2) ? (C_TIME_ISABSOLUTE(t1) ? C_TIME_RELATIVE : C_TIME_GET_KIND(t1))  : (C_TIME_ISABSOLUTE(t1) ? C_TIME_GET_KIND(t1) : C_TIME_GET_KIND(t2)));

    return tr;
}

c_bool
c_timeValid(
    c_time t1)
{
    c_bool valid;

    if ( ((t1.seconds == C_TIME_INFINITE.seconds) &&
          (t1.nanoseconds == C_TIME_INFINITE.nanoseconds)) ||
         ((t1.seconds == C_TIME_MIN_INFINITE.seconds) &&
          (t1.nanoseconds == C_TIME_MIN_INFINITE.nanoseconds)) )
    {
        valid = TRUE;
    } else {
        if ( (t1.seconds == C_TIME_INFINITE.seconds) || 
             (t1.seconds == C_TIME_MIN_INFINITE.seconds)) {
            valid = FALSE;
        } else {
            if (C_TIME_NANOS(t1.nanoseconds) < 1000000000U) {
                valid = TRUE;
            } else { 
                valid = FALSE;
            }
        }
    }
        
    return valid;
}

c_timeResult
c_timeNanoSleep(
    c_time interval)
{
    os_time t;
    
    /* This call should only accept relative times. C_TIME_ISRELATIVE(...) does
     * include the INFINITE's as well, so !C_TIME_ISABSOLUTE(...) is used
     * instead. */
    assert (CHECK_TIME(!C_TIME_ISABSOLUTE(interval)));

    t.tv_sec = interval.seconds;
    t.tv_nsec = (os_int32) C_TIME_NANOS(interval.nanoseconds);
    return (c_timeResult) os_nanoSleep(t);
    
}

/** \brief return floating point representation of c_time reprersentation.
 *
 * because of the limited floating point represenation (64 bits)
 * the value will be limited to a resoltion of about 1 us.
 */
c_double
c_timeToReal(
    c_time t)
{
    c_double tr;

    /* always true expr => gcc warning :
     * assert (t.nanoseconds >= 0);
     */
    assert (C_TIME_NANOS(t.nanoseconds) < 1000000000);

    tr = (c_double)t.seconds +
         (c_double)C_TIME_NANOS(t.nanoseconds) / (c_double)1000000000.0;

    return tr;
}

/** \brief return c_time represenation of floating point reprersentation.
 *
 * because of the limited floating point represenation (64 bits)
 * the value will be limited to a resoltion of about 1 us.
 */
c_time
c_timeFromReal (
    c_double d)
{
    c_time tr;

    if (d >= (c_double)C_TIME_INFINITE.seconds) {
        OS_REPORT(OS_ERROR,"c_timeFromReal",0,"overflow detected: real exceeds max int");
    }
    tr.seconds = (c_long)d;
    tr.nanoseconds = (c_ulong)((d-(c_double)tr.seconds) *
                                  (c_double)1000000000.0);
    C_TIME_SET_KIND(tr, C_TIME_RELATIVE);

    return tr;
}
