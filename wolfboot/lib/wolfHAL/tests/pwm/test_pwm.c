/* test_pwm.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfHAL/wolfHAL.h>
#include "wolfHAL_board.h"
#include "test.h"

static void Test_Pwm_Api(void)
{
    /* A waveform every driver can represent: channel 0, continuous, 25% duty. */
    whal_Pwm_ChannelCfg wave = {
        .periodCycles = 1000,
        .pulseCycles  = 250,
        .pulseCount   = WHAL_PWM_PULSE_COUNT_CONTINUOUS,
        .polarity     = WHAL_PWM_POLARITY_NORMAL,
    };

    /* Init ran in Board_Init; Start/Stop is a repeatable toggle, so run two cycles. */
    WHAL_ASSERT_EQ(whal_Pwm_Start(BOARD_PWM_DEV, 0, &wave), WHAL_SUCCESS);
    WHAL_ASSERT_EQ(whal_Pwm_Stop(BOARD_PWM_DEV, 0), WHAL_SUCCESS);
    WHAL_ASSERT_EQ(whal_Pwm_Start(BOARD_PWM_DEV, 0, &wave), WHAL_SUCCESS);
    WHAL_ASSERT_EQ(whal_Pwm_Stop(BOARD_PWM_DEV, 0), WHAL_SUCCESS);

    /* Structural violations the generic dispatch rejects: pulse > period, and null pointers. */
    wave.pulseCycles = wave.periodCycles + 1;
    WHAL_ASSERT_EQ(whal_Pwm_Start(BOARD_PWM_DEV, 0, &wave), WHAL_EINVAL);
    wave.pulseCycles = 250;

    WHAL_ASSERT_EQ(whal_Pwm_Start(NULL, 0, &wave), WHAL_EINVAL);
    WHAL_ASSERT_EQ(whal_Pwm_Start(BOARD_PWM_DEV, 0, NULL), WHAL_EINVAL);
}

void whal_Test_Pwm(void)
{
    WHAL_TEST_SUITE_START("pwm");
    WHAL_TEST(Test_Pwm_Api);
    WHAL_TEST_SUITE_END();
}
