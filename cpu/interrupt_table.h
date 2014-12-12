// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CPU_INTERRUPT_TABLE_H_
#define CPU_INTERRUPT_TABLE_H_

#include "cpu/instruction.h"

namespace cpu {

// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0203j/Bgbcjggh.html
class InterruptTable {
 public:
  InterruptTable();

  void SetIRQStub(void stub());

  void Install();

 private:
  Instruction reset;
  Instruction undefined;
  Instruction svc;
  Instruction prefetch;
  Instruction abort;
  Instruction reserved;
  Instruction irq;
  Instruction fiq;
};

}

#endif // CPU_INTERRUPT_TABLE_H_
