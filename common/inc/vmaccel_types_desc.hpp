/******************************************************************************

Copyright (c) 2016-2019 VMware, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#ifndef _VMACCEL_TYPES_DESC_HPP_
#define _VMACCEL_TYPES_DESC_HPP_ 1

#include <cstring>
#include "vmaccel_types_address.h"
#include "vmaccel_types_address.hpp"

#include "log_level.h"

inline bool operator<(const VMAccelWorkloadDesc &lhs,
                      const VMAccelWorkloadDesc &rhs) {
   /*
    * A workload is less than another workload if at lesat one dimension
    * is less than.
    */
   if ((lhs.localMemSizeKB < rhs.localMemSizeKB) ||
       (lhs.megaFlops < rhs.megaFlops) || (lhs.megaOps < rhs.megaOps)) {
      return true;
   }

   return false;
}

inline bool operator<=(const VMAccelWorkloadDesc &lhs,
                       const VMAccelWorkloadDesc &rhs) {
   if ((lhs.localMemSizeKB <= rhs.localMemSizeKB) &&
       (lhs.megaFlops <= rhs.megaFlops) && (lhs.megaOps <= rhs.megaOps)) {
      return true;
   }

   return false;
}

inline VMAccelWorkloadDesc operator+=(VMAccelWorkloadDesc &lhs,
                                      const VMAccelWorkloadDesc &rhs) {
   lhs.megaFlops += rhs.megaFlops;
   lhs.megaOps += rhs.megaOps;
   lhs.llcSizeKB += rhs.llcSizeKB;
   lhs.llcBandwidthMBSec += rhs.llcBandwidthMBSec;
   lhs.localMemSizeKB += rhs.localMemSizeKB;
   lhs.localMemBandwidthMBSec += rhs.localMemBandwidthMBSec;
   lhs.nonLocalMemSizeKB += rhs.nonLocalMemSizeKB;
   lhs.nonLocalMemBandwidthMBSec += rhs.nonLocalMemBandwidthMBSec;
   lhs.interconnectBandwidthMBSec += rhs.interconnectBandwidthMBSec;

   return lhs;
};

inline VMAccelWorkloadDesc operator-=(VMAccelWorkloadDesc &lhs,
                                      const VMAccelWorkloadDesc &rhs) {
   lhs.megaFlops -= rhs.megaFlops;
   lhs.megaOps -= rhs.megaOps;
   lhs.llcSizeKB -= rhs.llcSizeKB;
   lhs.llcBandwidthMBSec -= rhs.llcBandwidthMBSec;
   lhs.localMemSizeKB -= rhs.localMemSizeKB;
   lhs.localMemBandwidthMBSec -= rhs.localMemBandwidthMBSec;
   lhs.nonLocalMemSizeKB -= rhs.nonLocalMemSizeKB;
   lhs.nonLocalMemBandwidthMBSec -= rhs.nonLocalMemBandwidthMBSec;
   lhs.interconnectBandwidthMBSec -= rhs.interconnectBandwidthMBSec;
   return lhs;
};

inline VMAccelWorkloadDesc operator+(const VMAccelWorkloadDesc &lhs,
                                     const VMAccelWorkloadDesc &rhs) {
   VMAccelWorkloadDesc out = lhs;
   out += rhs;
   return out;
}

inline VMAccelWorkloadDesc operator-(const VMAccelWorkloadDesc &lhs,
                                     const VMAccelWorkloadDesc &rhs) {
   VMAccelWorkloadDesc out = lhs;
   out -= rhs;
   return out;
}

static void Constructor(VMAccelWorkloadDesc &obj) {
   obj.megaFlops = 0;
   obj.megaOps = 0;
   obj.llcSizeKB = 0;
   obj.llcBandwidthMBSec = 0;
   obj.localMemSizeKB = 0;
   obj.localMemBandwidthMBSec = 0;
   obj.nonLocalMemSizeKB = 0;
   obj.nonLocalMemBandwidthMBSec = 0;
   obj.interconnectBandwidthMBSec = 0;
}

