cmake_minimum_required(VERSION 3.0.0)
project(OOP-Game VERSION 0.1.0)

find_package(Catch2 2 REQUIRED)

# Файлы исходного кода
set (
    sources
    ./src/main.cpp
    ./src/game.cpp
    ./src/field.cpp
    ./src/cell.cpp
    ./src/entity.cpp
)

# Заголовочные файлы
set (
    headers
    ./include/game.hpp
    ./include/config.hpp
    ./include/field.hpp
    ./include/cell.hpp
    ./include/entity.hpp
)

# Графические билиотеки
set (
    g_libs 
    sfml-graphics 
    sfml-window 
    sfml-system
)

# Основной исполняемый файл
add_executable(
    Game 
    ${sources}
    ${headers}
)
target_link_libraries(Game ${g_libs})


# Файлы исходного кода unit-тестирования
set (
    test_sources
    ./tests/test.cpp
)

# Исполняемый файл unit-тестирования
add_executable(
    tests 
    ${test_sources}
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

