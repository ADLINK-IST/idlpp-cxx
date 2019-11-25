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
/** \file services/serialization/code/sd_deepwalk.h
 *  \brief Prototypes for the deepwalk functionality, to be used by
 *         \b serializer descendants.
 */

#ifndef SD_DEEPWALK_H
#define SD_DEEPWALK_H

#include "c_typebase.h"
#include "c_metabase.h"

typedef c_bool sd_deepwalkFunc(c_type type, c_object *object, void *arg) __nonnull((1, 2)) __attribute_warn_unused_result__;

c_bool sd_deepwalk(c_type type, c_object *objectPtr, sd_deepwalkFunc action, void *actionArg) __nonnull((1, 2, 3)) __attribute_warn_unused_result__;

#endif  /* SD_DEEPWALK_H */
