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
    src/Field/field_builder.cpp
    src/Field/field_builder.h
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
    entity
    ./src/Entity/entity.h
    ./src/Entity/Alive/alive.cpp
    ./src/Entity/Alive/alive.h
    ./src/Entity/Alive/Hero/hero.cpp
    ./src/Entity/Alive/Hero/hero.h
    ./src/Entity/Alive/Enemy/enemy.cpp
    ./src/Entity/Alive/Enemy/enemy.h
    ./src/Entity/Alive/Enemy/Goblin/goblin.cpp
    ./src/Entity/Alive/Enemy/Goblin/goblin.h
    ./src/Entity/Alive/Enemy/Slime/slime.cpp
    ./src/Entity/Alive/Enemy/Slime/slime.h
    ./src/Entity/Alive/Enemy/Troll/troll.cpp
    ./src/Entity/Alive/Enemy/Troll/troll.h
)

set (
    auxiliary
    
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
    ${entity}
)

target_link_libraries (OOP sfml-graphics sfml-window sfml-system)