cmake_minimum_required(VERSION 3.20)
project(lab_1_clion)

set(CMAKE_CXX_STANDARD 20)

# Создаем исполняемый файл
add_executable(lab_1_clion main.cpp functions_1.cpp functions_2.cpp functions_3.cpp functions_4.cpp)

# Указываем путь к заголовочным файлам
target_include_directories(lab_1_clion PRIVATE ${CMAKE_SOURCE_DIR})

# Импортируем DLL как внешнюю библиотеку
add_library(InputCheck SHARED IMPORTED)

# Указываем пути к DLL и LIB
set_target_properties(InputCheck PROPERTIES
        IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/libinputCheck.dll"
        IMPORTED_IMPLIB "${CMAKE_BINARY_DIR}/libinputCheck.dll.a"
)

# Линкуем библиотеку
target_link_libraries(lab_1_clion PRIVATE InputCheck)