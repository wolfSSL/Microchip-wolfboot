/* libwolfssl_sources_asm.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* In wolfSSL library sources, #include this file before any other #includes, to
 * assure BUILDING_WOLFSSL is defined.
 *
 * This file also includes the common headers needed by all sources.
 */

#ifndef LIBWOLFSSL_SOURCES_ASM_H
#define LIBWOLFSSL_SOURCES_ASM_H

#if defined(TEST_LIBWOLFSSL_SOURCES_INCLUSION_SEQUENCE) && \
    defined(WOLF_CRYPT_SETTINGS_H) &&                      \
    !defined(LIBWOLFSSL_SOURCES_H)
    #error settings.h included before libwolfssl_sources_asm.h.
#endif

#ifndef BUILDING_WOLFSSL
    #define BUILDING_WOLFSSL
#endif
#ifndef BUILDING_WOLFSSL_ASM
    #define BUILDING_WOLFSSL_ASM
#endif

#if defined(HAVE_CONFIG_H) && !defined(WC_CONFIG_H_INCLUDED)
    #include <config.h>
    #define WC_CONFIG_H_INCLUDED
#endif

/* Generated assembly is guarded by the same feature macros as the C sources
 * (e.g. WOLFSSL_SHA512).  In an autoconf build those macros are not in config.h
 * - they live in wolfssl/options.h - so pull them in here, before settings.h,
 * so the assembler sees the same configuration as the compiler.  This is a
 * custom configuration method (options.h consumed directly), so tell settings.h
 * not to warn about options.h in a library object. */
#if defined(HAVE_CONFIG_H) && !defined(WOLFSSL_USER_SETTINGS)
    #ifndef WOLFSSL_CUSTOM_CONFIG
        #define WOLFSSL_CUSTOM_CONFIG
    #endif
    #include <wolfssl/options.h>
#endif

#include <wolfssl/wolfcrypt/settings.h>

#endif /* LIBWOLFSSL_SOURCES_ASM_H */
