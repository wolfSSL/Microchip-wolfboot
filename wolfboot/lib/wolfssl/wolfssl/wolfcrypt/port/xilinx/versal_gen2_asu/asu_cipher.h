/* asu_cipher.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ASU symmetric cipher engine for the wolfSSL crypto callback: AES-CBC, ECB,
 * CTR, CFB, OFB, GCM and CCM offload (128/256 bit keys). AES-192 uses software. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_CIPHER_H
#define WOLFSSL_VERSAL_GEN2_ASU_CIPHER_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU_CIPHER

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Single entry point for the cipher engine. Returns 0 on success,
 * CRYPTOCB_UNAVAILABLE for software fallback, or a negative error. */
WOLFSSL_LOCAL int wc_AsuCipher(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU_CIPHER */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_CIPHER_H */
