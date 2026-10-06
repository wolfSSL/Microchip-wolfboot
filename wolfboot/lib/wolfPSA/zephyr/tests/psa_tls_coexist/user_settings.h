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

/*
 * wolfPSA / wolfSSL TLS coexistence settings file.
 *
 * The example feature set minus WOLFCRYPT_ONLY, so the wolfSSL TLS layer stays
 * in the build (psa_tls_coexist exercises TLS and wolfPSA on one shared
 * wolfCrypt core). Inherited rather than forked: a macro added to the example
 * must reach this target too.
 *
 * Point CONFIG_WOLFSSL_SETTINGS_FILE at it (the wolfPSA module root is on the
 * include path, so this zephyr/-relative name resolves):
 *
 *     CONFIG_WOLFSSL_SETTINGS_FILE="zephyr/tests/psa_tls_coexist/user_settings.h"
 */

#ifndef USER_SETTINGS_WOLFPSA_TLS_COEXIST_H
#define USER_SETTINGS_WOLFPSA_TLS_COEXIST_H

#include "zephyr/user_settings_example.h"

/* The only divergence: keep the TLS layer. */
#undef WOLFCRYPT_ONLY

#endif /* USER_SETTINGS_WOLFPSA_TLS_COEXIST_H */
