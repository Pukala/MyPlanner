cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++17") #Turn on C++17 Support
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

#include files to test
include_directories(
    /usr/include
    ~/MyPlanner/tests/googletest/googletest/include
    ~/MyPlanner/code/src/manageData
    ~/MyPlanner/code/src/tools
    )

link_libraries(stdc++fs) #Turn on filesystem

add_executable(utest 
TestPlaner.cpp
../code//src/manageData/DataReader.cpp
../code//src/manageData/DbCreator.cpp
../code//src/manageData/DataWriter.cpp
../code//src/tools/Event.cpp
)



target_link_libraries(utest sqlite3)

target_link_libraries(utest ~/MyPlanner/tests/googletest/googletest/lib/libgtest.a pthread)

