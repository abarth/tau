// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_SYSTEM_TIMER_H_
#define HW_SYSTEM_TIMER_H_

#include "zen/int.h"

namespace hw {

// BCM2835-ARM-Peripherals.pdf, section 12
struct SystemTimer {
  SystemTimer() = delete;
  ~SystemTimer() = delete;

  // System Timer Control/Status
  volatile uint32_t CS;

  // System Timer Counter Lower 32 bits
  volatile uint32_t CLO;

  // System Timer Counter Higher 32 bits
  volatile uint32_t CHI;

  // System Timer Compare 0
  volatile uint32_t C0;

  // System Timer Compare 1
  volatile uint32_t C1;

  // System Timer Compare 2
  volatile uint32_t C2;

  // System Timer Compare 3
  volatile uint32_t C3;
};

}

#endif // HW_SYSTEM_TIMER_H_
