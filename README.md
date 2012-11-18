gcc-h8
======

This repository contains the binary utilities, C library and C compiler
needed to target the H8300 platform (used by BrickOS amongst others).
Most of these sources are taken from the Debian/Ubuntu archives, and
allow the building of suitable tools on non-Debian platforms (those who
are using Debian will be better served using the native packages).

Tested Platforms
----------------

 * Open SUSE 12.3 (64-bit)

Requirements
------------

## Open SUSE 12.3 (b6-bit)

Alongside the standard utilities needed to build GCC, we also need the
32-bit GCC library. The following command should install everything

sudo zypper install make gcc glibc-devel-32bit libgmp-devel bison flex

