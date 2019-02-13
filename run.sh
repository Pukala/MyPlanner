#!/bin/bash
cd code
cmake .
make
mv planner ../
rm -rf CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake
