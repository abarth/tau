#!/usr/bin/env python
# Copyright 2014 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import sys
import subprocess

objcopy = "/opt/gnuarm/bin/arm-none-eabi-objcopy"

subprocess.check_call([
    objcopy,
    sys.argv[1],
    "-O",
    "binary",
    sys.argv[2],
])
