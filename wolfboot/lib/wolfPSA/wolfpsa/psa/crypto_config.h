/* crypto_config.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFPSA_CRYPTO_CONFIG_H
#define WOLFPSA_CRYPTO_CONFIG_H

#if defined(CONFIG_WOLFPSA)

/* Zephyr build: derive the PSA_WANT_* surface from the consumer's Kconfig
 * (CONFIG_PSA_WANT_*) instead of the small hardcoded list below, so that the
 * size macros in crypto_sizes.h and any PSA_WANT_*-gated consumer code match
 * whatever capabilities the application enabled. */
#include "crypto_config_zephyr.h"

#else /* standalone (Makefile) build */

#define PSA_WANT_ALG_SHA_1
#define PSA_WANT_ALG_SHA_224
#define PSA_WANT_ALG_SHA_256
#define PSA_WANT_ALG_SHA_384
#define PSA_WANT_ALG_SHA_512

#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC
#define PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY

#define PSA_WANT_KEY_TYPE_ML_DSA
#define PSA_WANT_KEY_TYPE_ML_KEM

#endif /* CONFIG_WOLFPSA */

#endif
