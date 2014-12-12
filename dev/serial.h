// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEV_SERIAL_H_
#define DEV_SERIAL_H_

#include "zen/int.h"

namespace dev {

class Serial {
 public:
  Serial();
  ~Serial();

  void Write(uint8_t byte);
  void WriteBytes(const uint8_t* bytes, size_t length);

  template<size_t N>
  void WriteString(const char (&string)[N]) {
    WriteBytes(reinterpret_cast<const uint8_t*>(string), N - 1);
  }

  uint8_t Read();
  void ReadBytes(uint8_t* bytes, size_t length);
};

}

#endif // DEV_SERIAL_H_
