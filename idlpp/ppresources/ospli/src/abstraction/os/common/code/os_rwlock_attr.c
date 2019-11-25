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

/** \file os/common/code/os_rwlock_attr.c
 *  \brief Common multiple reader writer lock attributes
 *
 * Implements os_rwlockAttrInit and sets attributes
 * to platform independent values:
 * - scope is OS_SCOPE_PRIVATE
 */

/** \brief Initialize rwlock attribute
 *
 * Set \b rwlockAttr->scopeAttr to \b OS_SCOPE_PRIVATE
 */
_Post_satisfies_(rwlockAttr->scopeAttr == OS_SCOPE_PRIVATE)
void
os_rwlockAttrInit (
    _Out_ os_rwlockAttr *rwlockAttr)
{
    rwlockAttr->scopeAttr = OS_SCOPE_PRIVATE;
}
