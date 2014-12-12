// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_MINI_UART_H_
#define HW_MINI_UART_H_

#include "zen/int.h"

namespace hw {

// BCM2835-ARM-Peripherals.pdf, section 2.2
//
// Apparently, the Mini UART doesn't work quite as described in the BCM2835
// data sheet.  Additional constants from the 16550 UART data sheet as noted:
// http://www.cs.indiana.edu/classes/b649-sjoh/reading/SISDA-16550-UART.pdf
struct MiniUART {
  MiniUART() = delete;
  ~MiniUART() = delete;

  // Mini Uart I/O Data (8 bits)
  volatile uint32_t IO;

  // Mini Uart Interrupt Enable
  volatile uint32_t IER;
  static const uint32_t IER_INTERRUPT_PENDING = 1 << 0;
  static const uint32_t IER_READY_TX          = 1 << 1;
  static const uint32_t IER_READY_RX          = 1 << 2;

  // Mini Uart Interrupt Identify
  volatile uint32_t IIR;
  static const uint32_t IIR_ENABLE_TX         = 1 << 0;
  static const uint32_t IIR_ENABLE_RX         = 1 << 1;

  // Mini Uart Line Control
  volatile uint32_t LCR;
  static const uint32_t LCR_BREAK             = 1 << 6;
  static const uint32_t LCR_DLAB_ACCESS       = 1 << 7;
  // From SISDA-16550-UART.pdf, Table 5
  static const uint32_t LCR_DATA_SIZE_5_BITS  = 0;
  static const uint32_t LCR_DATA_SIZE_6_BITS  = 1;
  static const uint32_t LCR_DATA_SIZE_7_BITS  = 2;
  static const uint32_t LCR_DATA_SIZE_8_BITS  = 3;

  // Mini Uart Modem Control
  volatile uint32_t MCR;
  static const uint32_t MCR_RCS               = 1 << 1;

  // Mini Uart Line Status
  volatile uint32_t LSR;
  static const uint32_t LSR_DATA_READY        = 1 << 0;
  static const uint32_t LSR_RECEIVER_OVERRUN  = 1 << 1;
  static const uint32_t LSR_TRANSMITTER_EMPTY = 1 << 5;
  static const uint32_t LSR_TRANSMITTER_IDLE  = 1 << 6;

  // Mini Uart Modem Status
  volatile uint32_t MSR;
  static const uint32_t MSR_CTS_STATUS        = 1 << 5;

  // Mini Uart Scratch
  volatile uint32_t SCRATCH;

  // Mini Uart Extra Control
  volatile uint32_t CNTL;
  static const uint32_t CNTL_ENABLE_RX        = 1 << 0;
  static const uint32_t CNTL_ENABLE_TX        = 1 << 1;

  // Mini Uart Extra Status
  volatile uint32_t STAT;

  // Mini Uart Baudrate (16 bits)
  volatile uint32_t BAUD;
};

}

#endif // HW_MINI_UART_H_
