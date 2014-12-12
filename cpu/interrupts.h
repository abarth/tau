// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CPU_INTERRUPTS_H_
#define CPU_INTERRUPTS_H_

#define ENABLE_IRQ_INTERRUPTS() asm volatile ("cpsie i")
#define DISABLE_IRQ_INTERRUPTS() asm volatile ("cpsid i")

#endif // CPU_INTERRUPTS_H_


