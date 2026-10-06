/* user_settings.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFSSL_USER_SETTINGS_H
#define WOLFSSL_USER_SETTINGS_H

/* The build-config-matrix harness drives every algorithm feature via
 * wolfcrypt-native defines passed on the compiler command line by
 * build-test/build-variant.sh. This file only sets up invariants that are
 * always required (or always forbidden) regardless of the lane. */

#define WOLFCRYPT_ONLY
#define SINGLE_THREADED
#define WOLFSSL_PSA_ENGINE
#define NO_DSA
/* Constant-time AES, required by src/psa_config.h unless WOLFPSA_AES_FAST is
 * set. Selected here rather than in the BASELINE list so the aes-ecb lane can
 * strip it together with HAVE_AES_ECB, which wolfCrypt requires alongside it. */
#if !defined(WOLFPSA_AES_FAST) && !defined(WOLFPSA_NO_AES_BITSLICED)
#define WC_AES_BITSLICED
#endif
/* psa_sign_hash()/psa_verify_hash() must accept an all-zero digest (PSA
 * treats the hash as opaque bytes); wolfCrypt rejects it by default, so opt
 * out. src/psa_config.h #errors when HAVE_ECC is on and this is undefined. */
#define WC_ALLOW_ECC_ZERO_HASH

#endif /* WOLFSSL_USER_SETTINGS_H */
