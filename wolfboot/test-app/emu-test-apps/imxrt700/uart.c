/* uart.c
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
#include "emu_app.h"

/* LP_FLEXCOMM0 / LPUART0, non-secure alias. wolfBoot set up the FCCLK0 and
 * LP_FLEXCOMM0 clocks and the console pins before the jump, so only the LPUART
 * block itself is armed here. Both worlds use the non-secure alias; the secure
 * world reaches it too. */
#define LPUART0_BASE     0x40110000u
#define LPUART0_BAUD     (*(volatile uint32_t *)(LPUART0_BASE + 0x10u))
#define LPUART0_STAT     (*(volatile uint32_t *)(LPUART0_BASE + 0x14u))
#define LPUART0_CTRL     (*(volatile uint32_t *)(LPUART0_BASE + 0x18u))
#define LPUART0_DATA     (*(volatile uint32_t *)(LPUART0_BASE + 0x1Cu))
#define LPFC0_PSELID     (*(volatile uint32_t *)(LPUART0_BASE + 0xFF8u))

#define UART_STAT_TDRE   0x00800000u
#define UART_STAT_RDRF   0x00200000u
#define UART_CTRL_TE_RE  0x000C0000u

/* FCCLK0 = 192 MHz compute base clock, over-16 sampling at 115200 baud. */
#define UART_SBR         104u
#define UART_TX_POLL_LIMIT 100000u

void emu_uart_init(void)
{
    LPFC0_PSELID = 0x1u;
    LPUART0_CTRL = 0u;
    LPUART0_BAUD = (15u << 24) | UART_SBR;
    LPUART0_CTRL = UART_CTRL_TE_RE;
}

void emu_uart_write(uint8_t c)
{
    uint32_t t = UART_TX_POLL_LIMIT;

    while (((LPUART0_STAT & UART_STAT_TDRE) == 0u) && (t > 0u)) {
        t--;
    }
    if (t != 0u) {
        LPUART0_DATA = (uint32_t)c;
    }
}

int emu_uart_read(uint8_t *c)
{
    if ((LPUART0_STAT & UART_STAT_RDRF) == 0u) {
        return 0;
    }
    *c = (uint8_t)(LPUART0_DATA & 0xFFu);
    return 1;
}
