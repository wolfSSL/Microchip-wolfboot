; /* aes_asm.asm
;  *
; * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
;  *
;  * This file is part of wolfBoot.
;  *
;  * Contact licensing@wolfssl.com with any questions or comments.
;  *
;  * https://www.wolfssl.com
;  */



;
;
;  /* See Intel Advanced Encryption Standard (AES) Instructions Set White Paper
;   * by Israel, Intel Mobility Group Development Center, Israel Shay Gueron
;   */
;
;   /* This file is in intel asm syntax, see .s for at&t syntax */
;


fips_version = 0
IFDEF HAVE_FIPS
  fips_version = 1
  IFDEF HAVE_FIPS_VERSION
    fips_version = HAVE_FIPS_VERSION
  ENDIF
ENDIF

IF fips_version GE 2
  fipsAb SEGMENT ALIAS(".fipsA$b") 'CODE'
ELSE
  _text SEGMENT
ENDIF

IF fips_version GE 2
  fipsAb ENDS
ELSE
  _text ENDS
ENDIF

END
