/* disk_trailer.h
 *
 * On-media boot-confirmation trailer for the disk boot path.
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfBoot.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef DISK_TRAILER_H
#define DISK_TRAILER_H

#include <stdint.h>

/* This is the partition trailer update_flash.c already keeps, placed in the
 * tail of a raw boot partition: the 4-byte "BOOT" magic in the last four
 * bytes of the partition, and the state byte immediately below it. The magic
 * is what tells "never written" from a state, and on a disk that is
 * load-bearing rather than decorative: a freshly imaged partition tail is
 * usually 0x00, and 0x00 is IMG_STATE_SUCCESS, so without the magic a blank
 * slot would read as already confirmed.
 *
 * The states are the default-polarity IMG_STATE_* values, written literally.
 * IMG_STATE_* flips with WOLFBOOT_FLAGS_INVERT, and a format two programs
 * must agree on must not change meaning with a build option. The bytes on
 * media are therefore the same as a flash trailer's on a default-polarity
 * build, whatever polarity either program was built with.
 *
 * Both sides of the contract include this header - the loader in
 * src/update_disk.c and the userspace tool in hal/library_fs.c - so the
 * offset, the magic and the four state values have exactly one definition.
 */

#define DISK_TRAILER_SZ         8U      /* state byte + magic, read together */
#define DISK_TRAILER_MIN_PART   512U    /* one LBA, the smallest tail usable */

#define DISK_TRAILER_STATE_IDX  3U      /* state byte within the trailer */
#define DISK_TRAILER_MAGIC_IDX  4U      /* "BOOT", to the end of the tail */

#define DISK_STATE_NEW          0xFFU   /* IMG_STATE_NEW      */
#define DISK_STATE_UPDATING     0x70U   /* IMG_STATE_UPDATING */
#define DISK_STATE_TESTING      0x10U   /* IMG_STATE_TESTING  */
#define DISK_STATE_SUCCESS      0x00U   /* IMG_STATE_SUCCESS  */

/* Byte offset of the trailer in a partition of size sz, or a non-zero return
 * when the partition is too small to carry one. Derived from the size the
 * caller observed, so both programs locate it the same way: from the media,
 * never from a compile-time partition size. */
static inline int disk_trailer_offset(uint64_t sz, uint64_t *off)
{
    if ((off == NULL) || (sz < DISK_TRAILER_MIN_PART)) {
        return -1;
    }
    *off = sz - (uint64_t)DISK_TRAILER_SZ;
    return 0;
}

/* Fill buf with a trailer carrying state. */
static inline void disk_trailer_encode(uint8_t *buf, uint8_t state)
{
    unsigned int i;

    for (i = 0; i < DISK_TRAILER_SZ; i++) {
        buf[i] = 0xFF;
    }
    buf[DISK_TRAILER_STATE_IDX] = state;
    buf[DISK_TRAILER_MAGIC_IDX + 0] = 'B';
    buf[DISK_TRAILER_MAGIC_IDX + 1] = 'O';
    buf[DISK_TRAILER_MAGIC_IDX + 2] = 'O';
    buf[DISK_TRAILER_MAGIC_IDX + 3] = 'T';
}

/* State recorded in buf. A missing magic reads as NEW, so a partition
 * written by a tool that knows nothing of this is never treated as failed. */
static inline uint8_t disk_trailer_decode(const uint8_t *buf)
{
    if ((buf[DISK_TRAILER_MAGIC_IDX + 0] != 'B') ||
        (buf[DISK_TRAILER_MAGIC_IDX + 1] != 'O') ||
        (buf[DISK_TRAILER_MAGIC_IDX + 2] != 'O') ||
        (buf[DISK_TRAILER_MAGIC_IDX + 3] != 'T')) {
        return DISK_STATE_NEW;
    }
    return buf[DISK_TRAILER_STATE_IDX];
}

static inline const char *disk_trailer_state_name(uint8_t state)
{
    switch (state) {
        case DISK_STATE_NEW:
            return "NEW";
        case DISK_STATE_UPDATING:
            return "UPDATING";
        case DISK_STATE_TESTING:
            return "TESTING";
        case DISK_STATE_SUCCESS:
            return "SUCCESS";
        default:
            return "UNKNOWN";
    }
}

#endif /* DISK_TRAILER_H */
