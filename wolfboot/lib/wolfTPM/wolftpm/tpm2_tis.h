/* tpm2_tis.h
 *
 * Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfTPM.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef __TPM2_TIS_H__
#define __TPM2_TIS_H__

#include <wolftpm/tpm2.h>
#include <wolftpm/tpm2_packet.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* The default locality to use */
#ifndef WOLFTPM_LOCALITY_DEFAULT
#define WOLFTPM_LOCALITY_DEFAULT 0
#endif

/* Optional: WOLFTPM_TIS_RESET_STALE_LOCALITY makes TPM2_TIS_RequestLocality
 * release any other active locality at startup so the default can be granted -
 * recovers a wedge left when a prior session did not return to locality 0. Off
 * by default: on a shared bus it could clear a locality another master holds, so
 * enable it only for single-master setups (or use the nRST HAL to recover). */

/* Number of poll attempts when requesting a locality at runtime. A legitimate
 * grant is near-instant, so this is kept small to fail fast when a locality
 * cannot be granted (unlike TPM_TIMEOUT_TRIES used for chip startup). */
#ifndef WOLFTPM_LOCALITY_TIMEOUT_TRIES
#define WOLFTPM_LOCALITY_TIMEOUT_TRIES 1000
#endif

#define TPM_TIS_READ       0x80
#define TPM_TIS_WRITE      0x00

/* A floating/undecoded bus reads back 0xFF; since that has both the active and
 * valid ACCESS bits set it must not be mistaken for a granted locality. */
#define TPM_TIS_ACCESS_INVALID 0xFFu

#define TPM_TIS_HEADER_SZ  4

#define TPM_TIS_READY_MASK 0x01

/* TIS register offsets (without base address or locality) */
#define TPM_TIS_DATA_FIFO_OFFSET   0x0024u
#define TPM_TIS_XDATA_FIFO_OFFSET  0x0083u

/* Typically only 0-2 wait states are required */
#ifndef TPM_TIS_MAX_WAIT
#define TPM_TIS_MAX_WAIT   3
#endif

WOLFTPM_LOCAL int TPM2_TIS_GetBurstCount(TPM2_CTX* ctx, word16* burstCount);
WOLFTPM_LOCAL int TPM2_TIS_SendCommand(TPM2_CTX* ctx, TPM2_Packet* packet);
WOLFTPM_API int TPM2_TIS_ValidateRspSz(int rspSz, int packetSize);
WOLFTPM_LOCAL int TPM2_TIS_Ready(TPM2_CTX* ctx);
WOLFTPM_LOCAL int TPM2_TIS_WaitForStatus(TPM2_CTX* ctx, byte status, byte status_mask);
WOLFTPM_LOCAL int TPM2_TIS_Status(TPM2_CTX* ctx, byte* status);
WOLFTPM_LOCAL int TPM2_TIS_GetInfo(TPM2_CTX* ctx);
WOLFTPM_LOCAL int TPM2_TIS_RequestLocality(TPM2_CTX* ctx, int timeout);
WOLFTPM_LOCAL int TPM2_TIS_RequestLocalityEx(TPM2_CTX* ctx, int locality, int timeout);
WOLFTPM_LOCAL int TPM2_TIS_ReleaseLocality(TPM2_CTX* ctx, int locality);
WOLFTPM_LOCAL int TPM2_TIS_CheckLocality(TPM2_CTX* ctx, int locality, byte* access);
WOLFTPM_LOCAL int TPM2_TIS_StartupWait(TPM2_CTX* ctx, int timeout);
WOLFTPM_LOCAL int TPM2_TIS_Write(TPM2_CTX* ctx, word32 addr, const byte* value, word32 len);
WOLFTPM_LOCAL int TPM2_TIS_Read(TPM2_CTX* ctx, word32 addr, byte* result, word32 len);

#ifdef __cplusplus
    }  /* extern "C" */
#endif

#endif /* __TPM2_TIS_H__ */
