/* wolfcrypt/wc_compat.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
/*!
    \file ../wolfssl/wolfcrypt/wc_compat.h
    \brief Header file containing wolfCrypt compatibility shims
*/

#if defined(WC_NO_COMPAT_H_REMAPS) ||                                        \
    (defined(WOLF_CRYPT_SHA256_H) && !defined(NO_SHA256) &&                  \
     !defined(WC_SHA256_TYPE_DEFINED) && !defined(SHA256_NOINLINE)) ||       \
    (defined(WOLF_CRYPT_SHA512_H) &&                                         \
     (defined(WOLFSSL_SHA512) || defined(WOLFSSL_SHA384)) &&                 \
     !defined(WC_SHA512_TYPE_DEFINED) && !defined(WC_SHA384_TYPE_DEFINED) && \
     !defined(SHA512_NOINLINE)) ||                                           \
    (defined(WOLF_CRYPT_AES_H) && !defined(NO_AES) &&                        \
     !defined(WC_AES_TYPE_DEFINED) && !defined(CTAO_CRYPT_AES_H)) ||         \
    (defined(WOLF_CRYPT_RANDOM_H) && !defined(WC_RNG_TYPE_DEFINED)) ||       \
    (defined(WOLF_CRYPT_FIPS_H) && !defined(WOLFSSL_FIPS_DEV_NO_POST) &&     \
     !defined(fipsCastStatus_get) && !defined(wc_Des3_SetKey) &&             \
     !defined(WC_DES3_TYPE_DEFINED)) ||                                      \
    (defined(WOLF_CRYPT_FIPS_TEST_H) &&                                      \
     !defined(WC_FIPS_ENUM_CAST_ID_DEFINED) && !defined(WOLF_CRYPT_FIPS_H))

    /* Inhibit wc_compat.h during inclusion of sha256.h, sha512.h, aes.h,
     * random.h, fips.h, and fips_test.h, to mitigate circular dependencies.
     */

#else /* Circular dependency deferral check passed */

#ifndef wolfSSL_WOLFCRYPT_WC_COMPAT_H
#define wolfSSL_WOLFCRYPT_WC_COMPAT_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef __cplusplus
    extern "C" {
#endif

#if defined(HAVE_FIPS) && defined(HAVE_AESGCM) && \
    !defined(WC_FIPS_AESGCM_ONE_SHOT_EXT_IV_ALLOWED)

    /* Unless WC_FIPS_AESGCM_ONE_SHOT_EXT_IV_ALLOWED, wc_AesGcmEncrypt() is a
     * non-FIPS API hardwired to FIPS_WRONG_API_E in fips.c.  But we can emulate
     * it with FIPS calls as below.
     */

    #undef wc_AesGcmEncrypt
    #include <wolfssl/wolfcrypt/aes.h>
    #undef wc_AesGcmEncrypt

    #define wc_AesGcmEncrypt wc_AesGcmEncrypt_compat_shim

    #ifdef WOLFSSL_AESGCM_STREAM

    static WC_INLINE int wc_AesGcmEncrypt_compat_shim(Aes* aes, byte* out, const byte* in, word32 sz,
                       const byte* iv, word32 ivSz,
                       byte* authTag, word32 authTagSz,
                       const byte* authIn, word32 authInSz)
    {
        int ret;

    #if FIPS_VERSION3_EQ(6,0,0)
        /* FIPS v6 doesn't robustly validate authTagSz in wc_AesGcmEncryptFinal(). */
        if (authTagSz < WOLFSSL_MIN_AUTH_TAG_SZ)
            return BAD_FUNC_ARG;
    #endif
        ret = wc_AesGcmInit(aes, NULL /* key */, 0 /* len */, iv, ivSz);
        if (ret)
            return ret;
        ret = wc_AesGcmEncryptUpdate(aes, out, in, sz, authIn, authInSz);
        if (ret)
            return ret;
        return wc_AesGcmEncryptFinal(aes, authTag, authTagSz);
    }

    #else /* ! WOLFSSL_AESGCM_STREAM */

    /* Note this variant of the shim can't handle nonstandard-size IVs. */
    #define WC_TEST_AES_GCM_ENCRYPT_NO_NONSTD_IV

    static WC_INLINE int wc_AesGcmEncrypt_compat_shim(Aes* aes, byte* out, const byte* in, word32 sz,
                           const byte* iv, word32 ivSz,
                           byte* authTag, word32 authTagSz,
                           const byte* authIn, word32 authInSz)
    {
        int ret;
        byte scratch[16]; /* FIPS v2 doesn't have GCM_NONCE_MAX_SZ */

        if (ivSz > sizeof(scratch))
            return BAD_LENGTH_E;

        ret = wc_AesGcmSetExtIV(aes, iv, ivSz);
        if (ret != 0)
            return ret;
        ret = wc_AesGcmEncrypt_ex(aes, out, in, sz, scratch, ivSz, authTag,
                                 authTagSz, authIn, authInSz);
        if (ret != 0)
            return ret;
        return wc_AesGcmSetExtIV(aes, iv, ivSz);
    }
    #endif /* ! WOLFSSL_AESGCM_STREAM */
#endif /* HAVE_FIPS && HAVE_AESGCM &&                  */
       /* !WC_FIPS_AESGCM_ONE_SHOT_EXT_IV_ALLOWED &&   */
       /* !FIPS_NO_WRAPPERS && !WOLF_CRYPT_FIPS_TEST_H */


#ifdef __cplusplus
    }
#endif

#endif /* !wolfSSL_WOLFCRYPT_WC_COMPAT_H */

#endif /* Circular dependency deferral check passed */
