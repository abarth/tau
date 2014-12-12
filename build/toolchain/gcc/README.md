GCC Toolchain
=============

To create the GCC toolchain, use the following tar files:

 * http://ftp.gnu.org/gnu/binutils/binutils-2.24.tar.bz2
 * http://ftp.gnu.org/gnu/gcc/gcc-4.9.2/gcc-4.9.2.tar.bz2

binutils
--------

 * ``./configure --target=arm-none-eabi --prefix=/opt/gnuarm``
 * ``make all``
 * ``make install``

gcc
---

 * ``./configure --target=arm-none-eabi --prefix=/opt/gnuarm --without-headers --with-newlib --with-gnu-as --with-gnu-ld --enable-languages='c,c++'``
 * ``make all-gcc``
 * ``make install-gcc``
 * ``make all-target-libgcc CFLAGS_FOR_TARGET="-g -O2"``
 * ``make install-target-libgcc``
