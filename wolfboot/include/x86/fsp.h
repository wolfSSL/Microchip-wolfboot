/* fsp.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */
#ifndef FSP_H
#define FSP_H

#include <x86/fsp/FspCommon.h>

int fsp_info_header_is_ok(struct fsp_info_header *hdr);
int fsp_get_image_revision(struct fsp_info_header *h, int *build,
                                  int *rev, int *maj, int *min);
void print_fsp_image_revision(struct fsp_info_header *h);
void fsp_init_silicon(void);

/* Act on a reset request from any FSP entry point; returns for a non-reset
 * status so the caller still checks for EFI_SUCCESS. */
void fsp_handle_reset(uint32_t status);

/* Reset requests (not failures) from FspMemInit and NotifyPhase. */
#define FSP_STATUS_RESET_REQUIRED_COLD  0x40000001
#define FSP_STATUS_RESET_REQUIRED_WARM  0x40000002
/* Codes 3..8 are platform-defined. On Intel client SoCs FSP-S returns _3 to
 * request a global reset (host + CSME), needed for the ChipsetInit sync. */
#define FSP_STATUS_RESET_REQUIRED_3     0x40000003
#define FSP_STATUS_RESET_REQUIRED_4     0x40000004
#define FSP_STATUS_RESET_REQUIRED_5     0x40000005
#define FSP_STATUS_RESET_REQUIRED_6     0x40000006
#define FSP_STATUS_RESET_REQUIRED_7     0x40000007
#define FSP_STATUS_RESET_REQUIRED_8     0x40000008

#endif /* FSP_H */
