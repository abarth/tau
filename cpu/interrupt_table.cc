// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cpu/interrupt_table.h"

#include "cpu/barriers.h"

namespace cpu {
namespace {

InterruptTable* const kActiveInterruptTable = nullptr;

inline uint32_t OffsetFrom(void stub(), uint32_t* instruction_address) {
  // The  branch offset must take account of the prefetch operation, which
  // causes the  PC to be 2 words (8 bytes) ahead of the current instruction.
  //   -- http://aelmahmoudy.users.sourceforge.net/electronix/arm/chapter2.htm
  uint32_t* stub_address = reinterpret_cast<uint32_t*>(stub);
  return stub_address - instruction_address - 2;
}

void LoopForever() {
  while(1) { }
}

}

InterruptTable::InterruptTable() {
  reset = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->reset));
  undefined = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->undefined));
  svc = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->svc));
  prefetch = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->prefetch));
  abort = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->abort));
  reserved = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->reserved));
  irq = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->irq));
  fiq = CreateBranchInstruction(OffsetFrom(LoopForever,
      &kActiveInterruptTable->fiq));
}

void InterruptTable::SetIRQStub(void stub()) {
  irq = CreateBranchInstruction(OffsetFrom(stub, &kActiveInterruptTable->irq));
}

void InterruptTable::Install() {
  *kActiveInterruptTable = *this;
  MEMORY_BARRIER();
  __builtin___clear_cache(kActiveInterruptTable, kActiveInterruptTable + 1);
}

}
