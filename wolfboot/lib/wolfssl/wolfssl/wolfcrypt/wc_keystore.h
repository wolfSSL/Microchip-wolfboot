/* wc_keystore.h
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
    \file wolfssl/wolfcrypt/wc_keystore.h
*/

#ifndef WOLF_CRYPT_KEYSTORE_H
#define WOLF_CRYPT_KEYSTORE_H

#include <wolfssl/wolfcrypt/settings.h>

#ifdef WOLF_CRYPTO_CB_KEYSTORE

/* The backing wc_CryptoCb_KeyStore* functions live inside WOLF_CRYPTO_CB, so
 * without it this header would advertise an API that does not link. */
#ifndef WOLF_CRYPTO_CB
    #error WOLF_CRYPTO_CB_KEYSTORE requires WOLF_CRYPTO_CB
#endif

#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/cryptocb.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* Lifecycle operations on a key held inside a hardware key store, which the
 * algorithm callbacks cannot express: those are bound to a wolfCrypt key
 * object. A key reference is the identifier WOLF_PRIVATE_KEY_ID already uses,
 * copied through without inspection. Full docs in doc/dox_comments. */

/* Place plaintext key material into the device's key store. The caller owns
 * the plaintext copy and should zeroize it once the import succeeds. */
WOLFSSL_API int wc_KeyStore_ImportPlain(int devId,
    const byte* keyRef, word32 keyRefSz,
    word32 keyType, const byte* key, word32 keySz,
    word32 attrs, const void* ctx);

/* Read a stored key back as plaintext. keySz is in/out: capacity on entry,
 * bytes written on return; key == NULL queries the size. */
WOLFSSL_API int wc_KeyStore_ExportPlain(int devId,
    const byte* keyRef, word32 keyRefSz,
    byte* key, word32* keySz, const void* ctx);

/* Unwrap a key blob directly into the device's key store. Nothing is returned:
 * on success the key exists at keyRef and its material was never in memory. */
WOLFSSL_API int wc_KeyStore_ImportWrapped(int devId,
    const byte* keyRef, word32 keyRefSz, word32 keyType,
    const byte* wrapKeyRef, word32 wrapKeyRefSz,
    word32 format, const byte* blob, word32 blobSz,
    word32 attrs, const void* ctx);

/* Wrap a stored key under wrapKeyRef and emit the blob. blobSz is in/out:
 * capacity on entry, bytes written on return; blob == NULL queries the size. */
WOLFSSL_API int wc_KeyStore_ExportWrapped(int devId,
    const byte* keyRef, word32 keyRefSz,
    const byte* wrapKeyRef, word32 wrapKeyRefSz,
    word32 format, byte* blob, word32* blobSz, const void* ctx);

/* Derive a new stored key from an existing one without either touching RAM.
 * keySz is the size in bytes of the key to create, or 0 to leave it to the
 * device; derivSz is algorithm-specific and often fixed by the hardware. */
WOLFSSL_API int wc_KeyStore_Derive(int devId,
    const byte* keyRef, word32 keyRefSz, word32 keyType, word32 keySz,
    const byte* srcKeyRef, word32 srcKeyRefSz,
    word32 kdfType, const byte* deriv, word32 derivSz,
    word32 attrs, const void* ctx);

/* Destroy a stored key. Deliberately separate from WC_ALGO_TYPE_FREE: freeing
 * a wolfCrypt key object must never destroy the hardware key it refers to. */
WOLFSSL_API int wc_KeyStore_Delete(int devId,
    const byte* keyRef, word32 keyRefSz, const void* ctx);

/* Report what a slot holds: key type, size in bits and attributes. Out
 * parameters the device does not fill are cleared. */
WOLFSSL_API int wc_KeyStore_GetInfo(int devId,
    const byte* keyRef, word32 keyRefSz,
    word32* keyType, word32* keyBits, word32* attrs, const void* ctx);

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPTO_CB_KEYSTORE */
#endif /* WOLF_CRYPT_KEYSTORE_H */
