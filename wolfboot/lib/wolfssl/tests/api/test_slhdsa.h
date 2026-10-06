/* test_slhdsa.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_SLHDSA_H
#define WOLFCRYPT_TEST_SLHDSA_H

#include <tests/api/api_decl.h>

int test_wc_slhdsa(void);
int test_wc_slhdsa_sizes(void);
int test_wc_slhdsa_make_key(void);
int test_wc_slhdsa_sign(void);
int test_wc_slhdsa_verify(void);
int test_wc_slhdsa_sign_vfy(void);
int test_wc_slhdsa_sign_hash(void);
int test_wc_slhdsa_sign_msg(void);
int test_wc_slhdsa_sign_addrnd(void);
int test_wc_slhdsa_dev_only_key(void);
int test_wc_slhdsa_export_import(void);
int test_wc_slhdsa_check_key(void);
int test_wc_slhdsa_der_roundtrip(void);
int test_wc_slhdsa_der_negative(void);
int test_wc_slhdsa_der_decode_files(void);
int test_wc_slhdsa_x509_i2d_roundtrip(void);
int test_wc_slhdsa_param_disabled(void);
int test_wc_slhdsa_decoder_disabled_oid(void);
int test_wc_SlhdsaDecisionCoverage(void);
int test_wc_SlhdsaFeatureCoverage(void);
int test_slhdsa_tls13_certverify_want_write(void);
int test_slhdsa_get_sigalg_info(void);
int test_slhdsa_tls12_client_cert_rejected(void);
int test_slhdsa_tls13_certverify_multi_stall(void);
int test_mldsa_tls13_certverify_maxfrag_stream(void);
int test_slhdsa_dev_private_key(void);
int test_slhdsa_tls13_certverify_bad_signature(void);
int test_slhdsa_cb_free(void);

#define TEST_SLHDSA_DECLS                                                      \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa),                                 \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_sizes),                           \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_make_key),                        \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_sign),                            \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_verify),                          \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_sign_vfy),                        \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_sign_hash),                       \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_sign_msg),                        \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_sign_addrnd),                     \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_dev_only_key),                    \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_export_import),                   \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_check_key),                       \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_der_roundtrip),                   \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_der_negative),                    \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_der_decode_files),                \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_x509_i2d_roundtrip),              \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_param_disabled),                  \
    TEST_DECL_GROUP("slhdsa", test_wc_slhdsa_decoder_disabled_oid),            \
    TEST_DECL_GROUP("slhdsa", test_wc_SlhdsaDecisionCoverage),                 \
    TEST_DECL_GROUP("slhdsa", test_wc_SlhdsaFeatureCoverage),                  \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_tls13_certverify_want_write),        \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_get_sigalg_info),                    \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_tls12_client_cert_rejected),        \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_tls13_certverify_multi_stall),      \
    TEST_DECL_GROUP("slhdsa", test_mldsa_tls13_certverify_maxfrag_stream),   \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_dev_private_key),                   \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_tls13_certverify_bad_signature),     \
    TEST_DECL_GROUP("slhdsa", test_slhdsa_cb_free)

#endif /* WOLFCRYPT_TEST_SLHDSA_H */
