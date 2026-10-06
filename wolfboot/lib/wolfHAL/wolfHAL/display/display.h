/* display.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef WHAL_DISPLAY_H
#define WHAL_DISPLAY_H

#include <wolfHAL/error.h>
#include <stdint.h>
#include <stddef.h>

/*
 * @file display.h
 * @brief Generic display abstraction and driver interface.
 *
 * Provides a bus-agnostic API for driving pixel-addressable displays.
 * Each display driver implements the vtable and talks to its panel over
 * the appropriate bus (SPI, parallel, etc.) internally. The Update
 * function pushes a rectangular region of pixel data to the panel; the
 * pixel format and the byte layout of the data buffer are defined by
 * each driver.
 */

typedef struct whal_Display whal_Display;

/*
 * @brief Driver vtable for display devices.
 */
typedef struct {
    /* Initialize the display hardware. */
    whal_Error (*Init)(whal_Display *dev);
    /* Deinitialize the display hardware. */
    whal_Error (*Deinit)(whal_Display *dev);
    /* Push pixel data to the w-by-h region whose top-left corner is (x,y). */
    whal_Error (*Update)(whal_Display *dev, uint16_t x, uint16_t y,
                         uint16_t w, uint16_t h,
                         const void *data, size_t dataSz);
} whal_DisplayDriver;

/*
 * @brief Display device instance tying a driver and configuration.
 */
struct whal_Display {
    const whal_DisplayDriver *driver;
    void *cfg;
};

/*
 * @brief Initialize a display device and its driver.
 *
 * @param dev Pointer to the display instance to initialize.
 *
 * @retval WHAL_SUCCESS Driver-specific init completed.
 * @retval WHAL_EINVAL  Null pointer.
 * @retval WHAL_ENOTSUP No driver bound or operation unsupported.
 */
whal_Error whal_Display_Init(whal_Display *dev);
/*
 * @brief Deinitialize a display device and release resources.
 *
 * @param dev Pointer to the display instance to deinitialize.
 *
 * @retval WHAL_SUCCESS Driver-specific deinit completed.
 * @retval WHAL_EINVAL  Null pointer.
 * @retval WHAL_ENOTSUP No driver bound or operation unsupported.
 */
whal_Error whal_Display_Deinit(whal_Display *dev);
/*
 * @brief Push pixel data to a rectangular region of the display.
 *
 * Updates the @p w by @p h rectangle whose top-left corner is (@p x,
 * @p y) with the pixel data in @p data. The pixel format and the
 * expected size of @p data for a given region are defined by each
 * driver.
 *
 * @param dev    Pointer to the display instance.
 * @param x      Left column of the region.
 * @param y      Top row of the region.
 * @param w      Width of the region in pixels.
 * @param h      Height of the region in pixels.
 * @param data   Pointer to the driver-defined pixel data to push.
 * @param dataSz Size of @p data in bytes.
 *
 * @retval WHAL_SUCCESS Region updated successfully.
 * @retval WHAL_EINVAL  Null pointer or malformed region request.
 * @retval WHAL_ENOTSUP No driver bound, or region/data size unsupported.
 */
whal_Error whal_Display_Update(whal_Display *dev, uint16_t x, uint16_t y,
                               uint16_t w, uint16_t h,
                               const void *data, size_t dataSz);

#endif /* WHAL_DISPLAY_H */
