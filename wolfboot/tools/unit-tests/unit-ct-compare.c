/* unit-ct-compare.c
 *
 * Regression test: the WOLFBOOT_ARMORED image_CT_compare() self-check
 * computed expected_witness = (len * (len + 1U)) / 2U in 32-bit
 * arithmetic. For len >= 65536 the product truncates and the folded
 * witness no longer matches the running sum, so byte-identical buffers
 * were reported as unequal (fail-closed false reject). The loop itself
 * is constant-time; this was a pure correctness defect in the witness.
 *
 * src/image.c drags in the full image dependency tree, so the Makefile
 * extracts the ARMORED function verbatim; the test exercises it at the
 * wrap boundary and beyond.
 *
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <check.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NOINLINEFUNCTION __attribute__((noinline))

/* Accumulator seed, mirrored from the definition in src/image.c. */
#define CT_SENTINEL 0xA5C3F000U

#include "ct_compare_extract.h"

#define CT_BUF_SIZE 131072U

START_TEST(test_ct_compare_equal_lengths){
    uint8_t *a = malloc(CT_BUF_SIZE);
    uint8_t *b = malloc(CT_BUF_SIZE);
    static const uint32_t lens[] =
    {32U, 48U, 65535U, 65536U, 65537U, 131072U};
    unsigned li;

    ck_assert_ptr_nonnull(a);
    ck_assert_ptr_nonnull(b);

    for (li = 0; li < sizeof(lens) / sizeof(lens[0]); li++) {
        memset(a, 0x5AU, CT_BUF_SIZE);
        memset(b, 0x5AU, CT_BUF_SIZE);
        ck_assert_int_eq(image_CT_compare(a, b, lens[li]), 0);
    }

    free(a);
    free(b);
}
END_TEST

START_TEST(test_ct_compare_unequal)
{
    uint8_t a[64];
    uint8_t b[64];

    memset(a, 0x00, sizeof(a));
    memset(b, 0x00, sizeof(b));
    b[63] = 0x01; /* last byte differs: the loop must run to the end */
    ck_assert_int_ne(image_CT_compare(a, b, sizeof(a)), 0);
}
END_TEST

START_TEST(test_ct_compare_zero_len)
{
    uint8_t a[1];

    a[0] = 0;
    ck_assert_int_ne(image_CT_compare(a, a, 0), 0);
}
END_TEST

Suite *ct_compare_suite(void)
{
    Suite *s = suite_create("ct_compare");
    TCase *tc = tcase_create("armored");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, test_ct_compare_equal_lengths);
    tcase_add_test(tc, test_ct_compare_unequal);
    tcase_add_test(tc, test_ct_compare_zero_len);

    return s;
}

int main(void)
{
    int failed;
    Suite *s = ct_compare_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed == 0) ? 0 : 1;
}
