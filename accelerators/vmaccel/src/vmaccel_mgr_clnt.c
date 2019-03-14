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

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "vmaccel_mgr.h"


/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = {25, 0};

VMAccelAllocateReturnStatus *vmaccelmgr_register_1(VMAccelRegisterDesc *argp,
                                                   CLIENT *clnt) {
   static VMAccelAllocateReturnStatus clnt_res;

   memset((char *)&clnt_res, 0, sizeof(clnt_res));
   if (clnt_call(clnt, VMACCELMGR_REGISTER, (xdrproc_t)xdr_VMAccelRegisterDesc,
                 (caddr_t)argp, (xdrproc_t)xdr_VMAccelAllocateReturnStatus,
                 (caddr_t)&clnt_res, TIMEOUT) != RPC_SUCCESS) {
      return (NULL);
   }
   return (&clnt_res);
}

VMAccelReturnStatus *vmaccelmgr_unregister_1(VMAccelId *argp, CLIENT *clnt) {
   static VMAccelReturnStatus clnt_res;

   memset((char *)&clnt_res, 0, sizeof(clnt_res));
   if (clnt_call(clnt, VMACCELMGR_UNREGISTER, (xdrproc_t)xdr_VMAccelId,
                 (caddr_t)argp, (xdrproc_t)xdr_VMAccelReturnStatus,
                 (caddr_t)&clnt_res, TIMEOUT) != RPC_SUCCESS) {
      return (NULL);
   }
   return (&clnt_res);
}

VMAccelAllocateReturnStatus *vmaccelmgr_alloc_1(VMAccelDesc *argp,
                                                CLIENT *clnt) {
   static VMAccelAllocateReturnStatus clnt_res;

   memset((char *)&clnt_res, 0, sizeof(clnt_res));
   if (clnt_call(clnt, VMACCELMGR_ALLOC, (xdrproc_t)xdr_VMAccelDesc,
                 (caddr_t)argp, (xdrproc_t)xdr_VMAccelAllocateReturnStatus,
                 (caddr_t)&clnt_res, TIMEOUT) != RPC_SUCCESS) {
      return (NULL);
   }
   return (&clnt_res);
}

VMAccelReturnStatus *vmaccelmgr_free_1(VMAccelId *argp, CLIENT *clnt) {
   static VMAccelReturnStatus clnt_res;

   memset((char *)&clnt_res, 0, sizeof(clnt_res));
   if (clnt_call(clnt, VMACCELMGR_FREE, (xdrproc_t)xdr_VMAccelId, (caddr_t)argp,
                 (xdrproc_t)xdr_VMAccelReturnStatus, (caddr_t)&clnt_res,
                 TIMEOUT) != RPC_SUCCESS) {
      return (NULL);
   }
   return (&clnt_res);
}
