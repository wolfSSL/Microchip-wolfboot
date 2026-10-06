/* app_imx_rt7xx.c
 *
 * Test application for the NXP i.MX RT700 (MIMXRT798S-EVK)
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
#include "target.h"
#include "wolfboot/wolfboot.h"

#ifdef DEBUG_UART
/* LPUART0 (LP_FLEXCOMM0) Non-secure alias. wolfBoot brings the console up with
 * DEBUG_UART before the jump, so the app only polls TDRE and writes. The poll
 * is bounded so a stalled console never blocks boot confirmation. */
#define LPUART0_NS_BASE    0x40110000u
#define LPUART0_STAT       (*(volatile uint32_t *)(LPUART0_NS_BASE + 0x14u))
#define LPUART0_DATA       (*(volatile uint32_t *)(LPUART0_NS_BASE + 0x1Cu))
#define LPUART0_TDRE       0x00800000u
#define UART_TX_POLL_LIMIT 0x00100000u

static void uart_write_str(const char *s)
{
    uint32_t timeout;

    while (*s != '\0') {
        timeout = UART_TX_POLL_LIMIT;
        while (((LPUART0_STAT & LPUART0_TDRE) == 0u) && (timeout > 0u)) {
            timeout--;
        }
        if (timeout == 0u) {
            return;
        }
        LPUART0_DATA = (uint32_t)(uint8_t)*s;
        s++;
    }
}
#endif /* DEBUG_UART */

void main(void)
{
    uint32_t version;
    uint8_t state = IMG_STATE_NEW;
#ifdef DEBUG_UART
    char msg[] = "wolfBoot test app v0\r\n";
#endif

    version = wolfBoot_current_firmware_version();

#ifdef DEBUG_UART
    msg[19] = (char)('0' + (int)(version % 10u));
    uart_write_str(msg);
#endif

    if ((wolfBoot_get_partition_state(PART_BOOT, &state) == 0) &&
            (state == IMG_STATE_TESTING)) {
        wolfBoot_success();
    }

    if ((version == 1u) && (wolfBoot_update_firmware_version() != 0u)) {
        wolfBoot_update_trigger();
    }

    while (1) {
        __asm__ volatile("wfi");
    }
}
