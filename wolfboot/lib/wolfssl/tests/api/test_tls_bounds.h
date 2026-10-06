/* test_tls_bounds.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef TESTS_API_TEST_TLS_BOUNDS_H
#define TESTS_API_TEST_TLS_BOUNDS_H

int test_TLSX_UseSNI_bounds(void);
int test_TLSX_UseALPN_bounds(void);
int test_TLSX_UseMaxFragment_bounds(void);
int test_TLSX_UseCertificateStatusRequest_bounds(void);
int test_TLSX_UseCertificateStatusRequestV2_bounds(void);
int test_TLSX_SupportExtensions_bounds(void);
int test_TLSX_CSR2_InitRequests_bounds(void);
int test_TLSX_CSR2_ForceRequest_bounds(void);
int test_TLSX_CSR_GetRequest_ex_bounds(void);
int test_wolfSSL_make_eap_keys_bounds(void);
int test_wolfSSL_SetTlsHmacInner_bounds(void);
int test_BuildTlsHandshakeHash_bounds(void);
int test_TLS_hmac_bounds(void);
int test_TLSX_ALPN_GetSize_overflow(void);
int test_TLSX_Cookie_bounds(void);
int test_TLSX_CSR_write_getsize_bounds(void);
int test_TLSX_CSR_SetResponseWithStatusCB_bounds(void);
int test_ProcessChainOCSPRequest_bounds(void);
int test_TLSX_PopulateExtensions_bounds(void);
int test_TLSX_PopulateSupportedGroups_bounds(void);
int test_TLSX_CSR_Parse_bounds(void);
int test_TLSX_CSR2_Parse_bounds(void);
int test_TLSX_ext_dispatch_ctx_extensions_bounds(void);
int test_TLSX_WriteRequest_ems_bounds(void);
int test_TLSX_WriteRequest_length_prefix_bounds(void);
int test_TLSX_WriteResponse_bounds(void);
int test_TLSX_ext_msgtype_dispatch_bounds(void);
int test_TLSX_SecureRenegotiation_Write_bounds(void);
int test_TLSX_SessionTicket_Parse_falsefalse_bounds(void);

#define TEST_TLS_BOUNDS_DECLS                                                \
        TEST_DECL_GROUP("tls", test_TLSX_UseSNI_bounds),                     \
        TEST_DECL_GROUP("tls", test_TLSX_UseALPN_bounds),                    \
        TEST_DECL_GROUP("tls", test_TLSX_UseMaxFragment_bounds),             \
        TEST_DECL_GROUP("tls", test_TLSX_UseCertificateStatusRequest_bounds),\
        TEST_DECL_GROUP("tls",                                               \
                test_TLSX_UseCertificateStatusRequestV2_bounds),             \
        TEST_DECL_GROUP("tls", test_TLSX_SupportExtensions_bounds),          \
        TEST_DECL_GROUP("tls", test_TLSX_CSR2_InitRequests_bounds),          \
        TEST_DECL_GROUP("tls", test_TLSX_CSR2_ForceRequest_bounds),          \
        TEST_DECL_GROUP("tls", test_TLSX_CSR_GetRequest_ex_bounds),          \
        TEST_DECL_GROUP("tls", test_wolfSSL_make_eap_keys_bounds),           \
        TEST_DECL_GROUP("tls", test_wolfSSL_SetTlsHmacInner_bounds),         \
        TEST_DECL_GROUP("tls", test_BuildTlsHandshakeHash_bounds),           \
        TEST_DECL_GROUP("tls", test_TLS_hmac_bounds),                       \
        TEST_DECL_GROUP("tls", test_TLSX_ALPN_GetSize_overflow),            \
        TEST_DECL_GROUP("tls", test_TLSX_Cookie_bounds),                    \
        TEST_DECL_GROUP("tls", test_TLSX_CSR_write_getsize_bounds),         \
        TEST_DECL_GROUP("tls",                                              \
                test_TLSX_CSR_SetResponseWithStatusCB_bounds),              \
        TEST_DECL_GROUP("tls", test_ProcessChainOCSPRequest_bounds),        \
        TEST_DECL_GROUP("tls", test_TLSX_PopulateExtensions_bounds),        \
        TEST_DECL_GROUP("tls", test_TLSX_PopulateSupportedGroups_bounds),   \
        TEST_DECL_GROUP("tls", test_TLSX_CSR_Parse_bounds),                 \
        TEST_DECL_GROUP("tls", test_TLSX_CSR2_Parse_bounds),                \
        TEST_DECL_GROUP("tls", test_TLSX_ext_dispatch_ctx_extensions_bounds),\
        TEST_DECL_GROUP("tls", test_TLSX_WriteRequest_ems_bounds),          \
        TEST_DECL_GROUP("tls", test_TLSX_WriteRequest_length_prefix_bounds),\
        TEST_DECL_GROUP("tls", test_TLSX_WriteResponse_bounds),             \
        TEST_DECL_GROUP("tls", test_TLSX_ext_msgtype_dispatch_bounds),      \
        TEST_DECL_GROUP("tls", test_TLSX_SecureRenegotiation_Write_bounds),  \
        TEST_DECL_GROUP("tls", test_TLSX_SessionTicket_Parse_falsefalse_bounds)

#endif /* TESTS_API_TEST_TLS_BOUNDS_H */
