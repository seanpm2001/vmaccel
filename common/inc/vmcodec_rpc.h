/******************************************************************************

Copyright (c) 2019 VMware, Inc.
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

#ifndef _VMCODEC_RPC_H_RPCGEN
#define _VMCODEC_RPC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "vmaccel_rpc.h"
#include "vmcodec_defs.h"

typedef u_int VMCODECCaps;

typedef VMAccelId VMCODECContextId;

struct VMCODECContextAllocateDesc {
   VMAccelId accelId;
   VMCODECContextId clientId;
   VMAccelSelectionMask selectionMask;
   VMCODECCaps requiredCaps;
};
typedef struct VMCODECContextAllocateDesc VMCODECContextAllocateDesc;

struct VMCODECContextAllocateStatus {
   VMAccelStatusCode status;
   VMCODECCaps caps;
};
typedef struct VMCODECContextAllocateStatus VMCODECContextAllocateStatus;

struct VMCODECSurfaceId {
   VMCODECContextId cid;
   VMAccelSurfaceId accel;
};
typedef struct VMCODECSurfaceId VMCODECSurfaceId;

struct VMCODECSurfaceAllocateDesc {
   VMAccelSurfaceId client;
   VMAccelSurfaceDesc desc;
};
typedef struct VMCODECSurfaceAllocateDesc VMCODECSurfaceAllocateDesc;

struct VMCODECImageUploadOp {
   VMCODECSurfaceId img;
   VMAccelImageTransferOp op;
   VMAccelSurfaceWriteConsistency mode;
};
typedef struct VMCODECImageUploadOp VMCODECImageUploadOp;

struct VMCODECImageDownloadOp {
   VMCODECSurfaceId img;
   VMAccelImageTransferOp op;
   VMAccelSurfaceReadConsistency mode;
};
typedef struct VMCODECImageDownloadOp VMCODECImageDownloadOp;

struct VMCODECDecodeOp {
   VMCODECContextId cid;
   struct {
      u_int output_len;
      VMCODECSurfaceId *output_val;
   } output;
};
typedef struct VMCODECDecodeOp VMCODECDecodeOp;

struct VMCODECEncodeOp {
   VMCODECContextId cid;
   struct {
      u_int inptut_len;
      VMCODECSurfaceId *inptut_val;
   } inptut;
};
typedef struct VMCODECEncodeOp VMCODECEncodeOp;

struct VMCODECContextAllocateReturnStatus {
   int errno;
   union {
      VMCODECContextAllocateStatus *ret;
   } VMCODECContextAllocateReturnStatus_u;
};
typedef struct VMCODECContextAllocateReturnStatus
   VMCODECContextAllocateReturnStatus;

#define VMCODEC 0x20000082
#define VMCODEC_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define VMCODEC_CONTEXTALLOC 1
extern VMCODECContextAllocateReturnStatus *
vmcodec_contextalloc_1(VMCODECContextAllocateDesc *, CLIENT *);
extern VMCODECContextAllocateReturnStatus *
vmcodec_contextalloc_1_svc(VMCODECContextAllocateDesc *, struct svc_req *);
#define VMCODEC_CONTEXTDESTROY 2
extern VMAccelReturnStatus *vmcodec_contextdestroy_1(VMCODECContextId *,
                                                     CLIENT *);
extern VMAccelReturnStatus *vmcodec_contextdestroy_1_svc(VMCODECContextId *,
                                                         struct svc_req *);
#define VMCODEC_SURFACEALLOC 3
extern VMAccelSurfaceAllocateReturnStatus *
vmcodec_surfacealloc_1(VMCODECSurfaceAllocateDesc *, CLIENT *);
extern VMAccelSurfaceAllocateReturnStatus *
vmcodec_surfacealloc_1_svc(VMCODECSurfaceAllocateDesc *, struct svc_req *);
#define VMCODEC_SURFACEDESTROY 4
extern VMAccelReturnStatus *vmcodec_surfacedestroy_1(VMCODECSurfaceId *,
                                                     CLIENT *);
extern VMAccelReturnStatus *vmcodec_surfacedestroy_1_svc(VMCODECSurfaceId *,
                                                         struct svc_req *);
#define VMCODEC_IMAGEUPLOAD 5
extern VMAccelReturnStatus *vmcodec_imageupload_1(VMCODECImageUploadOp *,
                                                  CLIENT *);
extern VMAccelReturnStatus *vmcodec_imageupload_1_svc(VMCODECImageUploadOp *,
                                                      struct svc_req *);
#define VMCODEC_IMAGEDOWNLOAD 6
extern VMAccelDownloadReturnStatus *
vmcodec_imagedownload_1(VMCODECImageDownloadOp *, CLIENT *);
extern VMAccelDownloadReturnStatus *
vmcodec_imagedownload_1_svc(VMCODECImageDownloadOp *, struct svc_req *);
#define VMCODEC_DECODE 7
extern VMAccelReturnStatus *vmcodec_decode_1(VMCODECDecodeOp *, CLIENT *);
extern VMAccelReturnStatus *vmcodec_decode_1_svc(VMCODECDecodeOp *,
                                                 struct svc_req *);
#define VMCODEC_ENCODE 8
extern VMAccelReturnStatus *vmcodec_encode_1(VMCODECEncodeOp *, CLIENT *);
extern VMAccelReturnStatus *vmcodec_encode_1_svc(VMCODECEncodeOp *,
                                                 struct svc_req *);
extern int vmcodec_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define VMCODEC_CONTEXTALLOC 1
extern VMCODECContextAllocateReturnStatus *vmcodec_contextalloc_1();
extern VMCODECContextAllocateReturnStatus *vmcodec_contextalloc_1_svc();
#define VMCODEC_CONTEXTDESTROY 2
extern VMAccelReturnStatus *vmcodec_contextdestroy_1();
extern VMAccelReturnStatus *vmcodec_contextdestroy_1_svc();
#define VMCODEC_SURFACEALLOC 3
extern VMAccelSurfaceAllocateReturnStatus *vmcodec_surfacealloc_1();
extern VMAccelSurfaceAllocateReturnStatus *vmcodec_surfacealloc_1_svc();
#define VMCODEC_SURFACEDESTROY 4
extern VMAccelReturnStatus *vmcodec_surfacedestroy_1();
extern VMAccelReturnStatus *vmcodec_surfacedestroy_1_svc();
#define VMCODEC_IMAGEUPLOAD 5
extern VMAccelReturnStatus *vmcodec_imageupload_1();
extern VMAccelReturnStatus *vmcodec_imageupload_1_svc();
#define VMCODEC_IMAGEDOWNLOAD 6
extern VMAccelDownloadReturnStatus *vmcodec_imagedownload_1();
extern VMAccelDownloadReturnStatus *vmcodec_imagedownload_1_svc();
#define VMCODEC_DECODE 7
extern VMAccelReturnStatus *vmcodec_decode_1();
extern VMAccelReturnStatus *vmcodec_decode_1_svc();
#define VMCODEC_ENCODE 8
extern VMAccelReturnStatus *vmcodec_encode_1();
extern VMAccelReturnStatus *vmcodec_encode_1_svc();
extern int vmcodec_1_freeresult();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern bool_t xdr_VMCODECCaps(XDR *, VMCODECCaps *);
extern bool_t xdr_VMCODECContextId(XDR *, VMCODECContextId *);
extern bool_t xdr_VMCODECContextAllocateDesc(XDR *,
                                             VMCODECContextAllocateDesc *);
extern bool_t xdr_VMCODECContextAllocateStatus(XDR *,
                                               VMCODECContextAllocateStatus *);
extern bool_t xdr_VMCODECSurfaceId(XDR *, VMCODECSurfaceId *);
extern bool_t xdr_VMCODECSurfaceAllocateDesc(XDR *,
                                             VMCODECSurfaceAllocateDesc *);
extern bool_t xdr_VMCODECImageUploadOp(XDR *, VMCODECImageUploadOp *);
extern bool_t xdr_VMCODECImageDownloadOp(XDR *, VMCODECImageDownloadOp *);
extern bool_t xdr_VMCODECDecodeOp(XDR *, VMCODECDecodeOp *);
extern bool_t xdr_VMCODECEncodeOp(XDR *, VMCODECEncodeOp *);
extern bool_t
xdr_VMCODECContextAllocateReturnStatus(XDR *,
                                       VMCODECContextAllocateReturnStatus *);

#else /* K&R C */
extern bool_t xdr_VMCODECCaps();
extern bool_t xdr_VMCODECContextId();
extern bool_t xdr_VMCODECContextAllocateDesc();
extern bool_t xdr_VMCODECContextAllocateStatus();
extern bool_t xdr_VMCODECSurfaceId();
extern bool_t xdr_VMCODECSurfaceAllocateDesc();
extern bool_t xdr_VMCODECImageUploadOp();
extern bool_t xdr_VMCODECImageDownloadOp();
extern bool_t xdr_VMCODECDecodeOp();
extern bool_t xdr_VMCODECEncodeOp();
extern bool_t xdr_VMCODECContextAllocateReturnStatus();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_VMCODEC_RPC_H_RPCGEN */
