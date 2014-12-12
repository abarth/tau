// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CPU_WAIT_H_
#define CPU_WAIT_H_

#include "zen/int.h"

namespace cpu {

extern "C" void SpinWait(uint32_t count);

}

#endif // CPU_WAIT_H_
