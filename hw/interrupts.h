// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_INTERRUPTS_H_
#define HW_INTERRUPTS_H_

#include "zen/int.h"

namespace hw {

// BCM2835-ARM-Peripherals.pdf, section 7.5
struct Interrupts {
  Interrupts() = delete;
  ~Interrupts() = delete;

  // IRQ basic pending
  volatile uint32_t BASIC;

  // IRQ pending 1
  volatile uint32_t PEND1;

  // IRQ pending 2
  volatile uint32_t PEND2;

  // FIQ control
  volatile uint32_t FIQ_CONTROL;

  // Enable IRQs 1
  volatile uint32_t ENABLE1;

  // Enable IRQs 2
  volatile uint32_t ENABLE2;

  // Enable Basic IRQs
  volatile uint32_t ENABLE_BASIC;

  // Disable IRQs 1
  volatile uint32_t DISABLE1;

  // Disable IRQs 2
  volatile uint32_t DISABLE2;

  // Disable Basic IRQs
  volatile uint32_t DISABLE_BASIC;
};

}

#endif // HW_INTERRUPTS_H_
