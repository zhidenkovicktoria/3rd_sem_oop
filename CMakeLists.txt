cmake_minimum_required(VERSION 3.10)

# Название проекта
project(LabProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исходные файлы
set(SOURCES
    solution.cpp
    main.cpp
)

set(TEST_SOURCES
    test.cpp
    solution.cpp
)

# Добавляем заголовочные файлы
set(HEADERS
    solution.h
)

# Создаем исполняемый файл для основной программы
add_executable(lab6 ${SOURCES})

# Подключаем Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Создаем исполняемый файл для тестов
add_executable(RunTests ${TEST_SOURCES})

# Линковка с Google Test и pthread
target_link_libraries(RunTests GTest::GTest GTest::Main pthread)

# Установки для тестирования
enable_testing()
add_test(NAME RunTests COMMAND RunTests)
