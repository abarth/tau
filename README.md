Tau
===

Tau is a bare-metal operating system for the Raspberry Pi. Tau has zero external
dependencies and runs directly from boot on the Raspberry Pi. Tau is written in
a mix of ARM assembly and C++11 but does not link against libc or libc++.

Currently, Tau supports a limited number of the peripherals available on the Pi.
Over time, we'd like to add support for more peripherals, including the USB and
video controllers.

Getting started
---------------

Tau supports a Linux host environment. Tau has been tested using Ubuntu 12.04,
but most Linux host environments should work.

The first step is to [install Chromium's ``depot_tools``](http://www.chromium.org/developers/how-tos/install-depot-tools).
We use ``depot_tools`` to pull in our other dependencies (e.g., ``gn``).

Once you've installed ``depot_tools``, create a ``.gclient`` file in an empty
directory with the following contents:

```
solutions = [{
  'managed': False,
  'name': 'src',
  'url': 'git@github.com:abarth/tau.git',
  'deps_file': 'DEPS',
}]
```

Now, run ``gclient sync`` to pull down this repository and its dependencies.

The toolchain for building Tau is not managed with gclient. Instead, you'll need
to build and install the toolchain using the
[instructions in the toolchain directory](build/toolchain/gcc/README.md). In the
future, we would like to use gclient to make the toolchain dependency hermetic.

Building the code
-----------------

Tau uses a ``ninja``-based build system generated with ``gn``. To build Tau, we
first need to create the ``ninja`` files:

 * ``gn gen out``

We can then use ``ninja`` to build the system:

 * ``ninja -C out``

Running the examples
--------------------

To run the examples, you'll need a Raspberry Pi, a MicroSD card, and a (ideally)
a serial cable. To run the LED example, copy ``led.img`` to your MicroSD card,
overwriting the ``kernel.img`` file. Note: When you copy ``led.img`` to your
MicroSD card, you'll need to rename it to ``kernel.img`` in order for the Pi's
boot process to find it.

License
-------

Tau is available under a BSD-style license that can be found in the LICENSE
file.

Acknowledgements
----------------

Special thanks to [David Welch](https://github.com/dwelch67) and
[Rene Stange](https://github.com/rsta2/). Their example bare-metal systems for
the Raspberry Pi have saved me an immeasurable amount of heartache.
