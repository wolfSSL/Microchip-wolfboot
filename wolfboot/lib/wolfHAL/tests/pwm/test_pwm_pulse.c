/* test_pwm_pulse.c
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
#include <stddef.h>
#include <wolfHAL/wolfHAL.h>
#include "wolfHAL_board.h"
#include "test.h"

/* Period in PWM ticks; the frequency depends on the board's PWM clock and prescaler. */
#define TEST_PWM_PULSE_PERIOD  64000

/* Hold each duty long enough to capture on a logic analyzer. */
#define TEST_PWM_PULSE_HOLD_MS  1000

/* Drive 25/50/75% duty on the wired output so the steps are visible on a logic analyzer. */
static void Test_Pwm_Pulse(void)
{
    const uint8_t duty[] = {25, 50, 75};
    whal_Pwm_ChannelCfg wave = {
        .periodCycles = TEST_PWM_PULSE_PERIOD,
        .pulseCount   = WHAL_PWM_PULSE_COUNT_CONTINUOUS,
        .polarity     = WHAL_PWM_POLARITY_NORMAL,
    };
    size_t i;

    for (i = 0; i < sizeof(duty) / sizeof(duty[0]); i++) {
        wave.pulseCycles = TEST_PWM_PULSE_PERIOD * duty[i] / 100;
        WHAL_ASSERT_EQ(whal_Pwm_Start(BOARD_PWM_DEV, 0, &wave), WHAL_SUCCESS);
        Board_WaitMs(TEST_PWM_PULSE_HOLD_MS);
    }

    WHAL_ASSERT_EQ(whal_Pwm_Stop(BOARD_PWM_DEV, 0), WHAL_SUCCESS);
}

void whal_Test_Pwm_Pulse(void)
{
    WHAL_TEST_SUITE_START("pwm_pulse");
    WHAL_TEST(Test_Pwm_Pulse);
    WHAL_TEST_SUITE_END();
}
