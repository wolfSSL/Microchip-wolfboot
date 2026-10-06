/*
 * Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfHSM.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
/*
 * test/wh_test_keywrap_util.h
 *
 * Helpers shared by the keywrap and SHE test suites (test/ and test-refactor/)
 * so the trusted-KEK test bytes and the wrapped-blob layout live in one place.
 */
#ifndef WH_TEST_KEYWRAP_UTIL_H_
#define WH_TEST_KEYWRAP_UTIL_H_

#include <stdint.h>

#include "wolfhsm/wh_settings.h"
#include "wolfhsm/wh_common.h" /* whKeyId */

/* KEK bytes shared by the keywrap/SHE tests. Each suite provisions this key
 * server-side (in NVM or the cache, with WH_NVM_FLAGS_TRUSTED) as its trusted
 * KEK and, where it builds blobs itself, wraps under the same bytes. The
 * bytes are fixed but arbitrary. */
extern const uint8_t whTest_KeywrapKek[32];

#if defined(WOLFHSM_CFG_SHE_EXTENSION) && defined(WOLFHSM_CFG_KEYWRAP) && \
    !defined(WOLFHSM_CFG_NO_CRYPTO)
/* Build an AES-GCM wrapped-key blob for a SHE key the same way the server's
 * KEK would, so a test can drive unwrap-and-cache without first having to get
 * the key into the server. Uses software AES with the known KEK bytes. Blob
 * layout matches the server: [IV(12) || authTag(16) || GCM(metadata || key)].
 * Only defined when AES-GCM is available (HAVE_AESGCM). */
int whTest_BuildSheKeyBlob(const uint8_t* kek, uint32_t kekSz, whKeyId sheKeyId,
                           uint32_t counter, uint32_t sheFlags,
                           const uint8_t* keyBytes, uint8_t* blobOut,
                           uint16_t* blobInOutSz);
#endif /* WOLFHSM_CFG_SHE_EXTENSION && WOLFHSM_CFG_KEYWRAP && \
          !WOLFHSM_CFG_NO_CRYPTO */

#endif /* WH_TEST_KEYWRAP_UTIL_H_ */
