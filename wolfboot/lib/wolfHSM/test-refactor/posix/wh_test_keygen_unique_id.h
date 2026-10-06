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
 * test-refactor/posix/wh_test_keygen_unique_id.h
 *
 * Concurrent keygen unique-id test. See the .c file for details.
 */

#ifndef WH_TEST_KEYGEN_UNIQUE_ID_H_
#define WH_TEST_KEYGEN_UNIQUE_ID_H_

/* Self-contained: spins up its own shared NVM and N client/server pairs.
 * Matches the whTestGroup_RunOne() entry-point contract; ctx is unused.
 * Returns WH_TEST_SUCCESS, WH_TEST_SKIPPED when the required build features
 * are absent, or a negative error code on failure. */
int whTest_KeygenUniqueIdConcurrent(void* ctx);

#endif /* WH_TEST_KEYGEN_UNIQUE_ID_H_ */
