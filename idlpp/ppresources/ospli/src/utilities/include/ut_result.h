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
#ifndef UT_RESULT_H
#define UT_RESULT_H

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

typedef enum ut_result_e {
    UT_RESULT_UNDEFINED = OS_RETCODE_ID_UT_RESULT,
    UT_RESULT_OK,
    UT_RESULT_OUT_OF_MEMORY,
    UT_RESULT_WALK_ABORTED,
    UT_RESULT_COUNT,
    UT_RESULT_NOT_IMPLEMENTED,
    UT_RESULT_ILL_PARAM,
    UT_RESULT_ERROR
} ut_result;

OS_API os_int
ut_resultToReturnCode(
    ut_result result);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* UT_RESULT_H */
