/* asu_ecc.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ECDSA and EdDSA on the ASU. Curves we do not support run in software.
 * See asu_ecc.c. */

#ifndef WOLFSSL_VERSAL_GEN2_ASU_ECC_H
#define WOLFSSL_VERSAL_GEN2_ASU_ECC_H

#include <wolfssl/wolfcrypt/settings.h>

/* Nothing here exists in a build without ECC. */
#if defined(WOLFSSL_VERSAL_GEN2_ASU_ECC) && defined(HAVE_ECC) && \
    !defined(NO_ECC)

#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ECC entry point. Returns 0, CRYPTOCB_UNAVAILABLE to use software, or a
 * negative error. */
WOLFSSL_LOCAL int wc_AsuEcc(wc_CryptoInfo* info);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSL_VERSAL_GEN2_ASU_ECC && HAVE_ECC && !NO_ECC */

#endif /* WOLFSSL_VERSAL_GEN2_ASU_ECC_H */
