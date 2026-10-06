/* test_tls_parse.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_TLS_PARSE_H
#define TESTS_API_TEST_TLS_PARSE_H

int test_TLSX_ALPN_parse(void);
int test_TLSX_TCA_parse(void);
int test_TLSX_certtype_parse(void);
int test_TLSX_Cookie_parse(void);
int test_TLSX_EncryptThenMac_parse(void);
int test_TLSX_MFL_parse(void);
int test_TLSX_THM_parse(void);
int test_TLSX_SessionTicket_parse(void);
int test_TLSX_SecureRenegotiation_parse(void);
int test_TLSX_SupportedVersions_parse(void);
int test_TLSX_SignatureAlgorithms_parse(void);
int test_TLSX_CSR_parse(void);
int test_TLSX_PointFormat_parse(void);
int test_TLSX_SNI_parse(void);
int test_TLSX_ValidateSupportedCurves(void);
int test_TLSX_SupportedGroups_parse(void);
int test_TLSX_KeyShare_negotiate(void);
int test_TLSX_KeyShare_gen(void);
int test_TLSX_KeyShare_freesizewrite(void);
int test_TLSX_KeyShare_process(void);

#define TEST_TLS_PARSE_DECLS                                               \
        TEST_DECL_GROUP("tls", test_TLSX_ALPN_parse),                     \
        TEST_DECL_GROUP("tls", test_TLSX_TCA_parse),                      \
        TEST_DECL_GROUP("tls", test_TLSX_certtype_parse),                 \
        TEST_DECL_GROUP("tls", test_TLSX_Cookie_parse),                   \
        TEST_DECL_GROUP("tls", test_TLSX_EncryptThenMac_parse),           \
        TEST_DECL_GROUP("tls", test_TLSX_MFL_parse),                      \
        TEST_DECL_GROUP("tls", test_TLSX_THM_parse),                      \
        TEST_DECL_GROUP("tls", test_TLSX_SessionTicket_parse),            \
        TEST_DECL_GROUP("tls", test_TLSX_SecureRenegotiation_parse),      \
        TEST_DECL_GROUP("tls", test_TLSX_SupportedVersions_parse),        \
        TEST_DECL_GROUP("tls", test_TLSX_SignatureAlgorithms_parse),      \
        TEST_DECL_GROUP("tls", test_TLSX_CSR_parse),                      \
        TEST_DECL_GROUP("tls", test_TLSX_PointFormat_parse),              \
        TEST_DECL_GROUP("tls", test_TLSX_SNI_parse),                      \
        TEST_DECL_GROUP("tls", test_TLSX_ValidateSupportedCurves),        \
        TEST_DECL_GROUP("tls", test_TLSX_SupportedGroups_parse),         \
        TEST_DECL_GROUP("tls", test_TLSX_KeyShare_negotiate),             \
        TEST_DECL_GROUP("tls", test_TLSX_KeyShare_gen),                   \
        TEST_DECL_GROUP("tls", test_TLSX_KeyShare_freesizewrite),         \
        TEST_DECL_GROUP("tls", test_TLSX_KeyShare_process)

#endif /* TESTS_API_TEST_TLS_PARSE_H */
