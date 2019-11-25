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
#ifndef OS_ITERATOR_H
#define OS_ITERATOR_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "os_if.h"
#include "os_iterator_type.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * @def NULL
 * @bug OSPL-2272 We should not export a defintion of NULL */
#ifndef NULL
#define NULL ((void *)0)
#endif


typedef enum os_equality {
    OS_PL = -4,    /* Partial less (structure)    */
    OS_EL = -3,    /* Less or Equal (set)         */
    OS_LE = -2,    /* Less or Equal               */
    OS_LT = -1,    /* Less                        */
    OS_EQ = 0,     /* Equal                       */
    OS_GT = 1,     /* Greater                     */
    OS_GE = 2,     /* Greater or Equal            */
    OS_EG = 3,     /* Greater or Equal (set)      */
    OS_PG = 4,     /* Partial greater (structure) */
    OS_PE = 10,    /* Partial Equal               */
    OS_NE = 20,    /* Not equal                   */
    OS_ER = 99     /* Error: equality undefined   */
} os_equality;

typedef const void *os_iterResolveCompareArg;
typedef os_equality (*os_iterResolveCompare) ( const void *iterElement, const void *arg );
typedef os_equality (*os_iterSortAction) (const void *object1, const void *object2);

typedef void     *os_iterActionArg;
typedef os_int32 (*os_iterAction)     (void *o, os_iterActionArg arg);
typedef void     (*os_iterWalkAction) (void *o, os_iterActionArg arg);

OS_API os_iter   os_iterNew        (void *object) __attribute_returns_nonnull__;
OS_API os_iter   os_iterInsert     (os_iter i, void *object);
OS_API os_iter   os_iterAppend     (os_iter i, void *object);
OS_API void     *os_iterTakeFirst  (os_iter i);
OS_API void     *os_iterTakeLast   (os_iter i);
OS_API void     *os_iterTake       (os_iter i, void *object);
OS_API void     *os_iterTakeAction (os_iter iter, os_iterAction condition, os_iterActionArg arg);
OS_API void     *os_iterReadAction (os_iter iter, os_iterAction condition, os_iterActionArg arg);
OS_API os_iter   os_iterConcat     (os_iter head, os_iter tail);
OS_API os_iter   os_iterCopy       (os_iter i);
OS_API os_uint32 os_iterLength     (os_iter i);
OS_API void     *os_iterResolve    (os_iter i, os_iterResolveCompare compare, os_iterResolveCompareArg arg);
OS_API void     *os_iterObject     (os_iter i, os_uint32 index);
OS_API void      os_iterWalk       (os_iter i, os_iterWalkAction action, os_iterActionArg arg);
OS_API void      os_iterArray      (os_iter i, void *ar[]);
OS_API void      os_iterFree       (os_iter i);
OS_API os_int32  os_iterContains   (os_iter i, void *object);
OS_API void      os_iterSort       (os_iter iter, os_iterSortAction action, os_boolean ascending);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
