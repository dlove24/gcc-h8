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

BASE_DIR=`pwd`

##
## Build the binutils first
##

mkdir -p build/binutils
cd build/binutils

$BASE_DIR/binutils/configure --target="h8300-hms" --prefix=$PREFIX
make CFLAGS=$CFLAGS all

# Ask to install the tools
sudo make install

##
## Build the GCC C and C++ compilers
##

cd $BASE_DIR
mkdir -p build/gcc
cd build/gcc

$BASE_DIR/gcc/configure --target="h8300-hms" --prefix=$PREFIX --enable-languages="c,c++" --with-newlib --with-headers=$BASE_DIR/newlib/newlib/libc/include make CFLAGS=$CFLAGS LANGUAGES="c,c++"

# Ask to install the compiler
sudo make install

##
## Build the newlib C library
##

cd $BASE_DIR
mkdir -p build/gcc
cd build/gcc

$BASE_DIR/newlib/configure --target=h8300-hms --prefix=$PREFIX
make FLAGS=$CFLAGS all

# Ask to install the library
sudo make install
