/* nrf52.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef TARGET_nrf52

#include <stdint.h>
#include "image.h"
#include "nrf52.h"

#ifdef DEBUG_UART
#define UARTE_ENABLE_ENABLE 8u

void uart_init(void)
{
    UART0_BAUDRATE = BAUD_115200;
    UART0_ENABLE = UARTE_ENABLE_ENABLE;
}

static volatile uint8_t uart_tx_buf;

static void uart_write_char(char c)
{
    uart_tx_buf = c;
    UART0_EVENT_ENDTX = 0;
    UART0_TXD_PTR = (uint32_t)&uart_tx_buf;
    UART0_TXD_MAXCOUNT = 1;
    UART0_TASK_STARTTX = 1;
    while(UART0_EVENT_ENDTX == 0)
        ;
}

void uart_write(const char* buf, unsigned int sz)
{
    uint32_t pos = 0;
    while (sz-- > 0) {
        char c = buf[pos++];
        if (c == '\n') { /* handle CRLF */
            uart_write_char('\r');
        }
        uart_write_char(c);
    }
}
#endif /* DEBUG_UART */

static void RAMFUNCTION flash_wait_complete(void)
{
    while (NVMC_READY == 0)
        ;
}

int RAMFUNCTION hal_flash_write(uint32_t address, const uint8_t *data, int len)
{
    int i = 0;
    uint32_t *src, *dst;

    while (i < len) {
        if ((len - i > 3) && ((((address + i) & 0x03) == 0)  && ((((uint32_t)data) + i) & 0x03) == 0)) {
            /* Index by "i" directly: the condition above only guarantees
             * that "address + i" and "data + i" are word aligned, so
             * dst[i >> 2] off the unaligned base would address the wrong
             * word (and fault on a strict-alignment core). */
            src = (uint32_t *)(data + i);
            dst = (uint32_t *)(address + i);
            NVMC_CONFIG = NVMC_CONFIG_WEN;
            flash_wait_complete();
            *dst = *src;
            flash_wait_complete();
            i+=4;
        } else {
            uint32_t val;
            uint8_t *vbytes = (uint8_t *)(&val);
            uint32_t off = ((address + i) % 4);
            dst = (uint32_t *)(address + i - off);
            val = *dst;
            while (off < 4) {
                if (i < len)
                    vbytes[off++] = data[i++];
                else
                    off++;
            }
            NVMC_CONFIG = NVMC_CONFIG_WEN;
            flash_wait_complete();
            *dst = val;
            flash_wait_complete();
        }
    }
    return 0;
}

void RAMFUNCTION hal_flash_unlock(void)
{
}

void RAMFUNCTION hal_flash_lock(void)
{
}


int RAMFUNCTION hal_flash_erase(uint32_t address, int len)
{
    uint32_t end = address + len - 1;
    uint32_t p;
    for (p = address; p <= end; p += FLASH_PAGE_SIZE) {
        NVMC_CONFIG = NVMC_CONFIG_EEN;
        flash_wait_complete();
        NVMC_ERASEPAGE = p;
        flash_wait_complete();
    }
    return 0;
}

void hal_init(void)
{
    TASKS_HFCLKSTART = 1;
    while(TASKS_HFCLKSTARTED == 0)
        ;
}

void hal_prepare_boot(void)
{
#ifdef WOLFBOOT_RESTORE_CLOCK
    TASKS_HFCLKSTOP = 1;
#endif
}

#endif /* TARGET_nrf52 */
