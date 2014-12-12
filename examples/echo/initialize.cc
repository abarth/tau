// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "dev/led.h"
#include "dev/serial.h"
#include "zen/runtime.h"

extern "C" void InitializeSystem() {
  zen::InitializeRuntime();

  dev::LED led;
  dev::Serial serial;

  bool on = false;

  serial.WriteString("Ready!\r\n");
  while(1) {
    uint8_t byte = serial.Read();

    serial.Write(byte);
    if (byte == '\r')
      serial.Write('\n');

    if (on) {
      led.Off();
      on = false;
    } else {
      led.On();
      on = true;
    }
  }
}
