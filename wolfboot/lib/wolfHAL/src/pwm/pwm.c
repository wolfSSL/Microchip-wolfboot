/* pwm.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfHAL/pwm/pwm.h>
#include <wolfHAL/error.h>

inline whal_Error whal_Pwm_Init(whal_Pwm *dev)
{
    if (!dev)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Init)
        return WHAL_ENOTSUP;

    return dev->driver->Init(dev);
}

inline whal_Error whal_Pwm_Deinit(whal_Pwm *dev)
{
    if (!dev)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Deinit)
        return WHAL_ENOTSUP;

    return dev->driver->Deinit(dev);
}

inline whal_Error whal_Pwm_Start(whal_Pwm *dev, uint8_t channel,
                                 const whal_Pwm_ChannelCfg *cfg)
{
    if (!dev || !cfg || cfg->periodCycles == 0 ||
        cfg->pulseCycles > cfg->periodCycles)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Start)
        return WHAL_ENOTSUP;

    return dev->driver->Start(dev, channel, cfg);
}

inline whal_Error whal_Pwm_Stop(whal_Pwm *dev, uint8_t channel)
{
    if (!dev)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Stop)
        return WHAL_ENOTSUP;

    return dev->driver->Stop(dev, channel);
}
