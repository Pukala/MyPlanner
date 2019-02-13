cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++17") #Turn on C++17 Support

project (planner)

include_directories(
    /usr/include
    ~/MyPlanner/code/include
    )

link_libraries(stdc++fs) #Turn on filesystem

add_executable(planner 
    ../main.cpp
    ~/MyPlanner/code/source/Planner.cpp
    ~/MyPlanner/code/source/DbCreator.cpp
    )

link_directories(/usr/lib)

target_link_libraries(planner sqlite3)