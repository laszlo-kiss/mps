/* impl.h.mpscmv2: MEMORY POOL SYSTEM CLASS "MV2"
 *
 * $HopeName: MMsrc!mpscmv2.h(MMdevel_gavinm_splay.3) $
 * Copyright (C) 1998 Harlequin Group plc. All rights reserved.
 */

#ifndef mpscmv2_h
#define mpscmv2_h

#include "mps.h"

/* The mv2 pool class has five extra parameters to mps_pool_create:
 *  mps_res_t mps_pool_create(mps_pool_t * pool, mps_arena_t arena,
 *                            mps_class_t mv2_class,
 *                            size_t minimum_size,
 *                            size_t mean_size,
 *                            size_t maximum_size,
 *                            mps_count_t reserve_depth
 *                            mps_count_t fragmentation_limit);
 * minimum_, mean_, and maximum_size are the mimimum, mean, and
 * maximum (typical) size of objects expected to be allocated in the
 * pool.  reserve_depth is a measure of the expected hysteresis of the
 * object population.  fragmentation_limit is a percentage (between 0
 * and 100):  if the free space managed by the pool exceeds the
 * specified percentage, the pool will resort to a "first fit"
 * allocation policy.
 */
extern mps_class_t mps_class_mv2(void);

/* The mv2 pool class supports two extensions to the pool protocol:
   size and free_size. */
extern size_t mps_mv2_free_size(mps_pool_t mps_pool);
extern size_t mps_mv2_size(mps_pool_t mps_pool);

#endif /* mpscmv2_h */
