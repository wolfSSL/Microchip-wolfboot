/* zynqmp_atf.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* ARM Trusted Firmware (BL31) handoff for wolfBoot running as the ZynqMP FSBL
 * replacement (Milestone 1). wolfBoot loads + verifies BL31 and the next
 * normal-world image (BL33: U-Boot or the Linux kernel) with its own keys,
 * then hands off to BL31 at EL3. BL31 stays resident as the EL3 monitor and
 * drops BL33 to the requested lower exception level. */

#ifndef ZYNQMP_ATF_H
#define ZYNQMP_ATF_H

#include <stdint.h>

/* Target exception level for the BL33 (normal-world) image. */
#define ZYNQMP_ATF_EL1  1U
#define ZYNQMP_ATF_EL2  2U

/* Build the BL31 handoff parameters for the given normal-world (BL33) entry
 * point and exception level, publish the parameter-block address to the
 * PMU_GLOBAL scratch register that BL31 reads, and hand off to BL31 at EL3.
 * Does not return.
 *
 * bl31_entry: EL3 entry point of the loaded BL31 image (from its ELF entry).
 * bl33_entry: entry point of the next normal-world image BL31 will start.
 * dts_addr:   device tree address for BL33. The standard ATF handoff block has
 *             no argument fields and stock ZynqMP TF-A enters BL33 with x0=0,
 *             so for a direct (no U-Boot) Linux BL33 wolfBoot also publishes
 *             dts_addr in PMU_GLOBAL.GLOBAL_GEN_STORAGE5. A small TF-A patch
 *             must read that register into the BL33 entrypoint x0; pass 0 when
 *             BL33 finds its own DTB (e.g. U-Boot). See docs.
 * bl33_el:    ZYNQMP_ATF_EL1 or ZYNQMP_ATF_EL2. */
void zynqmp_atf_handoff(uintptr_t bl31_entry, uintptr_t bl33_entry,
    uintptr_t dts_addr, uint32_t bl33_el);

#endif /* ZYNQMP_ATF_H */
