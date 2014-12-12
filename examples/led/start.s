/* Copyright 2014 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file. */

.section .init
.globl _start
_start:
mov sp,#0x8000
b InitializeSystem
