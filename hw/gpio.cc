// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "hw/gpio.h"

#include "cpu/barriers.h"
#include "hw/bcm2835.h"

namespace hw {
namespace {

const uint32_t kNumberOfPins = 54;
const uint32_t kNumberOfFunctions = 8;

const uint32_t kBitsPerRegister = 32;
const uint32_t kBitsPerPin = 3;
const uint32_t kPinsPerRegister = kBitsPerRegister / kBitsPerPin;

static_assert(kPinsPerRegister == 10, "10 pins per register");
static_assert(kNumberOfPins / kPinsPerRegister == 5, "Only 6 GPFSEL registers");
static_assert(kNumberOfPins / kBitsPerRegister == 1, "Only 2 GPSET registers");

}

void SetGpioFunction(uint32_t pin_number, GpioFunction::Type function) {
  if (pin_number >= kNumberOfPins || function >= kNumberOfFunctions)
    return;

  uint32_t register_number = pin_number / kPinsPerRegister;
  uint32_t offset = (pin_number % kPinsPerRegister) * kBitsPerPin;
  uint32_t mask = 0x7 << offset;

  volatile uint32_t* register_address = GPFSEL0 + register_number;
  *register_address = (*register_address & ~mask) | (function << offset);

  MEMORY_BARRIER();
}

void SetGpioValue(uint32_t pin_number, bool value) {
  if (pin_number >= kNumberOfPins)
    return;

  uint32_t register_number = pin_number / kBitsPerRegister;
  uint32_t offset = pin_number % kBitsPerRegister;

  volatile uint32_t* register_base = value ? GPSET0 : GPCLR0;
  volatile uint32_t* register_address = register_base + register_number;
  *register_address = 1 << offset;

  MEMORY_BARRIER();
}

}
