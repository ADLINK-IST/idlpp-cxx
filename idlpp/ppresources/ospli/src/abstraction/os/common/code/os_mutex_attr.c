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

/** \file os/common/code/os_mutex_attr.c
 *  \brief Common mutual exclusion semaphore attributes
 *
 * Implements os_mutexAttrInit and sets attributes
 * to platform independent values:
 * - scope is OS_SCOPE_SHARED
 */

/** \brief Initialize mutex attribute
 *
 * Set \b mutexAttr->scopeAttr to \b OS_SCOPE_PRIVATE
 * Set \b mutexAttr->errorCheckingAttr to \b OS_ERRORCHECKING_DISABLED
 */
_Post_satisfies_(mutexAttr->scopeAttr == OS_SCOPE_PRIVATE)
_Post_satisfies_(mutexAttr->errorCheckingAttr == OS_ERRORCHECKING_DISABLED)
void
os_mutexAttrInit (
    _Out_ os_mutexAttr *mutexAttr)
{
    mutexAttr->scopeAttr = OS_SCOPE_PRIVATE;
    /* By setting errorCheckingAttr to OS_ERRORCHECKING_ENABLED or
     * OS_ERRORCHECKING_DISABLED, error-checking can easily be enabled/disabled
     * for all mutexes that don't explicitly set the option themselves. */
    mutexAttr->errorCheckingAttr = OS_ERRORCHECKING_DISABLED;
}
