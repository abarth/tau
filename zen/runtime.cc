// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "zen/runtime.h"

#include "zen/mem.h"

namespace zen {

extern "C" uint8_t __bss_begin;
extern "C" uint8_t __bss_end;

void InitializeRuntime() {
  memset(&__bss_begin, '\0', &__bss_end - &__bss_begin);
}

}
