/* Copyright 2014 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file. */

SECTIONS {
    .init 0x8000 : {
        *(.init*)
    }
    
    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }
    
    .data : {
        *(.data*)
    }

    __bss_begin = .;

    .bss : {
        *(.bss*)
    }

    __bss_end = .;
}
