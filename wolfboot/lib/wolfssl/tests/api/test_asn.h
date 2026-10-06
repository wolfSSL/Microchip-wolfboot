/* test_asn.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFCRYPT_TEST_ASN_H
#define WOLFCRYPT_TEST_ASN_H

#include <tests/api/api_decl.h>

int test_SetAsymKeyDer(void);
int test_DecodeAsymKey_lenient_versions(void);
int test_DecodeAsymKey_negative(void);
int test_GetSetShortInt(void);
int test_wc_IndexSequenceOf(void);
int test_wolfssl_local_MatchBaseName(void);
int test_wolfssl_local_MatchDnsConstraintWildcard(void);
int test_wolfssl_local_MatchUriNameConstraint(void);
int test_wc_DecodeRsaPssParams(void);
int test_SerialNumber0_RootCA(void);
int test_DecodeAltNames_length_underflow(void);
int test_DecodeCertExtensions_dup_certpol(void);
int test_DecodeCertExtensions_crldp_multiple_uri(void);
int test_DecodeCertExtensions_empty_certpol(void);
int test_DecodeCertExtensions_certpol_trailing_junk(void);
int test_DecodeCertExtensions_empty_certpol_trailing(void);
int test_ParseCert_validity_length_overrun(void);
int test_ParseCert_SM3wSM2_short_pubkey(void);
int test_ParseCert_dnBufferBoundary(void);
int test_ParseCert_nameComponentIds(void);
int test_ParseCert_issuerNameNoField(void);
int test_wc_DecodeObjectId(void);
int test_ToTraditional_ex_handcrafted(void);
int test_ToTraditional_ex_roundtrip(void);
int test_ToTraditional_ex_negative(void);
int test_ToTraditional_ex_mldsa_bad_params(void);
int test_wc_SignCert_buffer_bounds(void);
int test_wc_MakeCert_generalizedTimeValidity(void);
int test_wc_MakeCert_serial_encoding(void);
int test_wc_DecodeKeyUsage_decipherOnly(void);
int test_wc_DecodeExtKeyUsage_ssh(void);
int test_wc_DecodeExtKeyUsage_ssh_oid_collision(void);
int test_wc_AsnDecisionCoverage(void);
int test_wc_AsnFeatureCoverage(void);

#define TEST_ASN_DECLS                                              \
    TEST_DECL_GROUP("asn", test_SetAsymKeyDer),                     \
    TEST_DECL_GROUP("asn", test_DecodeAsymKey_lenient_versions),    \
    TEST_DECL_GROUP("asn", test_DecodeAsymKey_negative),            \
    TEST_DECL_GROUP("asn", test_GetSetShortInt),                    \
    TEST_DECL_GROUP("asn", test_wc_IndexSequenceOf),                \
    TEST_DECL_GROUP("asn", test_wolfssl_local_MatchBaseName),       \
    TEST_DECL_GROUP("asn", test_wolfssl_local_MatchDnsConstraintWildcard), \
    TEST_DECL_GROUP("asn", test_wolfssl_local_MatchUriNameConstraint), \
    TEST_DECL_GROUP("asn", test_wc_DecodeRsaPssParams),             \
    TEST_DECL_GROUP("asn", test_SerialNumber0_RootCA),              \
    TEST_DECL_GROUP("asn", test_DecodeAltNames_length_underflow),   \
    TEST_DECL_GROUP("asn", test_DecodeCertExtensions_dup_certpol),  \
    TEST_DECL_GROUP("asn", test_DecodeCertExtensions_crldp_multiple_uri), \
    TEST_DECL_GROUP("asn", test_DecodeCertExtensions_empty_certpol), \
    TEST_DECL_GROUP("asn", test_DecodeCertExtensions_certpol_trailing_junk), \
    TEST_DECL_GROUP("asn", test_DecodeCertExtensions_empty_certpol_trailing), \
    TEST_DECL_GROUP("asn", test_ParseCert_validity_length_overrun), \
    TEST_DECL_GROUP("asn", test_ParseCert_SM3wSM2_short_pubkey),    \
    TEST_DECL_GROUP("asn", test_ParseCert_dnBufferBoundary),        \
    TEST_DECL_GROUP("asn", test_ParseCert_nameComponentIds),       \
    TEST_DECL_GROUP("asn", test_ParseCert_issuerNameNoField),      \
    TEST_DECL_GROUP("asn", test_wc_DecodeObjectId),                 \
    TEST_DECL_GROUP("asn", test_ToTraditional_ex_handcrafted),      \
    TEST_DECL_GROUP("asn", test_ToTraditional_ex_roundtrip),        \
    TEST_DECL_GROUP("asn", test_ToTraditional_ex_negative),         \
    TEST_DECL_GROUP("asn", test_ToTraditional_ex_mldsa_bad_params), \
    TEST_DECL_GROUP("asn", test_wc_SignCert_buffer_bounds),         \
    TEST_DECL_GROUP("asn", test_wc_MakeCert_generalizedTimeValidity), \
    TEST_DECL_GROUP("asn", test_wc_MakeCert_serial_encoding),       \
    TEST_DECL_GROUP("asn", test_wc_DecodeKeyUsage_decipherOnly),    \
    TEST_DECL_GROUP("asn", test_wc_DecodeExtKeyUsage_ssh),          \
    TEST_DECL_GROUP("asn", test_wc_DecodeExtKeyUsage_ssh_oid_collision), \
    TEST_DECL_GROUP("asn", test_wc_AsnDecisionCoverage),           \
    TEST_DECL_GROUP("asn", test_wc_AsnFeatureCoverage)

#endif /* WOLFCRYPT_TEST_ASN_H */
