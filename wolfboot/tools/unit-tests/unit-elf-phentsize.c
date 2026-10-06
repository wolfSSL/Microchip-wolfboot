/* unit-elf-phentsize.c
 *
 * Regression test for F-13656: elf_load_image_mmu() never constrained
 * e_phentsize against the program-header struct size, so an
 * undersized entry stride made the last loop iteration read past the
 * validated program-header table (and past the image buffer when the
 * table ends at the image end). The loader must reject such images.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <stdint.h>
#include <string.h>
#include <check.h>

#include "elf.h"

/* Pull in elf.c directly (avoids a separate link step). */
#include "../../src/elf.c"

/* 4 KiB is plenty for the ELF64 header + 1 program header + segment data. */
#define TEST_IMG_SIZE 4096

static uint8_t g_image[TEST_IMG_SIZE];
static uint8_t g_target[8];

/* Build a minimal ELF64 with one 8-byte PT_LOAD segment whose data sits
 * at image offset 256. entry_size overrides e_phentsize. */
static void build_elf(uint16_t entry_size)
{
    elf64_header          *hdr;
    elf64_program_header  *ph;

    memset(g_image, 0, sizeof(g_image));
    memset(g_target, 0, sizeof(g_target));

    hdr = (elf64_header *)g_image;
    memcpy(hdr->ident, ELF_IDENT_STR, 4);
    hdr->ident[ELF_CLASS_OFF]   = ELF_CLASS_64;
    hdr->ident[5]               = ELF_ENDIAN_LITTLE;
    hdr->type                   = ELF_HET_EXEC;
    hdr->version                = 1;
    hdr->entry                  = 0x1000;
    hdr->ph_offset              = sizeof(elf64_header);          /* 64 */
    hdr->ph_entry_size          = entry_size;
    hdr->ph_entry_count         = 1;

    ph = (elf64_program_header *)(g_image + sizeof(elf64_header));
    ph->type      = ELF_PT_LOAD;
    ph->flags     = 0;
    ph->offset    = 256;
    ph->vaddr     = (uint64_t)(uintptr_t)g_target;
    ph->paddr     = ph->vaddr;
    ph->file_size = 8;
    ph->mem_size  = 8;
    ph->align     = 1;

    memset(g_image + 256, 0xA5, 8);
}

/* An e_phentsize smaller than the program-header struct must be
 * rejected: the loop would read past the validated table. */
START_TEST(test_undersized_phentsize_rejected){
    uintptr_t entry = 0;
    int ret;

    build_elf(4);

    ret = elf_load_image_mmu(g_image, sizeof(g_image), &entry, NULL);

    ck_assert_int_eq(ret, -3);
    ck_assert_int_eq(entry, 0);
}
END_TEST

/* A conformant e_phentsize must still load: the new bound must not
 * over-reject. */
START_TEST(test_valid_phentsize_accepted)
{
    uintptr_t entry = 0;
    int ret;

    build_elf((uint16_t)sizeof(elf64_program_header));

    ret = elf_load_image_mmu(g_image, sizeof(g_image), &entry, NULL);

    ck_assert_int_eq(ret, 0);
    ck_assert_int_eq(entry, 0x1000);
    ck_assert_mem_eq(g_target, g_image + 256, 8);
}
END_TEST

Suite *elf_phentsize_suite(void)
{
    Suite *s  = suite_create("ELF phentsize");
    TCase *tc = tcase_create("phentsize-bound");
    tcase_add_test(tc, test_undersized_phentsize_rejected);
    tcase_add_test(tc, test_valid_phentsize_accepted);
    tcase_set_timeout(tc, 10);
    suite_add_tcase(s, tc);
    return s;
}

int main(void)
{
    int fails;
    Suite *s  = elf_phentsize_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    fails = srunner_ntests_failed(sr);
    srunner_free(sr);
    return fails;
}
