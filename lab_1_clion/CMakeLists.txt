cmake_minimum_required(VERSION 3.10)  # Более совместимая версия CMake
project(lab_1_clion)                  # Имя проекта

set(CMAKE_CXX_STANDARD 17)            # Используем C++17 для совместимости
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исходные файлы
add_executable(lab_1_clion
        main.cpp
        Header.h
        functions_1.cpp
        functions_2.cpp
        Header_2.h
        functions_3.cpp
        Header_3.h
)

# Указываем директорию с заголовочными файлами
target_include_directories(lab_1_clion PRIVATE ${CMAKE_SOURCE_DIR})