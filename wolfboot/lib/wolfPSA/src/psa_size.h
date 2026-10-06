/* psa_size.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFPSA_SIZE_H
#define WOLFPSA_SIZE_H

#include <stdint.h>

#include <psa/crypto.h>
#include <wolfssl/wolfcrypt/hash.h>

/* PSA_HASH_MAX_SIZE is derived from the PSA_WANT_ALG_SHA* set, which can be
 * smaller than the largest digest this hash engine accepts when XOFs are
 * enabled (a SHAKE256-only build exposes 64-byte SHAKE256-512 output while
 * PSA_HASH_MAX_SIZE stays 32). Internal scratch buffers that must fit any
 * accepted hash use this bound instead. */
#define WOLFPSA_HASH_MAX_SIZE \
    (PSA_HASH_MAX_SIZE >= WC_MAX_DIGEST_SIZE ? PSA_HASH_MAX_SIZE \
                                             : WC_MAX_DIGEST_SIZE)

static inline psa_status_t wolfpsa_check_word32_length(size_t length)
{
    if (length > UINT32_MAX) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    return PSA_SUCCESS;
}

#endif /* WOLFPSA_SIZE_H */
