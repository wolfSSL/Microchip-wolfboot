/* asu_rng.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ASU TRNG entropy for the wolfSSL crypto callback. Seeds the wolfCrypt Hash
 * DRBG from the ASU true random number generator. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_RNG_H
#define WOLFSSL_VERSAL_GEN2_ASU_RNG_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU_TRNG

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Single entry point for the ASU TRNG. The crypto callback dispatcher routes
 * both random number operations here and this handler decides which it is: seed
 * a DRBG (WC_ALGO_TYPE_SEED, fills info->seed) or serve random blocks
 * (WC_ALGO_TYPE_RNG, fills info->rng). The ASU TRNG returns at most one strength
 * block (32 bytes) per call, so larger requests are filled over several ASU
 * transactions. Returns 0 on success, CRYPTOCB_UNAVAILABLE for an unsupported
 * operation, or a negative error. */
WOLFSSL_LOCAL int wc_AsuRng(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU_TRNG */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_RNG_H */
