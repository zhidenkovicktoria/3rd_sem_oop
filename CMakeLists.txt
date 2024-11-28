cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(BinaryRepresentation)

# Устанавливаем минимальную версию компилятора GCC
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавляем исполняемый файл
add_executable(BinaryRepresentation main.cpp binary_representation.cpp)

# Добавляем Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавляем тесты
add_executable(runTests test_binary_representation.cpp binary_representation.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Указываем, что нужно использовать функцию main из Google Test
target_link_libraries(runTests gtest_main)
