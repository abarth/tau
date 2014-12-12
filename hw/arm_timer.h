// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_ARM_TIMER_H_
#define HW_ARM_TIMER_H_

#include "zen/int.h"

namespace hw {

// BCM2835-ARM-Peripherals.pdf, section 14
struct ARMTimer {
  ARMTimer() = delete;
  ~ARMTimer() = delete;

  // Load
  volatile uint32_t LOD;

  // Value (Read only)
  volatile uint32_t VAL;

  // Control
  volatile uint32_t CTL;

  // IRQ clear (Write only)
  volatile uint32_t CLI;

  // Raw IRQ (Read only)
  volatile uint32_t RIS;

  // Masked IRQ (Read only)
  volatile uint32_t MIS;

  // Reload
  volatile uint32_t RLD;

  // Pre-divisor
  volatile uint32_t DIV;

  // Free-running counter
  volatile uint32_t CNT;
};

}

#endif // HW_ARM_TIMER_H_
