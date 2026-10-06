/* boot_c2000.c
 *
 * Architecture boot handoff for the TI C2000 C28x DSP (TMS320F28P550SJ).
 *
 * The reset/startup path is provided by the C2000Ware codestart
 * (f28p55x_codestartbranch.asm -> _c_int00 -> main); wolfBoot's main()
 * (src/loader.c) then runs hal_init() and the verify state machine.  This file
 * provides the two arch hooks wolfBoot requires: do_boot(), which branches to
 * the verified application resident in the BOOT partition (execute-in-place),
 * and arch_reboot().
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
#include "hal.h"

#include "driverlib.h"
#include "device.h"

/*
 * Branch to the verified application.
 *
 * app_offset is the firmware base (BOOT partition address + IMAGE_HEADER_SIZE),
 * i.e. the application's own codestart, linked to execute in place.  There is
 * no vector table to reload on the C28x: interrupts are masked here and the
 * application's codestart re-establishes its stack pointer and re-runs the
 * C-runtime init before calling its main().  This never returns.
 */
void do_boot(const uint32_t *app_offset)
{
    void (*app_entry)(void);

    DINT;   /* mask maskable interrupts across the handoff */

    app_entry = (void (*)(void))(uintptr_t)app_offset;
    app_entry();

    /* Not reached. */
    while (1)
        ;
}

void arch_reboot(void)
{
    SysCtl_resetDevice();
    while (1)
        ;
}
