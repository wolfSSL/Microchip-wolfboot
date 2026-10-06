/* display.c
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#include <wolfHAL/display/display.h>
#include <wolfHAL/error.h>

inline whal_Error whal_Display_Init(whal_Display *dev)
{
    if (!dev)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Init)
        return WHAL_ENOTSUP;

    return dev->driver->Init(dev);
}

inline whal_Error whal_Display_Deinit(whal_Display *dev)
{
    if (!dev)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Deinit)
        return WHAL_ENOTSUP;

    return dev->driver->Deinit(dev);
}

inline whal_Error whal_Display_Update(whal_Display *dev, uint16_t x, uint16_t y,
                                      uint16_t w, uint16_t h,
                                      const void *data, size_t dataSz)
{
    if (!dev || !data || dataSz == 0 || w == 0 || h == 0)
        return WHAL_EINVAL;
    if (!dev->driver || !dev->driver->Update)
        return WHAL_ENOTSUP;

    return dev->driver->Update(dev, x, y, w, h, data, dataSz);
}
