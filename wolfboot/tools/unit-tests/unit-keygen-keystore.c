/* unit-keygen-keystore.c
 *
 * Regression test for F-13624: the keystore accessors emitted by
 * tools/keytools/keygen.c (the default keystore for every non-OTP,
 * non-wolfHSM build) lacked the out-of-range id guard the OTP backend
 * (src/flash_otp_keystore.c) has - get_buffer/get_size/get_mask tested only
 * `id >= keystore_num_pubkeys()` (a negative id indexed PubKeys[] out of
 * bounds) and get_key_type had no bounds check at all. No test covered the
 * generated keystore's bounds, so the divergence from the OTP contract was
 * invisible to CI.
 *
 * The Makefile extracts the real Keystore_API template from keygen.c, emits
 * a self-contained keystore.c (keystore_gen.c), and compiles it here. The
 * test asserts the same out-of-range contract unit-otp-keystore.c pins.
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

/* Defined in the emitted keystore.c (compiled as a separate TU). */
int keystore_num_pubkeys(void);
uint8_t *keystore_get_buffer(int id);
int keystore_get_size(int id);
uint32_t keystore_get_key_type(int id);
uint32_t keystore_get_mask(int id);

/* The emitted accessors must return the documented sentinels for out-of-
 * range ids (negative and >= num), matching the OTP backend's contract. */
START_TEST (test_out_of_range_ids_return_sentinels){
    int num = keystore_num_pubkeys();

    ck_assert_int_eq(num, 1);
    ck_assert_ptr_eq(keystore_get_buffer(-1), (uint8_t *)0);
    ck_assert_ptr_eq(keystore_get_buffer(num), (uint8_t *)0);
    ck_assert_int_eq(keystore_get_size(-1), -1);
    ck_assert_int_eq(keystore_get_size(num), -1);
    ck_assert_uint_eq(keystore_get_mask(-1), 0);
    ck_assert_uint_eq(keystore_get_mask(num), 0);
    ck_assert_uint_eq(keystore_get_key_type(-1), (uint32_t)-1);
    ck_assert_uint_eq(keystore_get_key_type(num), (uint32_t)-1);
}
END_TEST

/* In-range id 0 returns the slot's values (the guard must not over-reject). */
START_TEST(test_in_range_id_returns_slot)
{
    ck_assert_ptr_ne(keystore_get_buffer(0), (uint8_t *)0);
    ck_assert_int_eq(keystore_get_size(0), 32);
    ck_assert_uint_eq(keystore_get_key_type(0), 1);
    ck_assert_uint_eq(keystore_get_mask(0), 0x1);
}
END_TEST

Suite *wolfboot_suite(void)
{
    Suite *s = suite_create("keygen-keystore");
    TCase *tc = tcase_create("bounds");

    tcase_add_test(tc, test_out_of_range_ids_return_sentinels);
    tcase_add_test(tc, test_in_range_id_returns_slot);
    suite_add_tcase(s, tc);
    return s;
}

int main(int argc, char *argv[])
{
    int fails;
    Suite *s;
    SRunner *sr;

    (void)argc;
    (void)argv;
    s = wolfboot_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    fails = srunner_ntests_failed(sr);
    srunner_free(sr);
    return fails;
}
