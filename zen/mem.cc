// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "zen/mem.h"

void* memset(void* start, int c, size_t n) {
  unsigned char value = c & 0xF;
  unsigned char* current = static_cast<unsigned char*>(start);
  unsigned char* end = current + n;
  while (current != end)
    *current++ = value;
  return start;
}
