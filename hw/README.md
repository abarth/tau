HW Module
=========

The HW module contains a low-level, low-opinion interface to the underlying
hardware in the Raspberry Pi. Memory-mapped registers are represented as structs
that are statically allocated at their memory address.

The information encoded in these interfaces is translated directly from the
BCM2835-ARM-Peripherals.pdf data sheet on the raspberrypi.org. In some cases,
the data sheet is incomplete or incorrect. In those cases, the HW module favors
reality and incorporates information from other sources, typically annoated in
the source code.

The HW module can be used independently from the rest of the Tau system by other
bare metal projects. The HW module does depend on the Zen module for standard
C integer types, but that dependency should be straightforward to untangle.
