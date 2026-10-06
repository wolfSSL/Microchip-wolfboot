/* sign1_mldsa.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Post-quantum COSE_Sign1 sign + verify with ML-DSA (FIPS 204).
 *
 * Full round trip: generate an ML-DSA-44 key, sign a payload into a
 * COSE_Sign1, then verify it. Requires wolfSSL built with ML-DSA
 * (./configure --enable-dilithium). For the verify-only on-device case see
 * sign1_verify_mldsa.c and the WOLFCOSE_LEAN_MLDSA build profile.
 */

#include <stdio.h>
#include <string.h>
#include <wolfcose/wolfcose.h>
#include <wolfssl/wolfcrypt/dilithium.h>
#include <wolfssl/wolfcrypt/random.h>

static const char PAYLOAD[] = "wolfCOSE ML-DSA payload";

/* ML-DSA messages and scratch are large; keep them off the stack. */
static uint8_t gScratch[20000];
static uint8_t gMsg[8192];

int main(void)
{
    wc_MlDsaKey    dlKey;
    WOLFCOSE_KEY   key;
    WOLFCOSE_HDR   hdr;
    WC_RNG         rng;
    const uint8_t* payload = NULL;
    size_t         payloadLen = 0;
    size_t         msgLen = 0;
    int            ret;
    int            rc = 1;

    if (wc_InitRng(&rng) != 0) {
        (void)printf("wc_InitRng failed\n");
        return 1;
    }

    ret = wc_MlDsaKey_Init(&dlKey, NULL, INVALID_DEVID);
    if (ret == 0) {
        ret = wc_MlDsaKey_SetParams(&dlKey, WC_ML_DSA_44);
    }
    if (ret == 0) {
        ret = wc_MlDsaKey_MakeKey(&dlKey, &rng);
    }
    if (ret == 0) {
        ret = wc_CoseKey_Init(&key);
    }
    if (ret == 0) {
        ret = wc_CoseKey_SetMlDsa(&key, WOLFCOSE_ALG_ML_DSA_44, &dlKey);
    }

    /* Sign */
    if (ret == 0) {
        ret = wc_CoseSign1_Sign(&key, WOLFCOSE_ALG_ML_DSA_44, NULL, 0,
                                (const uint8_t*)PAYLOAD, sizeof(PAYLOAD) - 1,
                                NULL, 0, NULL, 0,
                                gScratch, sizeof(gScratch),
                                gMsg, sizeof(gMsg), &msgLen, &rng);
    }
    if (ret == WOLFCOSE_SUCCESS) {
        (void)printf("ML-DSA-44 sign:   COSE_Sign1 produced, %u bytes\n",
                     (unsigned int)msgLen);
    }
    else {
        (void)printf("ML-DSA-44 sign failed (%d)\n", ret);
    }

    /* Verify the message we just signed */
    if (ret == WOLFCOSE_SUCCESS) {
        (void)memset(&hdr, 0, sizeof(hdr));
        ret = wc_CoseSign1_Verify(&key, gMsg, msgLen, NULL, 0, NULL, 0,
                                  gScratch, sizeof(gScratch), &hdr,
                                  &payload, &payloadLen);
    }
    if ((ret == WOLFCOSE_SUCCESS) &&
        (payloadLen == (sizeof(PAYLOAD) - 1)) && (payload != NULL) &&
        (memcmp(payload, PAYLOAD, payloadLen) == 0)) {
        (void)printf("ML-DSA-44 verify: OK, payload = \"%.*s\"\n",
                     (int)payloadLen, payload);
        rc = 0;
    }
    else if (ret == WOLFCOSE_SUCCESS) {
        (void)printf("ML-DSA-44 verify: payload mismatch\n");
    }
    else {
        (void)printf("ML-DSA-44 verify failed (%d)\n", ret);
    }

    wc_CoseKey_Free(&key);
    wc_MlDsaKey_Free(&dlKey);
    wc_FreeRng(&rng);
    return rc;
}
