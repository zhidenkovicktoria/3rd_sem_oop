cmake_minimum_required(VERSION 3.10)
project(FigureProject)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(FigureProgram main.cpp solution.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(RunTests test.cpp solution.cpp)
target_link_libraries(RunTests ${GTEST_LIBRARIES} pthread)
