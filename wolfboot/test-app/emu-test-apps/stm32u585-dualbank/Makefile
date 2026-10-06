# Makefile
#
# Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
#
# This file is part of wolfBoot.
#
# Contact licensing@wolfssl.com with any questions or comments.
#
# https://www.wolfssl.com

-include ../../../.config

WOLFBOOT_PARTITION_BOOT_ADDRESS?=0x08010000
WOLFBOOT_PARTITION_UPDATE_ADDRESS?=0x08110000
WOLFBOOT_PARTITION_SIZE?=0x30000
IMAGE_HEADER_SIZE?=1024

APP_ORIGIN=$(shell printf '0x%08x' $$(( $(WOLFBOOT_PARTITION_BOOT_ADDRESS) + $(IMAGE_HEADER_SIZE) )))
APP_SIZE=$(shell printf '0x%08x' $$(( $(WOLFBOOT_PARTITION_SIZE) - $(IMAGE_HEADER_SIZE) )))
MARKER_ADDR=$(shell printf '0x%08x' $$(( $(WOLFBOOT_PARTITION_BOOT_ADDRESS) + $(WOLFBOOT_PARTITION_SIZE) )))

CC=arm-none-eabi-gcc
OBJCOPY?=arm-none-eabi-objcopy

CFLAGS:=-mcpu=cortex-m33 -mthumb -Os -ffreestanding -fdata-sections -ffunction-sections -g -ggdb
CFLAGS+=-DUPDATE_BASE=$(WOLFBOOT_PARTITION_UPDATE_ADDRESS)u
CFLAGS+=-DMARKER_ADDR=$(MARKER_ADDR)u
LDFLAGS:=-nostdlib -T target.ld -Wl,-gc-sections

all: app.bin

target.ld: target.ld.in
	sed -e "s/@FLASH_ORIGIN@/$(APP_ORIGIN)/g" \
	    -e "s/@FLASH_SIZE@/$(APP_SIZE)/g" $< > $@

app.elf: staging_app.c target.ld
	$(CC) $(CFLAGS) staging_app.c $(LDFLAGS) -o $@

app.bin: app.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f app.elf app.bin image.bin image_v*_signed.bin target.ld

.PHONY: all clean
