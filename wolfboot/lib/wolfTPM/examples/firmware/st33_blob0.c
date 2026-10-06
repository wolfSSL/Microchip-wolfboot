/* st33_blob0.c
 *
 * Copyright (C) 2006-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfTPM.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <examples/firmware/st33_blob0.h>

const size_t st33_blob0_sizes[ST33_BLOB0_SIZE_CNT] = {
    ST33_BLOB0_SIZE_NON_LMS_RSA,
    ST33_BLOB0_SIZE_NON_LMS,
    ST33_BLOB0_SIZE_LMS
};

int st33_blob0_family(word32 fwVerMajor)
{
    switch (fwVerMajor) {
        case 1:  /* ST33TPHF2X, SPI firmware line */
        case 2:  /* ST33TPHF2X, I2C firmware line */
        case 74: /* ST33TPHF2X, older line both buses (74.8 SPI, 74.9 I2C) */
            return ST33_BLOB0_FAMILY_TPHF2X;
        case 9:  /* ST33KTPM2X */
        case 10: /* ST33KTPM2A */
            return ST33_BLOB0_FAMILY_KTPM;
        /* Uncharacterized majors stay unknown so no size or family rule is
         * asserted against them, even ones the tool can name */
        default:
            return ST33_BLOB0_FAMILY_UNKNOWN;
    }
}

size_t st33_expected_blob0(word32 fwVerMajor, word32 fwVerMinor)
{
    switch (st33_blob0_family(fwVerMajor)) {
        case ST33_BLOB0_FAMILY_TPHF2X:
            return ST33_BLOB0_SIZE_NON_LMS_RSA;
        case ST33_BLOB0_FAMILY_KTPM:
            if (fwVerMinor < ST33_BLOB0_VERSION_LMS_REQUIRED) {
                return ST33_BLOB0_SIZE_NON_LMS;
            }
            return ST33_BLOB0_SIZE_LMS;
        default:
            return 0; /* unknown family, assert nothing */
    }
}

size_t st33_blob0_candidates(word32 fwVerMajor, word32 fwVerMinor,
    int haveCaps, size_t* cand)
{
    size_t idx;
    size_t candCnt = 0;
    size_t expected;

    if (cand == NULL) {
        return 0;
    }
    if (haveCaps) {
        expected = st33_expected_blob0(fwVerMajor, fwVerMinor);
        if (expected != 0) {
            cand[candCnt++] = expected;
        }
    }
    for (idx = 0; idx < ST33_BLOB0_SIZE_CNT; idx++) {
        if (candCnt == 0 || cand[0] != st33_blob0_sizes[idx]) {
            cand[candCnt++] = st33_blob0_sizes[idx];
        }
    }
    return candCnt;
}

size_t st33_detect_blob0(const byte* buf, size_t bufSz, const size_t* cand,
    size_t candCnt)
{
    size_t i, off, len;

    if (buf == NULL || cand == NULL) {
        return 0;
    }
    for (i = 0; i < candCnt; i++) {
        if (bufSz <= cand[i]) {
            continue;
        }
        off = cand[i];
        while (off + 3 <= bufSz) {
            if (buf[off] == 0) {
                break; /* end marker, not a record */
            }
            len = ((size_t)buf[off + 1] << 8) | buf[off + 2];
            /* Reject rather than walk past the end: a payload that does not
             * fit means this candidate is not where blob0 ends. Checked as a
             * subtraction on the remaining bytes so off + 3 + len can never
             * be formed out of range. */
            if (len == 0 || len > bufSz - off - 3) {
                break;
            }
            off += 3 + len;
        }
        if (off == bufSz) {
            return cand[i];
        }
    }
    return 0;
}
