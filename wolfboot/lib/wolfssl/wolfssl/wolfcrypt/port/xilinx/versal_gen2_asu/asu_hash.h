/* asu_hash.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ASU hashing for the wolfSSL crypto callback: SHA2 256/384/512 and SHA3
 * 256/384/512. The message is accumulated per hash context and hashed in a
 * single ASU operation at finalize. See asu_hash.c for why. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_HASH_H
#define WOLFSSL_VERSAL_GEN2_ASU_HASH_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU_HASH

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Single entry point for the SHA2/SHA3 engine. The crypto callback dispatcher
 * routes every hash related operation here and this handler decides which it is:
 * update and final (WC_ALGO_TYPE_HASH), context copy (WC_ALGO_TYPE_COPY), or
 * context release (WC_ALGO_TYPE_FREE). Supports SHA2 256/384/512 and SHA3
 * 256/384/512. Returns 0 on success, CRYPTOCB_UNAVAILABLE for an unsupported
 * operation or hash type (software fallback), or a negative error. */
WOLFSSL_LOCAL int wc_AsuHash(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU_HASH */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_HASH_H */
