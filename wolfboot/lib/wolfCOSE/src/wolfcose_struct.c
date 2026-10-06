/* wolfcose_struct.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/**
 * Unified Sig_structure/MAC_structure/Enc_structure builders.
 * RFC 9052 Sections 4.4, 5.3, 6.3.
 * All crypto via wolfCrypt wc_* APIs. Zero allocation.
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include "wolfcose_internal.h"
/* wolfcose.h (via internal.h) includes ecc.h, ed25519.h, ed448.h,
 * wc_mldsa.h (ML-DSA), rsa.h, random.h.  Only list headers not pulled in. */
#include <wolfssl/wolfcrypt/hash.h>
#include <wolfssl/wolfcrypt/error-crypt.h>
#include <wolfssl/wolfcrypt/memory.h>  /* XMEMCPY */
#if defined(WOLFCOSE_HAVE_AESGCM) || defined(WOLFCOSE_HAVE_AESCCM) || \
    defined(WOLFCOSE_HAVE_AESMAC) || defined(WOLFCOSE_KEY_WRAP)
    #include <wolfssl/wolfcrypt/aes.h>
#endif
#ifdef WOLFCOSE_HAVE_HMAC
    #include <wolfssl/wolfcrypt/hmac.h>
#endif
#if defined(WOLFCOSE_HAVE_CHACHA20)
    #include <wolfssl/wolfcrypt/chacha20_poly1305.h>
#endif
#include <string.h>


/* -----
 * Unified Structure Builders (Phase 3 refactoring)
 *
 * These shared helpers reduce code size by unifying:
 * - Sig_structure (Sign1/Sign): [context, body_prot, [sign_prot,] ext_aad, payload]
 * - MAC_structure (Mac0/Mac): [context, body_prot, ext_aad, payload]
 * - Enc_structure (Encrypt0/Encrypt): [context, body_prot, ext_aad]
 * ----- */

/**
 * Build a ToBeSigned/ToBeMAced structure (RFC 9052 Section 4.4, 6.3).
 *
 * For Sign1/Mac0/Mac: [context, body_protected, external_aad, payload]
 * For Sign (multi-signer): [context, body_protected, sign_protected, external_aad, payload]
 */
int wolfCose_BuildToBeSignedMaced(
    const uint8_t* context, size_t contextLen,
    const uint8_t* bodyProtected, size_t bodyProtectedLen,
    const uint8_t* signProtected, size_t signProtectedLen,
    const uint8_t* extAad, size_t extAadLen,
    const uint8_t* payload, size_t payloadLen,
    uint8_t* scratch, size_t scratchSz,
    size_t* structLen)
{
    int ret;
    WOLFCOSE_CBOR_CTX ctx;

    if ((context == NULL) || (scratch == NULL) || (structLen == NULL)) {
        ret = WOLFCOSE_E_INVALID_ARG;
    }
    else {
        size_t arrayLen;
        ctx.buf = scratch;
        ctx.bufSz = scratchSz;
        ctx.idx = 0;

        /* 4 elements normally, 5 if sign_protected is present (multi-signer) */
        arrayLen = (signProtected != NULL) ? (size_t)5 : (size_t)4;

        ret = wc_CBOR_EncodeArrayStart(&ctx, arrayLen);

        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeTstr(&ctx, context, contextLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeBstr(&ctx, bodyProtected, bodyProtectedLen);
        }
        if ((ret == WOLFCOSE_SUCCESS) && (signProtected != NULL)) {
            ret = wc_CBOR_EncodeBstr(&ctx, signProtected, signProtectedLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeBstr(&ctx, extAad, extAadLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeBstr(&ctx, payload, payloadLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            *structLen = ctx.idx;
        }
    }
    return ret;
}

#if (defined(WOLFCOSE_ENCRYPT0) || defined(WOLFCOSE_ENCRYPT)) && \
    (defined(WOLFCOSE_HAVE_AESGCM) || defined(WOLFCOSE_HAVE_AESCCM) || \
     defined(WOLFCOSE_HAVE_CHACHA20))
/**
 * Build an Enc_structure for AEAD operations (RFC 9052 Section 5.3).
 *
 * [context, body_protected, external_aad]
 */
int wolfCose_BuildEncStructure(
    const uint8_t* context, size_t contextLen,
    const uint8_t* bodyProtected, size_t bodyProtectedLen,
    const uint8_t* extAad, size_t extAadLen,
    uint8_t* scratch, size_t scratchSz,
    size_t* structLen)
{
    int ret;
    WOLFCOSE_CBOR_CTX ctx;

    if ((context == NULL) || (scratch == NULL) || (structLen == NULL)) {
        ret = WOLFCOSE_E_INVALID_ARG;
    }
    else {
        ctx.buf = scratch;
        ctx.bufSz = scratchSz;
        ctx.idx = 0;

        ret = wc_CBOR_EncodeArrayStart(&ctx, 3);

        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeTstr(&ctx, context, contextLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeBstr(&ctx, bodyProtected, bodyProtectedLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            ret = wc_CBOR_EncodeBstr(&ctx, extAad, extAadLen);
        }
        if (ret == WOLFCOSE_SUCCESS) {
            *structLen = ctx.idx;
        }
    }
    return ret;
}
#endif /* (ENCRYPT0 || ENCRYPT) && AEAD */
