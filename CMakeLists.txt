cmake_minimum_required(VERSION 3.10)
project(TwelveProject)

set(CMAKE_CXX_STANDARD 11)

# Основная программа
add_executable(TwelveProject main.cpp Twelve.cpp)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Тесты
add_executable(RunTests test.cpp Twelve.cpp)
target_link_libraries(RunTests gtest gtest_main pthread)
