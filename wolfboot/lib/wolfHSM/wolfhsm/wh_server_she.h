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
 * wolfhsm/wh_server_she.h
 *
 */

#ifndef WOLFHSM_WH_SERVER_SHE_H
#define WOLFHSM_WH_SERVER_SHE_H

/* Pick up compile-time configuration */
#include "wolfhsm/wh_settings.h"

#include <stdint.h>

#include "wolfhsm/wh_server.h"

#ifndef WOLFHSM_CFG_NO_CRYPTO
#include "wolfssl/wolfcrypt/settings.h"
#include "wolfssl/wolfcrypt/types.h"
#include "wolfssl/wolfcrypt/aes.h"
#include "wolfssl/wolfcrypt/cmac.h"
#endif /* !WOLFHSM_CFG_NO_CRYPTO */

#if defined(WOLFHSM_CFG_SHE_EXTENSION)

/* Reads WH_SHE_UID_SZ bytes into outUid. Returns 0, WH_ERROR_NOTFOUND if no UID
 * is provisioned, or another wolfHSM error. A NULL outUid reports provisioning
 * status only and must not transfer any bytes. Called on every gated SHE
 * request, so it must be cheap and idempotent. */
typedef int (*whServerSheGetUidCb)(void* ctx, uint8_t* outUid);

/* Persists the WH_SHE_UID_SZ byte UID provisioned by WH_SHE_SET_UID. */
typedef int (*whServerSheSetUidCb)(void* ctx, const uint8_t* uid);

typedef struct {
    whServerSheGetUidCb getUidCb; /* NULL = use in-context uid[]/uidSet */
    whServerSheSetUidCb setUidCb; /* NULL = UID is read-only */
    void*               uidCtx;   /* opaque, passed back to both callbacks */
} whServerSheConfig;

typedef struct {
    uint8_t  sbState;
    uint8_t  cmacKeyFound;
    uint8_t  ramKeyPlain;
    uint8_t  uidSet;
    uint32_t blSize;
    uint32_t blSizeReceived;
    uint32_t rndInited;

#ifndef WOLFHSM_CFG_NO_CRYPTO
#ifndef NO_AES
    Aes sheAes[1];
#endif /* !NO_AES*/
#ifdef WOLFSSL_CMAC
    Cmac sheCmac[1];
#endif /* WOLFSSL_CMAC */
#endif /* !WOLFHSM_CFG_NO_CRYPTO*/

    uint8_t  prngState[WH_SHE_KEY_SZ];
    uint8_t  prngKey[WH_SHE_KEY_SZ];
    uint8_t  uid[WH_SHE_UID_SZ];

    /* When getUidCb is set, the uid[] and uidSet fields above are unused. */
    whServerSheGetUidCb getUidCb;
    whServerSheSetUidCb setUidCb;
    void*               uidCtx;
} whServerSheContext;

int wh_Server_HandleSheRequest(whServerContext* server, uint16_t magic,
                               uint16_t action, uint16_t req_size,
                               const void* req_packet, uint16_t* out_resp_size,
                               void* resp_packet);

/**
 * @brief Register SHE UID storage callbacks at runtime.
 *
 * Replaces callbacks previously set via whServerConfig.sheConfig or by a prior
 * call to this function.
 *
 * @param server Server context.
 * @param getCb  UID read callback, or NULL to use in-context uid[]/uidSet.
 * @param setCb  UID write callback, or NULL for a read-only UID, which makes
 *               WH_SHE_SET_UID return WH_SHE_ERC_WRITE_PROTECTED.
 * @param ctx    Opaque context passed to both callbacks.
 * @return WH_ERROR_OK on success, WH_ERROR_BADARGS if server or server->she is
 *         NULL.
 */
int wh_Server_SheSetUidCb(whServerContext* server, whServerSheGetUidCb getCb,
                          whServerSheSetUidCb setCb, void* ctx);
#endif /* WOLFHSM_CFG_SHE_EXTENSION */

#endif /* !WOLFHSM_WH_SERVER_SHE_H */
