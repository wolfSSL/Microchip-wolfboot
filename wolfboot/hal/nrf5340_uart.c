/* nrf5340_uart.c
 *
 * CRLF line conversion for the nRF5340 debug UART, split out of
 * hal/nrf5340.c so the newline handling can be unit-tested on the host
 * without the nrfx register access the rest of that HAL needs.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef DEBUG_UART

#include <string.h>

/* Emit buf[0..sz) via "sink" with every '\n' rendered as CRLF. */
void nrf5340_uart_crlf(const char* buf, unsigned int sz,
        void (*sink)(const char*, unsigned int))
{
    const char* line;
    unsigned int lineSz;
    do {
        /* find '\n' */
        line = memchr(buf, '\n', sz);
        if (line == NULL) {
            sink(buf, sz);
            break;
        }
        lineSz = (unsigned int)(line - buf);
        if (lineSz > sz - 1)
            lineSz = sz - 1;

        sink(buf, lineSz);
        sink("\r\n", 2); /* handle CRLF */

        buf = line + 1; /* advance past the emitted newline */
        sz -= lineSz + 1;
    } while ((int)sz > 0);
}

#endif /* DEBUG_UART */
