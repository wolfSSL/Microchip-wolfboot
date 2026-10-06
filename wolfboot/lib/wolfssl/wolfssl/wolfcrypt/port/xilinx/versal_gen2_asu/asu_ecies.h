/* asu_ecies.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ECIES on the ASU, which does the ECDH, key derivation and AES-GCM.
 * See asu_ecies.c. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_ECIES_H
#define WOLFSSL_VERSAL_GEN2_ASU_ECIES_H

#include <wolfssl/wolfcrypt/settings.h>

/* Turned on from the ECC and AES macros. Only the default scheme is used. */
#if defined(WOLFSSL_VERSAL_GEN2_ASU_ECIES) && defined(HAVE_ECC) && \
    !defined(NO_ECC) && defined(HAVE_ECC_ENCRYPT) && !defined(NO_AES) && \
    defined(HAVE_AESGCM) && defined(WOLFSSL_ECIES_GEN_IV) && \
    !defined(WOLFSSL_ECIES_OLD) && !defined(WOLFSSL_ECIES_ISO18033)
    #define WC_ASU_ECIES_ENABLED
#endif

#ifdef WC_ASU_ECIES_ENABLED

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ECIES entry point. Returns 0, CRYPTOCB_UNAVAILABLE to use software, or a
 * negative error. */
WOLFSSL_LOCAL int wc_AsuEcies(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WC_ASU_ECIES_ENABLED */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_ECIES_H */
