/* app_f28p55x.c
 *
 * Minimal wolfBoot test application for the TI LAUNCHXL-F28P55X
 * (TMS320F28P550SJ, C2000 C28x DSP).
 *
 * This is the XIP payload wolfBoot verifies and branches to.  It is linked so
 * its codestart lands at WOLFBOOT_PARTITION_BOOT_ADDRESS + IMAGE_HEADER_SIZE
 * (0xA0100, see test-app/f28p55x_app.cmd), which is exactly the firmware base
 * do_boot() jumps to.  On boot it prints a banner on SCIA (GPIO28/29, the
 * XDS110 virtual COM, 115200 8N1) so a successful verify+jump is visible.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include "driverlib.h"
#include "device.h"

static void sci_init(void)
{
    GPIO_setPinConfig(DEVICE_GPIO_CFG_SCIRXDA);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SCIRXDA, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SCIRXDA, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SCIRXDA, GPIO_QUAL_ASYNC);

    GPIO_setPinConfig(DEVICE_GPIO_CFG_SCITXDA);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SCITXDA, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SCITXDA, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SCITXDA, GPIO_QUAL_ASYNC);

    SCI_performSoftwareReset(SCIA_BASE);
    SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, 115200,
                  (SCI_CONFIG_WLEN_8 | SCI_CONFIG_STOP_ONE | SCI_CONFIG_PAR_NONE));
    SCI_resetChannels(SCIA_BASE);
    SCI_resetRxFIFO(SCIA_BASE);
    SCI_resetTxFIFO(SCIA_BASE);
    SCI_enableFIFO(SCIA_BASE);
    SCI_enableModule(SCIA_BASE);
    SCI_performSoftwareReset(SCIA_BASE);
}

static void sci_puts(const char *s)
{
    while (*s != '\0') {
        if (*s == '\n')
            SCI_writeCharBlockingFIFO(SCIA_BASE, (uint16_t)'\r');
        SCI_writeCharBlockingFIFO(SCIA_BASE, (uint16_t)(*s & 0xFF));
        s++;
    }
}

/* The signed wolfBoot header lives at 0xA0000 (see f28p55x_app.cmd); reference
 * it so the linker retains the .wolfboot_hdr section in the image. */
extern const unsigned int wolfboot_header[];

int main(void)
{
    volatile long d;
    volatile unsigned int hdr0 = wolfboot_header[0];
    (void)hdr0;

    /* wolfBoot already configured the clock (150 MHz PLL), flash wait states and
     * the SCIA pins before the XIP handoff.  Re-running Device_init() here would
     * re-lock the PLL, and that clock transient garbles the SCI across the
     * handoff -- so just (re)initialize the console and run. */
    sci_init();

    for (;;) {
        sci_puts("hello from the wolfBoot app on F28P55x\n");
        for (d = 0; d < 4000000; d++)
            ;
    }
}
