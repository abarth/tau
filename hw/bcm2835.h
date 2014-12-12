// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HW_BCM2835_H_
#define HW_BCM2835_H_

#include "zen/int.h"

namespace hw {

struct ARMTimer;
struct Aux;
struct Interrupts;
struct MiniUART;
struct SystemTimer;

// Constants from the BCM2835 data sheet:
// http://www.raspberrypi.org/wp-content/uploads/2012/02/BCM2835-ARM-Peripherals.pdf

SystemTimer* const kSystemTimer    = reinterpret_cast<SystemTimer*>(0x20003000);
Interrupts*  const kInterrupts     = reinterpret_cast<Interrupts*> (0x2000B200);
ARMTimer*    const kARMTimer       = reinterpret_cast<ARMTimer*>   (0x2000B400);
Aux*         const kAux            = reinterpret_cast<Aux*>        (0x20215000);
MiniUART*    const kMiniUART       = reinterpret_cast<MiniUART*>   (0x20215040);
void*        const kSPI0           = reinterpret_cast<void*>       (0x20215080);
void*        const kSPI1           = reinterpret_cast<void*>       (0x202150C0);
void*        const kBSC0           = reinterpret_cast<void*>       (0x20205000);
void*        const kBSC1           = reinterpret_cast<void*>       (0x20804000);
void*        const kBSC2           = reinterpret_cast<void*>       (0x20805000);

// GPIO ------------------------------------------------------------------------

// GPIO Function Select 0 32 R/W
volatile uint32_t* const GPFSEL0   = reinterpret_cast<uint32_t*>(0x20200000);

// GPIO Function Select 1 32 R/W
volatile uint32_t* const GPFSEL1   = reinterpret_cast<uint32_t*>(0x20200004);

// GPIO Function Select 2 32 R/W
volatile uint32_t* const GPFSEL2   = reinterpret_cast<uint32_t*>(0x20200008);

// GPIO Function Select 3 32 R/W
volatile uint32_t* const GPFSEL3   = reinterpret_cast<uint32_t*>(0x2020000C);

// GPIO Function Select 4 32 R/W
volatile uint32_t* const GPFSEL4   = reinterpret_cast<uint32_t*>(0x20200010);

// GPIO Function Select 5 32 R/W
volatile uint32_t* const GPFSEL5   = reinterpret_cast<uint32_t*>(0x20200014);

// GPIO Pin Output Set 0 32 W
volatile uint32_t* const GPSET0    = reinterpret_cast<uint32_t*>(0x2020001C);

// GPIO Pin Output Set 1 32 W
volatile uint32_t* const GPSET1    = reinterpret_cast<uint32_t*>(0x20200020);

// GPIO Pin Output Clear 0 32 W
volatile uint32_t* const GPCLR0    = reinterpret_cast<uint32_t*>(0x20200028);

// GPIO Pin Output Clear 1 32 W
volatile uint32_t* const GPCLR1    = reinterpret_cast<uint32_t*>(0x2020002C);

// GPIO Pin Level 0 32 R
volatile uint32_t* const GPLEV0    = reinterpret_cast<uint32_t*>(0x20200034);

// GPIO Pin Level 1 32 R
volatile uint32_t* const GPLEV1    = reinterpret_cast<uint32_t*>(0x20200038);

// GPIO Pin Event Detect Status 0 32 R/W
volatile uint32_t* const GPEDS0    = reinterpret_cast<uint32_t*>(0x20200040);

// GPIO Pin Event Detect Status 1 32 R/W
volatile uint32_t* const GPEDS1    = reinterpret_cast<uint32_t*>(0x20200044);

// GPIO Pin Rising Edge Detect Enable 0 32 R/W
volatile uint32_t* const GPREN0    = reinterpret_cast<uint32_t*>(0x2020004C);

// GPIO Pin Rising Edge Detect Enable 1 32 R/W
volatile uint32_t* const GPREN1    = reinterpret_cast<uint32_t*>(0x20200050);

// GPIO Pin Falling Edge Detect Enable 0 32 R/W
volatile uint32_t* const GPFEN0    = reinterpret_cast<uint32_t*>(0x20200058);

// GPIO Pin Falling Edge Detect Enable 1 32 R/W 
volatile uint32_t* const GPFEN1    = reinterpret_cast<uint32_t*>(0x2020005C);

// GPIO Pin High Detect Enable 0 32 R/W
volatile uint32_t* const GPHEN0    = reinterpret_cast<uint32_t*>(0x20200064);

// GPIO Pin High Detect Enable 1 32 R/W
volatile uint32_t* const GPHEN1    = reinterpret_cast<uint32_t*>(0x20200068);

// GPIO Pin Low Detect Enable 0 32 R/W
volatile uint32_t* const GPLEN0    = reinterpret_cast<uint32_t*>(0x20200070);

// GPIO Pin Low Detect Enable 1 32 R/W
volatile uint32_t* const GPLEN1    = reinterpret_cast<uint32_t*>(0x20200074);

// GPIO Pin Async. Rising Edge Detect 0 32 R/W
volatile uint32_t* const GPAREN0   = reinterpret_cast<uint32_t*>(0x2020007C);

// GPIO Pin Async. Rising Edge Detect 1 32 R/W
volatile uint32_t* const GPAREN1   = reinterpret_cast<uint32_t*>(0x20200080);

// GPIO Pin Async. Falling Edge Detect 0 32 R/W
volatile uint32_t* const GPAFEN0   = reinterpret_cast<uint32_t*>(0x20200088);

// GPIO Pin Async. Falling Edge Detect 1 32 R/W
volatile uint32_t* const GPAFEN1   = reinterpret_cast<uint32_t*>(0x2020008C);

// GPIO Pin Pull-up/down Enable 32 R/W
volatile uint32_t* const GPPUD     = reinterpret_cast<uint32_t*>(0x20200094);

// GPIO Pin Pull-up/down Enable Clock 0 32 R/W
volatile uint32_t* const GPPUDCLK0 = reinterpret_cast<uint32_t*>(0x20200098);

// GPIO Pin Pull-up/down Enable Clock 1 32 R/W
volatile uint32_t* const GPPUDCLK1 = reinterpret_cast<uint32_t*>(0x2020009C);

}

#endif // HW_BCM2835_H_
