cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++17") #Turn on C++17 Support
#include files to test
include_directories(~/MyPlanner/tests/googletest/googletest/include)
add_executable(utest test.cpp)

target_link_libraries(tutorial sqlite3)

target_link_libraries(utest ~/MyPlanner/tests/googletest/googletest/lib/libgtest.a pthread)

