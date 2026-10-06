/* signature.h
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
    \file wolfssl/wolfcrypt/signature.h
*/


#ifndef WOLF_CRYPT_SIGNATURE_H
#define WOLF_CRYPT_SIGNATURE_H

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/hash.h>
#include <wolfssl/wolfcrypt/random.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* Minimum hash strength accepted by the wc_SignatureVerify/Generate
 * convenience APIs. Default is SHA-256 to keep MD5 and SHA-1 (both with
 * known collision attacks) out of new code. Define WC_SIG_MIN_HASH_TYPE
 * to a weaker wc_HashType (e.g. WC_HASH_TYPE_SHA) to opt back into legacy
 * behavior. The lower-level wc_SignatureVerifyHash/wc_SignatureGenerateHash
 * APIs are unaffected. */
#ifndef WC_SIG_MIN_HASH_TYPE
    #define WC_SIG_MIN_HASH_TYPE WC_HASH_TYPE_SHA256
#endif

enum wc_SignatureType {
    WC_SIGNATURE_TYPE_NONE = 0,
    WC_SIGNATURE_TYPE_ECC = 1,
    WC_SIGNATURE_TYPE_RSA = 2,
    WC_SIGNATURE_TYPE_RSA_W_ENC = 3 /* Adds DER header via wc_EncodeSignature */
};

WOLFSSL_API int wc_SignatureGetSize(enum wc_SignatureType sig_type,
    const void* key, word32 key_len);

WOLFSSL_API int wc_SignatureVerifyHash(
    enum wc_HashType hash_type, enum wc_SignatureType sig_type,
    const byte* hash_data, word32 hash_len,
    const byte* sig, word32 sig_len,
    void* key, word32 key_len);

WOLFSSL_API int wc_SignatureVerify(
    enum wc_HashType hash_type, enum wc_SignatureType sig_type,
    const byte* data, word32 data_len,
    const byte* sig, word32 sig_len,
    void* key, word32 key_len);

WOLFSSL_API int wc_SignatureGenerateHash(
    enum wc_HashType hash_type, enum wc_SignatureType sig_type,
    const byte* hash_data, word32 hash_len,
    byte* sig, word32 *sig_len,
    void* key, word32 key_len, WC_RNG* rng);
WOLFSSL_API int wc_SignatureGenerateHash_ex(
    enum wc_HashType hash_type, enum wc_SignatureType sig_type,
    const byte* hash_data, word32 hash_len,
    byte* sig, word32 *sig_len,
    void* key, word32 key_len, WC_RNG* rng, int verify);
WOLFSSL_API int wc_SignatureGenerate(
    enum wc_HashType hash_type, enum wc_SignatureType sig_type,
    const byte* data, word32 data_len,
    byte* sig, word32 *sig_len,
    void* key, word32 key_len,
    WC_RNG* rng);
WOLFSSL_API int wc_SignatureGenerate_ex(
    enum wc_HashType hash_type, enum wc_SignatureType sig_type,
    const byte* data, word32 data_len,
    byte* sig, word32 *sig_len,
    void* key, word32 key_len,
    WC_RNG* rng, int verify);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_SIGNATURE_H */
