cmake_minimum_required(VERSION 3.0.0)
project(OOP VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib")

set (
    game
    src/Game/game.cpp
    src/Game/game.h
)

set (
    field
    src/Field/field.cpp
    src/Field/field.h
)
set (
    drawer
    ./src/Drawer/drawer.cpp
    ./src/Drawer/drawer.h
)

set (
    tile    
    ./src/Tile/tile.cpp
    ./src/Tile/tile.h
)

set (
    auxiliary
    
    src/Interfaces/i_entity.h
    src/Structs/sample.h
    settings/config.h
)

add_executable(
    OOP 
    src/main.cpp
    ${game}
    ${field}
    ${drawer}
    ${tile}
    ${auxiliary}
)

target_link_libraries (OOP sfml-graphics sfml-window sfml-system)