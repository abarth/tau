// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_AUX_H_
#define HW_AUX_H_

#include "zen/int.h"

namespace hw {

// BCM2835-ARM-Peripherals.pdf, section 2.1
struct Aux {
  Aux() = delete;
  ~Aux() = delete;

  // Interrupt status
  volatile uint32_t IRQ;
  static const uint32_t IRQ_MINI_UART = 1 << 0;
  static const uint32_t IRQ_SPI1      = 1 << 1;
  static const uint32_t IRQ_SPI2      = 1 << 2;

  // Enables
  volatile uint32_t ENABLES;
  static const uint32_t ENABLES_MINI_UART = 1 << 0;
  static const uint32_t ENABLES_SPI1      = 1 << 1;
  static const uint32_t ENABLES_SPI2      = 1 << 2;
};

}

#endif // HW_AUX_H_
