/* test_frodokem.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_FRODOKEM_H
#define WOLFCRYPT_TEST_FRODOKEM_H

#include <tests/api/api_decl.h>

int test_wc_frodokem_make_key_kats(void);
int test_wc_frodokem_encapsulate_kats(void);
int test_wc_frodokem_decapsulate_kats(void);
int test_wc_frodokem_roundtrip(void);
int test_wc_frodokem_encode_decode(void);
int test_wc_frodokem_decap_implicit_reject(void);
int test_wc_frodokem_decapsulate_pubonly_fails(void);
int test_wc_frodokem_decode_privkey_bad_pkh(void);
int test_wc_frodokem_bad_args(void);
int test_wc_frodokem_op_len_checks(void);
int test_wc_frodokem_new_delete(void);
int test_wc_frodokem_not_compiled_in(void);
int test_wc_frodokem_asn1(void);
int test_wc_frodokem_key_pem(void);
int test_wc_frodokem_x509(void);
int test_wc_frodokem_cert_file(void);
int test_wc_frodokem_cert_verify(void);
int test_wc_frodokem_cb_pending_rejected(void);

#define TEST_FRODOKEM_DECLS                                                 \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_make_key_kats),            \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_encapsulate_kats),         \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_decapsulate_kats),         \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_roundtrip),                \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_encode_decode),            \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_decap_implicit_reject),    \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_decapsulate_pubonly_fails),\
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_decode_privkey_bad_pkh),   \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_bad_args),                 \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_op_len_checks),            \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_new_delete),               \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_not_compiled_in),          \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_asn1),                     \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_key_pem),                  \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_x509),                     \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_cert_file),                \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_cert_verify),          \
    TEST_DECL_GROUP("frodokem", test_wc_frodokem_cb_pending_rejected)

#endif /* WOLFCRYPT_TEST_FRODOKEM_H */
