/* nxp_ppc_io.h
 *
 * MMIO accessors for the generic NS16550 driver on NXP QorIQ PowerPC.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WOLFBOOT_NXP_PPC_IO_H
#define WOLFBOOT_NXP_PPC_IO_H

/* PowerPC device access needs the enforced-ordering sequences; a plain
 * volatile access is not enough. These match get8()/set8() in hal/nxp_ppc.h
 * byte for byte, repeated rather than included so the driver builds the same
 * from the stage1 and test-app sub-makes, which do not share the top-level
 * include path. */

static inline uint8_t ns16550_ppc_rd8(uintptr_t addr)
{
    int ret;
    __asm__ __volatile__(
        "sync;\n"
        "lbz%U1%X1 %0,%1;\n"
        "twi 0,%0,0;\n"
        "isync"
            : "=r" (ret) : "m" (*(const volatile unsigned char*)addr)
    );
    return (uint8_t)ret;
}

static inline void ns16550_ppc_wr8(uintptr_t addr, uint8_t val)
{
    __asm__ __volatile__(
        "stb%U0%X0 %1,%0;\n"
        "eieio"
            : "=m" (*(volatile unsigned char*)addr) : "r" ((int)val)
    );
}

#define NS16550_RD8(a)     ns16550_ppc_rd8((uintptr_t)(a))
#define NS16550_WR8(a, v)  ns16550_ppc_wr8((uintptr_t)(a), (uint8_t)(v))

#endif /* WOLFBOOT_NXP_PPC_IO_H */
