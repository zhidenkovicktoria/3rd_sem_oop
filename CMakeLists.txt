cmake_minimum_required(VERSION 3.10)
project(FigureProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(FigureProgram main.cpp src/Figure.cpp src/Pentagon.cpp src/Hexagon.cpp src/Octagon.cpp src/FigureArray.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(RunTests test.cpp src/Figure.cpp src/Pentagon.cpp src/Hexagon.cpp src/Octagon.cpp src/FigureArray.cpp)
target_link_libraries(RunTests ${GTEST_LIBRARIES} pthread)
