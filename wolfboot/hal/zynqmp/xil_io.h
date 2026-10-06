/* xil_io.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

/* Minimal Xilinx-compatible MMIO/types shim.
 *
 * This provides just enough of the Xilinx BSP <xil_io.h> surface for an
 * unmodified, board-generated psu_init_gpl.c to compile and link into
 * wolfBoot when it runs as the ZynqMP FSBL replacement (WOLFBOOT_ZYNQMP_FSBL).
 * The board's psu_init_gpl.c / psu_init_gpl.h are supplied at build time and
 * are NOT part of the wolfBoot tree (they are board/XSA specific and carry the
 * Xilinx copyright). See docs and config/examples/zynqmp_fsbl.config.
 */

#ifndef WOLFBOOT_ZYNQMP_XIL_IO_H
#define WOLFBOOT_ZYNQMP_XIL_IO_H

#include <stdint.h>

/* Xilinx fixed-width type aliases used by psu_init_gpl.c */
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;
typedef int8_t    s8;
typedef int16_t   s16;
typedef int32_t   s32;
typedef int64_t   s64;
typedef uintptr_t UINTPTR;
typedef intptr_t  INTPTR;

#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

static inline u32 Xil_In32(UINTPTR addr)
{
    return *(volatile u32*)addr;
}

static inline void Xil_Out32(UINTPTR addr, u32 value)
{
    *(volatile u32*)addr = value;
}

static inline u16 Xil_In16(UINTPTR addr)
{
    return *(volatile u16*)addr;
}

static inline void Xil_Out16(UINTPTR addr, u16 value)
{
    *(volatile u16*)addr = value;
}

static inline u8 Xil_In8(UINTPTR addr)
{
    return *(volatile u8*)addr;
}

/* Xilinx BSP logging used by a few psu_init error paths (e.g. SERDES cal
 * timeout). psu_init runs before uart_init(), so this is a no-op; see
 * hal/zynqmp_psu_shim.c. */
int xil_printf(const char* ctrl1, ...);

static inline void Xil_Out8(UINTPTR addr, u8 value)
{
    *(volatile u8*)addr = value;
}

#endif /* WOLFBOOT_ZYNQMP_XIL_IO_H */
