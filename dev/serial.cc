// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "dev/serial.h"

#include "cpu/barriers.h"
#include "hw/aux.h"
#include "hw/bcm2835.h"
#include "hw/gpio.h"
#include "hw/mini_uart.h"

namespace dev {
namespace {

// From BCM2835-ARM-Peripherals.pdf, page 11:
//
// The mini UART uses 8-times oversampling. The Baudrate can be calculated from:
//
// system_clock_freq / (8 * (baudrate_reg + 1))
//
// If the system clock is 250 MHz and the baud register is zero the baudrate is
// 31.25 Mega baud. (25 Mbits/sec or 3.125 Mbytes/sec). The lowest baudrate with
// a 250 MHz system clock is 476 Baud. 
const uint32_t kSystemClockFrequency = 250000000;
const uint32_t kBaudRate = 115200;
const uint32_t kBaudRegister = kSystemClockFrequency/(8*kBaudRate) - 1;

}

inline bool ReadyForTransmit() {
  return hw::kMiniUART->LSR & hw::MiniUART::LSR_TRANSMITTER_EMPTY;
}

inline bool ReadyForReceive() {
  return hw::kMiniUART->LSR & hw::MiniUART::LSR_DATA_READY;
}

Serial::Serial() {
  hw::SetGpioFunction(14, hw::GpioFunction::kAlternative5);
  hw::SetGpioFunction(15, hw::GpioFunction::kAlternative5);

  hw::kAux->ENABLES |= hw::Aux::ENABLES_MINI_UART;

  hw::kMiniUART->IER = 0;
  hw::kMiniUART->IIR = 0;
  hw::kMiniUART->LCR = hw::MiniUART::LCR_DATA_SIZE_8_BITS;
  hw::kMiniUART->MCR = 0;
  hw::kMiniUART->BAUD = kBaudRegister;
  hw::kMiniUART->CNTL = hw::MiniUART::CNTL_ENABLE_RX |
                        hw::MiniUART::CNTL_ENABLE_TX;
}

Serial::~Serial() {
  hw::kAux->ENABLES &= ~hw::Aux::ENABLES_MINI_UART;
}

void Serial::Write(uint8_t byte) {
  while (!ReadyForTransmit())
    continue;
  hw::kMiniUART->IO = byte;
}

void Serial::WriteBytes(const uint8_t* bytes, size_t length) {
  for (size_t i = 0; i < length; ++i)
    Write(bytes[i]);
}

uint8_t Serial::Read() {
  while (!ReadyForReceive())
    continue;
  return hw::kMiniUART->IO;
}

void Serial::ReadBytes(uint8_t* bytes, size_t length) {
  for (size_t i = 0; i < length; ++i)
    bytes[i] = Read();
}

}