inline void Log_VMAccelWorkloadDesc(const char *prefix,
                                    const VMAccelWorkloadDesc *desc) {
   Log("%s megaFlops=%u\n", prefix, desc->megaFlops);
   Log("%s megaOps=%u\n", prefix, desc->megaOps);
   Log("%s llcSizeKB=%u\n", prefix, desc->llcSizeKB);
   Log("%s llcBandwidthMBSec=%u\n", prefix, desc->llcBandwidthMBSec);
   Log("%s localMemSizeKB=%u\n", prefix, desc->localMemSizeKB);
   Log("%s localMemBandwidthMBSec=%u\n", prefix, desc->localMemBandwidthMBSec);
   Log("%s nonLocalMemSizeKB=%u\n", prefix, desc->nonLocalMemSizeKB);
   Log("%s nonLocalMemBandwidthMBSec=%u\n", prefix,
       desc->nonLocalMemBandwidthMBSec);
   Log("%s interconnectBandwidthMBSec=%u\n", prefix,
       desc->interconnectBandwidthMBSec);
}

inline bool operator<(const VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   return lhs.capacity < rhs.capacity;
}

inline bool operator<=(const VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   return lhs.capacity <= rhs.capacity;
}

inline VMAccelDesc operator+=(VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   lhs.capacity += rhs.capacity;
   return lhs;
};

inline VMAccelDesc operator-=(VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   lhs.capacity -= rhs.capacity;
   return lhs;
};

inline VMAccelDesc operator+(const VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   VMAccelDesc out = lhs;
   out.capacity += rhs.capacity;
   return out;
}

inline VMAccelDesc operator-(const VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   VMAccelDesc out = lhs;
   out.capacity -= rhs.capacity;
   return out;
}

struct VMAccelDescCmp {
   bool operator()(const VMAccelObject<VMAccelDesc> &lhs,
                   const VMAccelObject<VMAccelDesc> &rhs) const {
      return (lhs.GetParentId() != rhs.GetParentId() ||
              lhs.GetObj().capacity < rhs.GetObj().capacity);
   }
};

static void Constructor(VMAccelDesc &obj) {
   obj.parentId = VMACCEL_INVALID_ID;
   Constructor(obj.parentAddr);
   obj.typeMask = 0;
   obj.architecture = 0;
   obj.caps = 0;
   obj.formatCaps.formatCaps_len = 0;
   obj.formatCaps.formatCaps_val = NULL;
   Constructor(obj.capacity);
   obj.maxContexts = 0;
   obj.maxQueues = 0;
   obj.maxEvents = 0;
   obj.maxFences = 0;
   obj.maxSurfaces = 0;
   obj.maxMappings = 0;
}

static void Destructor(VMAccelDesc &obj) {
   Destructor(obj.parentAddr);
   free(obj.formatCaps.formatCaps_val);
   obj.formatCaps.formatCaps_val = NULL;
}

static void DeepCopy(VMAccelDesc &lhs, const VMAccelDesc &rhs) {
   if (&lhs != &rhs) {
      lhs.parentId = rhs.parentId;
      DeepCopy(lhs.parentAddr, rhs.parentAddr);
      lhs.typeMask = rhs.typeMask;
      lhs.architecture = rhs.architecture;
      lhs.caps = rhs.caps;
      lhs.formatCaps.formatCaps_len = rhs.formatCaps.formatCaps_len;
      free(lhs.formatCaps.formatCaps_val);
      if (rhs.formatCaps.formatCaps_len != 0) {
         lhs.formatCaps.formatCaps_val = (VMAccelFormatDesc *)malloc(
            rhs.formatCaps.formatCaps_len * sizeof(VMAccelFormatDesc));
         if (lhs.formatCaps.formatCaps_val != NULL) {
            memcpy(lhs.formatCaps.formatCaps_val, rhs.formatCaps.formatCaps_val,
                   rhs.formatCaps.formatCaps_len * sizeof(VMAccelFormatDesc));
         }
      } else {
         lhs.formatCaps.formatCaps_val = NULL;
      }
      lhs.capacity = rhs.capacity;
      lhs.maxContexts = rhs.maxContexts;
      lhs.maxQueues = rhs.maxQueues;
      lhs.maxEvents = rhs.maxEvents;
      lhs.maxFences = rhs.maxFences;
      lhs.maxSurfaces = rhs.maxSurfaces;
      lhs.maxMappings = rhs.maxMappings;
   }
}

