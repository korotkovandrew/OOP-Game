cmake_minimum_required(VERSION 3.0.0)
project(OOP-Game VERSION 0.1.0)

find_package(Catch2 2 REQUIRED)

# Файлы исходного кода
set (
    sources
    ./src/main.cpp
)

# Файлы исходного кода unit-тестирования
set (
    test_sources
    ./tests/test.cpp
)

# Заголовочные файлы
set (
    headers
    ./include/config.hpp
)

# Графические билиотеки
set (
    libraries 
    sfml-graphics 
    sfml-window 
    sfml-system
)

# Основной исполняемый файл
add_executable(
    OOP-Game 
    ${sources}
    ${headers}
)
target_link_libraries(OOP-Game ${libraries})

# Исполняемый файл unit-тестирования
add_executable(
    tests 
    ${test_sources}
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

