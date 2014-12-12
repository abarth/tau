// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CPU_INSTRUCTIONS_H_
#define CPU_INSTRUCTIONS_H_

#include "zen/int.h"

namespace cpu {

typedef uint32_t Instruction;

// http://aelmahmoudy.users.sourceforge.net/electronix/arm/chapter2.htm
//
// Branch instructions contain a signed 2's complement 24 bit offset.  This  is
// shifted left two bits, sign extended to 32 bits, and added to  the  PC.  The
// instruction can therefore specify a  branch  of  +/-  32Mbytes.  The  branch
// offset must take account of the prefetch operation, which causes the  PC  to
// be 2 words (8 bytes) ahead of the current instruction.
//
inline Instruction CreateBranchInstruction(uint32_t offset) {
  return 0xEA000000 | (offset & 0xFFFFFF);
}

}

#endif // CPU_INSTRUCTIONS_H_