static void Move(VMAccelDesc &lhs, VMAccelDesc &rhs) {
   if (&lhs != &rhs) {
      lhs.parentId = rhs.parentId;
      Move(lhs.parentAddr, rhs.parentAddr);
      lhs.typeMask = rhs.typeMask;
      lhs.architecture = rhs.architecture;
      lhs.caps = rhs.caps;
      lhs.formatCaps.formatCaps_len = rhs.formatCaps.formatCaps_len;
      /*
       * The following line causes a Valgrind warning:
       *
       *   Conditional jump or move depends on uninitialised value(s)
       *
       * This is avoided by memset of objects for VMAccelObject to zero on
       * construction.
       */
      free(lhs.formatCaps.formatCaps_val);
      lhs.formatCaps.formatCaps_val = rhs.formatCaps.formatCaps_val;
      lhs.capacity = rhs.capacity;
      lhs.maxContexts = rhs.maxContexts;
      lhs.maxQueues = rhs.maxQueues;
      lhs.maxEvents = rhs.maxEvents;
      lhs.maxFences = rhs.maxFences;
      lhs.maxSurfaces = rhs.maxSurfaces;
      lhs.maxMappings = rhs.maxMappings;
      memset(&rhs, 0, sizeof(rhs));
      rhs.parentId = VMACCEL_INVALID_ID;
   }
}

static bool IsEmpty(const VMAccelDesc val) {
   return (val.capacity.megaFlops + val.capacity.megaOps +
           val.capacity.llcSizeKB + val.capacity.llcBandwidthMBSec +
           val.capacity.localMemSizeKB + val.capacity.localMemBandwidthMBSec +
           val.capacity.nonLocalMemSizeKB +
           val.capacity.nonLocalMemBandwidthMBSec +
           val.capacity.interconnectBandwidthMBSec) == 0;
}

static bool Reserve(const VMAccelDesc &a, const VMAccelDesc &req,
                    VMAccelDesc &d, VMAccelDesc &r) {
   if (a.capacity < req.capacity) {
      return false;
   }

   memset(&d, 0, sizeof(d));
   memset(&r, 0, sizeof(r));

   DeepCopy(d, a);
   DeepCopy(r, a);
   d.capacity = req.capacity;
   r.capacity = a.capacity - d.capacity;

   return r.capacity < a.capacity;
}

static bool
FreeObj(std::multiset<VMAccelObject<VMAccelDesc>, VMAccelDescCmp> &pool,
        const VMAccelObject<VMAccelDesc> obj) {
   /*
    * Update and replace the value, only one per-parent.
    */
   auto it = pool.begin();
   for (; it != pool.end(); it++) {
      if (it->GetParentId() == obj.GetParentId()) {
         break;
      }
   }

   if (it == pool.end()) {
      auto res = pool.emplace(obj);
      if (res == pool.end())
         assert(0);
      return res != pool.end();
   } else {
      VMAccelDesc desc;
      memset(&desc, 0, sizeof(desc));
      /*
       * Make a deep copy before the backing is destructed by pool.erase.
       */
      DeepCopy(desc, it->GetObj());
      pool.erase(it);
      desc.capacity += obj.GetObj().capacity;
      auto res =
         pool.insert(VMAccelObject<VMAccelDesc>(obj.GetParentId(), &desc));
      Destructor(desc);
      return res != pool.end();
   }
}

inline void Log_VMAccelDesc(const char *prefix, const VMAccelDesc *desc) {
   char str[256];

   Log("%s parentId=%u\n", prefix, desc->parentId);
   Log_VMAccelAddress(prefix, &desc->parentAddr);
   Log("%s typeMask=%u\n", prefix, desc->typeMask);
   Log("%s architecture=%u\n", prefix, desc->architecture);
   Log("%s caps=0x%x\n", prefix, desc->caps);

   snprintf(str, sizeof(str), "%s capacity:", prefix);
   Log_VMAccelWorkloadDesc(str, &desc->capacity);

   Log("%s maxContexts=%u\n", prefix, desc->maxContexts);
   Log("%s maxQueues=%u\n", prefix, desc->maxQueues);
   Log("%s maxEvents=%u\n", prefix, desc->maxEvents);
   Log("%s maxFences=%u\n", prefix, desc->maxFences);
   Log("%s maxSurfaces=%u\n", prefix, desc->maxSurfaces);
   Log("%s maxMappings=%u\n", prefix, desc->maxMappings);
}

#endif /* defined _VMACCEL_TYPES_DESC_HPP_ */
