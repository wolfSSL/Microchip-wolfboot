/*
 * Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfHSM.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
/*
 * wolfhsm/wh_client_cryptocb.h
 *
 */

#ifndef WOLFHSM_CLIENT_CRYPTOCB_H_
#define WOLFHSM_CLIENT_CRYPTOCB_H_

/* Pick up compile-time configuration */
#include "wolfhsm/wh_settings.h"

#ifndef WOLFHSM_CFG_NO_CRYPTO

#include "wolfssl/wolfcrypt/settings.h"
#include "wolfssl/wolfcrypt/types.h"
#include "wolfssl/wolfcrypt/cryptocb.h"

#include "wolfhsm/wh_client.h"

/* Unified cryptoCb, registered for WH_DEV_ID and the client's configured
 * devId. Dispatches to the DMA path when the client's DMA mode is set (see
 * wh_Client_SetDmaMode), falling back to the standard path for algorithms
 * without a DMA variant; otherwise uses the standard path directly. */
int wh_Client_CryptoCb(int devId, wc_CryptoInfo* info, void* ctx);

/* Standard (non-DMA) cryptoCb */
int wh_Client_CryptoCbStd(int devId, wc_CryptoInfo* info, void* ctx);

#ifdef WOLFHSM_CFG_DMA
/* DMA-only cryptoCb, registered for WH_DEV_ID_DMA. No standard-path fallback:
 * algorithms without a DMA variant return CRYPTOCB_UNAVAILABLE.
 */
int wh_Client_CryptoCbDma(int devId, wc_CryptoInfo* info, void* inCtx);
#endif /* WOLFHSM_CFG_DMA */

#endif /* !WOLFHSM_CFG_NO_CRYPTO */

#endif /* !WOLFHSM_CLIENT_CRYPTOCB_H_ */
