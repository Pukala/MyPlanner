#!/bin/bash
cmake .
make
rm -rf CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake
./utest
rm utest;
