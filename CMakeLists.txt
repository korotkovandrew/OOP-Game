cmake_minimum_required(VERSION 3.0.0)
project(OOP VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -IC:/SFML/include -LC:/SFML/lib")

set (
    src
    ./src/main.cpp
    ./src/game.cpp
    ./src/field.cpp
    ./src/field_painter.cpp
    ./src/tile.cpp
)

set (
    headers
    ./include/game.h
    ./include/field.h
    ./include/tile.h
    ./include/entity.h
    ./include/field_painter.h
    ./settings/config.h
)

add_executable(OOP ${src} ${headers})

target_link_libraries (OOP sfml-graphics sfml-window sfml-system)