// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cpu/wait.h"
#include "dev/led.h"
#include "zen/runtime.h"

extern "C" void InitializeSystem() {
  zen::InitializeRuntime();

  dev::LED led;
  while(1) {
    led.On();
    cpu::SpinWait(0x400000);
    led.Off();
    cpu::SpinWait(0x400000);
  }
}
