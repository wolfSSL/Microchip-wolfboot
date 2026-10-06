/* asu_hmac.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ASU HMAC for the wolfSSL crypto callback: HMAC over SHA2 256/384/512 and SHA3
 * 256/384/512. The message is accumulated per HMAC context and the whole HMAC is
 * produced in a single ASU operation at finalize. See asu_hmac.c for why. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_HMAC_H
#define WOLFSSL_VERSAL_GEN2_ASU_HMAC_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLFSSL_VERSAL_GEN2_ASU_HMAC

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Single entry point for the HMAC engine. The crypto callback dispatcher routes
 * every HMAC related operation here and this handler decides which it is: update
 * and final (WC_ALGO_TYPE_HMAC), context copy (WC_ALGO_TYPE_COPY) or context
 * release (WC_ALGO_TYPE_FREE). The message is accumulated per context and the
 * HMAC is computed in one ASU operation at final using the raw key wolfSSL
 * keeps on the context. Supports HMAC over SHA2 256/384/512 and SHA3
 * 256/384/512. Returns 0 on success, CRYPTOCB_UNAVAILABLE for an unsupported
 * MAC type or key (software fallback), or a negative error. */
WOLFSSL_LOCAL int wc_AsuHmac(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU_HMAC */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_HMAC_H */
