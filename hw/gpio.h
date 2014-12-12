// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_GPIO_H_
#define HW_GPIO_H_

#include "zen/int.h"

namespace hw {

namespace GpioFunction {
enum Type {
  kInput        = 0,
  kOutput       = 1,
  kAlternative0 = 4,
  kAlternative1 = 5,
  kAlternative2 = 6,
  kAlternative3 = 7,
  kAlternative4 = 3,
  kAlternative5 = 2,
};
}

void SetGpioFunction(uint32_t pin_number, GpioFunction::Type function);
void SetGpioValue(uint32_t pin_number, bool value);

}

#endif // HW_GPIO_H_
