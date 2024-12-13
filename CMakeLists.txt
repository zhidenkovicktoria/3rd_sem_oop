cmake_minimum_required(VERSION 3.10)
project(Lab5)

set(CMAKE_CXX_STANDARD 17)

# Add the main executable
add_executable(Lab5 src/main.cpp src/CustomMemoryResource.cpp)

# Include directories
include_directories(include)

# Find and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
enable_testing()
add_executable(runTests tests/tests.cpp src/CustomMemoryResource.cpp)
target_link_libraries(runTests gtest gtest_main)

# Add tests
add_test(NAME AllTests COMMAND runTests)
