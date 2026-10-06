/* test_ssl_ext.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_SSL_EXT_H
#define TESTS_API_SSL_EXT_H

int test_wolfSSL_ech_config_api(void);
int test_wolfSSL_api_null_burndown(void);
int test_wolfSSL_session_null_burndown(void);
int test_wolfSSL_api_null_operands(void);
int test_wolfSSL_public_null_operands(void);
int test_wolfSSL_session_lifecycle_guards(void);

int test_wolfSSL_NoTicketTLSv12_ext(void);
int test_wolfSSL_CTX_UseMaxFragment_ext(void);
int test_wolfSSL_CTX_num_tickets_ext(void);
int test_wolfSSL_set1_groups_ext(void);
int test_wolfSSL_set1_groups_list_ext(void);
int test_wolfSSL_CTX_set_TicketHint_ext(void);
int test_wolfSSL_CTX_set_TicketHint_default_cb_limit(void);
int test_wolfSSL_tlsext_max_fragment_length_ext(void);
int test_wolfSSL_DisableExtendedMasterSecret_ext(void);
int test_wolfSSL_set_tlsext_host_name_ext(void);
int test_wolfSSL_CTX_set_tlsext_servername_callback_ext(void);
int test_wolfSSL_set_tlsext_debug_arg_ext(void);
int test_wolfSSL_set_tlsext_debug_callback_ext(void);
int test_wolfSSL_set_tlsext_debug_callback_handshake_ext(void);
int test_wolfSSL_set_SessionTicket_cb_ext(void);
int test_wolfSSL_set1_curves_list_ext(void);
int test_wolfSSL_SecureResume_ext(void);
int test_wolfSSL_CTX_UseSecureRenegotiation_ext(void);
int test_wolfSSL_next_proto_cb_ext(void);
int test_wolfSSL_tlsext_status_exts_ids_ext(void);
int test_wolfSSL_SNI_GetFromBuffer_inval_ext(void);
int test_wolfSSL_UseTrustedCA_inval_ext(void);
int test_wolfSSL_UseMaxFragment_inval_ext(void);
int test_wolfSSL_set1_groups_inval_ext(void);
int test_wolfSSL_UseALPN_inval_ext(void);
int test_wolfSSL_ALPN_GetPeerProtocol_inval_ext(void);
int test_wolfSSL_CTX_set_TicketEncCb_inval_ext(void);
int test_wolfSSL_SessionTicket_inval_ext(void);
int test_wolfSSL_CTX_set_servername_arg_inval_ext(void);
int test_wolfSSL_CTX_set_alpn_protos_inval_ext(void);
int test_wolfSSL_dual_alg_cks_parse_ext(void);
int test_wolfSSL_ALPN_FreePeerProtocol_inval_ext(void);
int test_wolfSSL_ALPN_GetPeerProtocol_badlen_ext(void);
int test_wolfSSL_get_secure_renegotiation_support_ext(void);
int test_wolfSSL_set_alpn_protos_badlen_ext(void);
int test_wolfSSL_ticket_key_cb_renew_ext(void);

#define TEST_SSL_EXT_DECLS                                                     \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_NoTicketTLSv12_ext),           \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_CTX_UseMaxFragment_ext),       \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_CTX_num_tickets_ext),          \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set1_groups_ext),              \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set1_groups_list_ext),         \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_CTX_set_TicketHint_ext),       \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_CTX_set_TicketHint_default_cb_limit),                 \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_tlsext_max_fragment_length_ext),                      \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_DisableExtendedMasterSecret_ext),                     \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set_tlsext_host_name_ext),     \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_CTX_set_tlsext_servername_callback_ext),              \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set_tlsext_debug_arg_ext),     \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set_tlsext_debug_callback_ext), \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_set_tlsext_debug_callback_handshake_ext),              \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set_SessionTicket_cb_ext),     \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set1_curves_list_ext),         \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_SecureResume_ext),             \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_CTX_UseSecureRenegotiation_ext),                      \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_next_proto_cb_ext),            \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_tlsext_status_exts_ids_ext),                          \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_SNI_GetFromBuffer_inval_ext),                         \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_UseTrustedCA_inval_ext),       \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_UseMaxFragment_inval_ext),     \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set1_groups_inval_ext),        \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_UseALPN_inval_ext),            \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_ALPN_GetPeerProtocol_inval_ext),                      \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_CTX_set_TicketEncCb_inval_ext),                       \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_SessionTicket_inval_ext),      \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_CTX_set_servername_arg_inval_ext),                    \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_CTX_set_alpn_protos_inval_ext),                       \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_dual_alg_cks_parse_ext),                              \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_ALPN_FreePeerProtocol_inval_ext),                     \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_ALPN_GetPeerProtocol_badlen_ext),                     \
        TEST_DECL_GROUP("ssl_ext",                                             \
            test_wolfSSL_get_secure_renegotiation_support_ext),                \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_set_alpn_protos_badlen_ext),   \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_ticket_key_cb_renew_ext),                  \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_ech_config_api),               \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_api_null_burndown),            \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_session_null_burndown),        \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_api_null_operands),            \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_public_null_operands),         \
        TEST_DECL_GROUP("ssl_ext", test_wolfSSL_session_lifecycle_guards)

#endif /* TESTS_API_SSL_EXT_H */
