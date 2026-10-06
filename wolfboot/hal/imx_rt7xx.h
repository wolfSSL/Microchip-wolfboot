/* imx_rt7xx — wolfBoot HAL for the NXP i.MX RT700 (MIMXRT798S, Cortex-M33).
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef IMX_RT7XX_H
#define IMX_RT7XX_H

#include <stdint.h>

/* XSPI0 octal NOR memory-mapped apertures (bit 28 selects the Secure alias). */
#define IMX_RT7XX_XSPI0_NS_BASE   0x28000000u
#define IMX_RT7XX_XSPI0_S_BASE    0x38000000u
#define IMX_RT7XX_XSPI0_SIZE      0x04000000u /* 64 MB octal NOR */

#define IMX_RT7XX_XSPI0_OFFSET(a)   ((a) & (IMX_RT7XX_XSPI0_SIZE - 1u))
#define IMX_RT7XX_XSPI0_APERTURE(a) ((a) & ~(IMX_RT7XX_XSPI0_SIZE - 1u))

/* Accept a program/erase range only if it lies wholly inside one XSPI0
 * aperture. Both apertures map the same die, so either is valid. */
static inline int imx_rt7xx_xspi0_addr_ok(uint32_t address, int len)
{
    uint32_t aperture = IMX_RT7XX_XSPI0_APERTURE(address);

    if ((len <= 0) ||
        ((aperture != IMX_RT7XX_XSPI0_NS_BASE) &&
         (aperture != IMX_RT7XX_XSPI0_S_BASE)) ||
        (IMX_RT7XX_XSPI0_OFFSET(address) + (uint32_t)len >
         IMX_RT7XX_XSPI0_SIZE)) {
        return -1;
    }
    return 0;
}

/* XSPI0 controller register block (distinct from the flash-content aperture). */
#define IMX_RT7XX_XSPI0_REGS_S    0x50184000u
#define IMX_RT7XX_XSPI0_REGS_NS   0x40184000u

/* Compute-domain register blocks, Non-secure aliases (TZEN=0 boot). */
#define IMX_RT7XX_RSTCTL0_NS      0x40000000u
#define IMX_RT7XX_CLKCTL0_NS      0x40001000u
#define IMX_RT7XX_IOPCTL0_NS      0x40004000u
#define IMX_RT7XX_LPFC0_NS        0x40110000u /* LP_FLEXCOMM0 / LPUART0 */

#endif /* IMX_RT7XX_H */
