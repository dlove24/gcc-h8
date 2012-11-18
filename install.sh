#!/bin/sh

# Prefix of the place to install the tools to
PREFIX="/usr/local"

# Flags passed to the C complier when building the tools and library
CFLAGS="-O2"

###############################################################################
###
### Everything below here should "just work".
###
###############################################################################

##
## Build the binutils first
##

mkdir -p build/binutils
cd build/binutils

../../binutils/configure --target="h8300-hms" --prefix=$PREFIX
make CFLAGS=$CFLAGS

# Ask to install the tools
sudo make install
