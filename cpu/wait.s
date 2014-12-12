/* Copyright 2014 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file. */

.globl SpinWait
SpinWait:
sub r0, #1
cmp r0, #0
bne SpinWait
bx lr
