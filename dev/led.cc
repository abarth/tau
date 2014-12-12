// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "dev/led.h"

#include "hw/gpio.h"

namespace dev {

LED::LED() {
  hw::SetGpioFunction(47, hw::GpioFunction::kOutput);
}

LED::~LED() {
}

void LED::On() {
  hw::SetGpioValue(47, true);
}

void LED::Off() {
  hw::SetGpioValue(47, false);
}

}
