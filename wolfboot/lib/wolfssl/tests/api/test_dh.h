/* test_dh.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_DH_H
#define WOLFCRYPT_TEST_DH_H

#include <tests/api/api_decl.h>

int test_wc_DhPublicKeyDecode(void);
int test_wc_DhAgree_subgroup_check(void);
int test_wc_DhSetKey(void);
int test_wc_DhSetKey_ex_pseudoprime(void);
int test_wc_DhSetNamedKey_and_helpers(void);
int test_wc_DhGenerateKeyPair_bad_args(void);
int test_wc_DhGenerateKeyPair_and_Agree(void);
int test_wc_DhAgree_nonblock(void);
int test_wc_DhImportExportKeyPair(void);
int test_wc_DhCheckPubKey(void);
int test_wc_DhCheckPrivKey(void);
int test_wc_DhCheckKeyPair(void);
int test_wc_DhGenerateParams_and_ExportRaw(void);
int test_wc_DhGenerateKeyPair_CheckDhLN(void);

#define TEST_DH_DECLS                                              \
    TEST_DECL_GROUP("dh", test_wc_DhPublicKeyDecode),               \
    TEST_DECL_GROUP("dh", test_wc_DhAgree_subgroup_check),          \
    TEST_DECL_GROUP("dh", test_wc_DhSetKey),                        \
    TEST_DECL_GROUP("dh", test_wc_DhSetKey_ex_pseudoprime),         \
    TEST_DECL_GROUP("dh", test_wc_DhSetNamedKey_and_helpers),       \
    TEST_DECL_GROUP("dh", test_wc_DhGenerateKeyPair_bad_args),      \
    TEST_DECL_GROUP("dh", test_wc_DhGenerateKeyPair_and_Agree),     \
    TEST_DECL_GROUP("dh", test_wc_DhAgree_nonblock),                \
    TEST_DECL_GROUP("dh", test_wc_DhImportExportKeyPair),           \
    TEST_DECL_GROUP("dh", test_wc_DhCheckPubKey),                   \
    TEST_DECL_GROUP("dh", test_wc_DhCheckPrivKey),                  \
    TEST_DECL_GROUP("dh", test_wc_DhCheckKeyPair),                  \
    TEST_DECL_GROUP("dh", test_wc_DhGenerateParams_and_ExportRaw),  \
    TEST_DECL_GROUP("dh", test_wc_DhGenerateKeyPair_CheckDhLN)

#endif /* WOLFCRYPT_TEST_DH_H */
