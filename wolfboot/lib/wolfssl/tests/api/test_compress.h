/* test_compress.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_COMPRESS_H
#define WOLFCRYPT_TEST_COMPRESS_H

#include <tests/api/api_decl.h>

int test_wc_CompressDecisionCoverage(void);
int test_wolfSSL_tls_compression(void);
int test_wolfSSL_tls_compression_multi_record(void);
int test_wolfSSL_tls_compression_client_hello(void);
int test_wolfSSL_tls13_compression_off(void);
int test_wolfSSL_tls_decompression_no_writeback(void);
int test_wolfSSL_tls_decompression_limit(void);
int test_wolfSSL_tls_decompression_lowered_limit(void);
int test_wolfSSL_tls_compression_output_size(void);
int test_wolfSSL_dtls_compression_off(void);

#define TEST_COMPRESS_DECLS                                                    \
    TEST_DECL_GROUP("compress", test_wc_CompressDecisionCoverage),             \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls_compression),                 \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls_compression_multi_record),    \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls_compression_client_hello),    \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls13_compression_off),           \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls_decompression_no_writeback),  \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls_decompression_limit),         \
    TEST_DECL_GROUP("compress",                                                \
        test_wolfSSL_tls_decompression_lowered_limit),                         \
    TEST_DECL_GROUP("compress", test_wolfSSL_tls_compression_output_size),     \
    TEST_DECL_GROUP("compress", test_wolfSSL_dtls_compression_off)

#endif /* WOLFCRYPT_TEST_COMPRESS_H */
