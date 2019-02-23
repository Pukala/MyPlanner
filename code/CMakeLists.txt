cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++17") #Turn on C++17 Support
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

project (planner)

include_directories(
    /usr/include
    ~/MyPlanner/code/src
    ~/MyPlanner/code/src/manageData
    ~/MyPlanner/code/src/tools
    )

link_libraries(stdc++fs) #Turn on filesystem

add_executable(planner 
    ../main.cpp
    ~/MyPlanner/code/src/Planner.cpp
    ~/MyPlanner/code/src/manageData/DbCreator.cpp
    ~/MyPlanner/code/src/manageData/DataReader.cpp
    ~/MyPlanner/code/src/manageData/DataWriter.cpp
    ~/MyPlanner/code/src/tools/Event.cpp
    )

link_directories(/usr/lib)

target_link_libraries(planner sqlite3)