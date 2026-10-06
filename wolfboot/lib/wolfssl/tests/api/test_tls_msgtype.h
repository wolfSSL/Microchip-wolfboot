/* test_tls_msgtype.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_TLS_MSGTYPE_H
#define TESTS_API_TEST_TLS_MSGTYPE_H

int test_tls_msgtype_arg_guard(void);
int test_tls_msgtype_psk_duplicate(void);
int test_tls_msgtype_certificate_ext_offered(void);
int test_tls_msgtype_sni_tls13(void);
int test_tls_msgtype_sni_tls12(void);
int test_tls_msgtype_tca(void);
int test_tls_msgtype_mfl_tls13(void);
int test_tls_msgtype_mfl_tls12(void);
int test_tls_msgtype_supported_groups_tls13(void);
int test_tls_msgtype_point_formats(void);
int test_tls_msgtype_csr_tls13(void);
int test_tls_msgtype_csr_tls12(void);
int test_tls_msgtype_csr2_tls12(void);
int test_tls_msgtype_extms(void);
int test_tls_msgtype_renegotiation_info(void);
int test_tls_msgtype_session_ticket_tls12(void);
int test_tls_msgtype_alpn_tls13(void);
int test_tls_msgtype_alpn_tls12(void);
int test_tls_msgtype_sigalgs_tls13(void);
int test_tls_msgtype_etm(void);
int test_tls_msgtype_supported_versions(void);
int test_tls_msgtype_cookie(void);
int test_tls_msgtype_psk(void);
int test_tls_msgtype_cert_with_extern_psk(void);
int test_tls_msgtype_early_data(void);
int test_tls_msgtype_sigalgs_cert(void);
int test_tls_msgtype_key_share(void);
int test_tls_msgtype_client_cert_type_tls13(void);
int test_tls_msgtype_client_cert_type_tls12(void);
int test_tls_msgtype_server_cert_type_tls13(void);
int test_tls_msgtype_server_cert_type_tls12(void);
int test_tls_msgtype_connection_id(void);
int test_tls_msgtype_ech(void);
int test_tls_msgtype_sni_find(void);
int test_tls_msgtype_sni_parse_response_gate(void);
int test_tls_msgtype_sni_parse_size_gates(void);
int test_tls_msgtype_sni_parse_cacheonly(void);
int test_tls_msgtype_sni_parse_match(void);
int test_tls_msgtype_sni_parse_ech_public(void);
int test_tls_msgtype_psk_ch_id_gates(void);
int test_tls_msgtype_psk_ch_binder_gates(void);
int test_tls_msgtype_psk_sh_index(void);
int test_tls_msgtype_psk_sh_resumption(void);
int test_tls_msgtype_cookie_parse_gates(void);
int test_tls_msgtype_tca_parse_gates(void);
int test_tls_msgtype_tca_find(void);
int test_tls_msgtype_tca_new_alloc(void);
int test_tls_msgtype_psk_write_chosen(void);

#define TEST_TLS_MSGTYPE_DECLS                                               \
        TEST_DECL_GROUP("tls", test_tls_msgtype_arg_guard),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk_duplicate),             \
        TEST_DECL_GROUP("tls", test_tls_msgtype_certificate_ext_offered),   \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_tls13),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_tls12),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_tca),                       \
        TEST_DECL_GROUP("tls", test_tls_msgtype_mfl_tls13),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_mfl_tls12),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_supported_groups_tls13),    \
        TEST_DECL_GROUP("tls", test_tls_msgtype_point_formats),             \
        TEST_DECL_GROUP("tls", test_tls_msgtype_csr_tls13),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_csr_tls12),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_csr2_tls12),                \
        TEST_DECL_GROUP("tls", test_tls_msgtype_extms),                     \
        TEST_DECL_GROUP("tls", test_tls_msgtype_renegotiation_info),        \
        TEST_DECL_GROUP("tls", test_tls_msgtype_session_ticket_tls12),      \
        TEST_DECL_GROUP("tls", test_tls_msgtype_alpn_tls13),                \
        TEST_DECL_GROUP("tls", test_tls_msgtype_alpn_tls12),                \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sigalgs_tls13),             \
        TEST_DECL_GROUP("tls", test_tls_msgtype_etm),                       \
        TEST_DECL_GROUP("tls", test_tls_msgtype_supported_versions),        \
        TEST_DECL_GROUP("tls", test_tls_msgtype_cookie),                    \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk),                       \
        TEST_DECL_GROUP("tls", test_tls_msgtype_cert_with_extern_psk),      \
        TEST_DECL_GROUP("tls", test_tls_msgtype_early_data),                \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sigalgs_cert),              \
        TEST_DECL_GROUP("tls", test_tls_msgtype_key_share),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_client_cert_type_tls13),    \
        TEST_DECL_GROUP("tls", test_tls_msgtype_client_cert_type_tls12),    \
        TEST_DECL_GROUP("tls", test_tls_msgtype_server_cert_type_tls13),    \
        TEST_DECL_GROUP("tls", test_tls_msgtype_server_cert_type_tls12),    \
        TEST_DECL_GROUP("tls", test_tls_msgtype_connection_id),             \
        TEST_DECL_GROUP("tls", test_tls_msgtype_ech),                      \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_find),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_parse_response_gate),  \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_parse_size_gates),     \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_parse_cacheonly),      \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_parse_match),          \
        TEST_DECL_GROUP("tls", test_tls_msgtype_sni_parse_ech_public),     \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk_ch_id_gates),          \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk_ch_binder_gates),      \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk_sh_index),             \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk_sh_resumption),        \
        TEST_DECL_GROUP("tls", test_tls_msgtype_cookie_parse_gates),       \
        TEST_DECL_GROUP("tls", test_tls_msgtype_tca_parse_gates),          \
        TEST_DECL_GROUP("tls", test_tls_msgtype_tca_find),                 \
        TEST_DECL_GROUP("tls", test_tls_msgtype_tca_new_alloc),          \
        TEST_DECL_GROUP("tls", test_tls_msgtype_psk_write_chosen)

#endif /* TESTS_API_TEST_TLS_MSGTYPE_H */
