// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEV_LED_H_
#define DEV_LED_H_

namespace dev {

class LED {
 public:
  LED();
  ~LED();

  void On();
  void Off();
};

}

#endif // DEV_LED_H_
