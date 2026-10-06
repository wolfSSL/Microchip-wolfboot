/* unit-hifive1-hfrosccfg.c
 *
 * Regression test for F-9743: HFROSCCFG_DIV_SHIFT() in hal/hifive1.c
 * masked the shifted divider with HFROSCCFG_TRIM (0x001F0000) instead
 * of HFROSCCFG_DIV (0x0000001F), so the divider field of the composed
 * HFROSCCFG register value was always zero and hifive1_init()
 * programmed divider 0 instead of the requested 4.
 *
 * The real macro definitions are extracted by the Makefile from
 * hal/hifive1.c; the test pins the composed register value hifive1_init
 * programs.
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

#include "hifive1_hfrosccfg_extract.h"

/* The divider field must carry the requested value unchanged. */
START_TEST(test_div_shift_carries_value)
{
    int d;

    for (d = 0; d <= 31; d++) {
        ck_assert_uint_eq(HFROSCCFG_DIV_SHIFT(d), (uint32_t)d);
    }
}
END_TEST

/* The trim field must land in bits 16..20 and nowhere else. */
START_TEST(test_trim_shift_carries_value)
{
    int t;

    for (t = 0; t <= 31; t++) {
        ck_assert_uint_eq(HFROSCCFG_TRIM_SHIFT(t),
                          (uint32_t)t << 16);
    }
}
END_TEST

/* The two fields must not overlap: composing a full-range divider and
 * trim must keep both values intact. */
START_TEST(test_fields_do_not_overlap)
{
    uint32_t composed;

    composed = HFROSCCFG_DIV_SHIFT(0x1F) | HFROSCCFG_TRIM_SHIFT(0x1F);
    ck_assert_uint_eq(composed, 0x001F001FUL);
}
END_TEST

/* The exact value hifive1_init() programs: EN | DIV(4) | TRIM(0x10).
 * Pre-fix the divider field came out zero (0x40100000). */
START_TEST(test_hifive1_init_composed_value)
{
    uint32_t reg;

    reg = (HFROSCCFG_EN |
        HFROSCCFG_DIV_SHIFT(0x4) |
        HFROSCCFG_TRIM_SHIFT(0x10));
    ck_assert_uint_eq(reg, 0x40100004UL);
}
END_TEST

int main(void)
{
    SRunner *sr;
    Suite *s = suite_create("hifive1_hfrosccfg");
    TCase *tc = tcase_create("hfrosccfg");
    int failures;

    tcase_add_test(tc, test_div_shift_carries_value);
    tcase_add_test(tc, test_trim_shift_carries_value);
    tcase_add_test(tc, test_fields_do_not_overlap);
    tcase_add_test(tc, test_hifive1_init_composed_value);
    suite_add_tcase(s, tc);

    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    failures = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
