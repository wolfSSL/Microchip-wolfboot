/* test_frodokem_mat_fault_whitebox.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/*
 * MC/DC fault-injection white-box for wolfcrypt/src/wc_frodokem_mat.c.
 *
 * #includes wc_frodokem_mat.c directly so llvm-cov instruments this file's copy
 * (reaching its file-static matrix / noise / mul-add helpers), then #includes
 * the shared driver body. The public FrodoKEM API (wc_frodokem.c) is still
 * provided by the trimmed archive, so make/encap/decap reach these mat routines
 * end to end.
 *
 * NOTE: wc_frodokem_mat.c's 13 (ret == 0) && step residuals become ret != 0
 * only when a SHAKE or AES-ECB primitive returns an error, and on x86/x86_64
 * neither of those primitives allocates from the heap (sha3.c has zero XMALLOC;
 * AES-ECB over the aligned scratch takes a non-allocating path). The heap-fault
 * mock therefore closes NONE of the 13 here -- they need a primitive-return
 * fault mock instead. This driver still runs the mat file end to end (baseline
 * coverage) and is kept so the harness has a documented, reproducible negative
 * result. See test_frodokem_fault_common.h for the full rationale.
 */

#include <wolfcrypt/src/wc_frodokem_mat.c>

#include "test_frodokem_fault_common.h"
