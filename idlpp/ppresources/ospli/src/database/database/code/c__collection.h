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

#ifndef C__COLLECTION_H
#define C__COLLECTION_H

#include "c_collection.h"

#if defined (__cplusplus)
extern "C" {
#endif

extern const size_t c_listSize;
extern const size_t c_setSize;
extern const size_t c_bagSize;
extern const size_t c_tableSize;
extern const size_t c_querySize;

c_array c_keyList          (c_table c);
void    c_collectionInit   (c_base base);
void    c_queryOptimize    (c_query _this);

void    c_clear            (c_collection c);

#if defined (__cplusplus)
}
#endif

#endif /* C__COLLECTION_H */
