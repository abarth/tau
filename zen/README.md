Zen Module
==========

The Zen module is a poor implementation of the usual C runtime for ARMv6 with
zero dependencies.

Hopefully we'll be able to replace Zen with a real C runtime if we can find one
that has zero dependencies. For now, Zen purposely uses non-standard header
names to avoid conflicts with libc.
