/* asu_ecdh.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ECDH shared secret on the ASU. Curves we do not support run in software.
 * See asu_ecdh.c. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_ECDH_H
#define WOLFSSL_VERSAL_GEN2_ASU_ECDH_H

#include <wolfssl/wolfcrypt/settings.h>

/* Turned on from the ECC macros, and compiles to nothing without them. */
#if defined(WOLFSSL_VERSAL_GEN2_ASU_ECDH) && defined(HAVE_ECC) && \
    !defined(NO_ECC) && defined(HAVE_ECC_DHE)
    #define WC_ASU_ECDH_ENABLED
#endif

#ifdef WC_ASU_ECDH_ENABLED

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ECDH entry point. Returns 0, CRYPTOCB_UNAVAILABLE to use software, or a
 * negative error. */
WOLFSSL_LOCAL int wc_AsuEcdh(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WC_ASU_ECDH_ENABLED */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_ECDH_H */
