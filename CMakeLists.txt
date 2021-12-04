cmake_minimum_required(VERSION 3.0.0)
project(OOP VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib")

set (
    game
    source/Game/game.cpp
    source/Game/game.h
)

set (
    field
    source/Field/field.cpp
    source/Field/field.h
    source/Field/field_builder.cpp
    source/Field/field_builder.h
)
set (
    drawer
    ./source/Drawer/drawer.cpp
    ./source/Drawer/drawer.h
)

set (
    tile    
    ./source/Tile/tile.cpp
    ./source/Tile/tile.h
)

set (
    entity
    ./source/Entity/entity.h
)

set (
    alive
    ./source/Entity/Alive/alive.cpp
    ./source/Entity/Alive/alive.h
    ./source/Entity/Alive/Hero/hero.cpp
    ./source/Entity/Alive/Hero/hero.h
    ./source/Entity/Alive/Enemy/enemy.cpp
    ./source/Entity/Alive/Enemy/enemy.h
    ./source/Entity/Alive/Enemy/Goblin/goblin.cpp
    ./source/Entity/Alive/Enemy/Goblin/goblin.h
    ./source/Entity/Alive/Enemy/Slime/slime.cpp
    ./source/Entity/Alive/Enemy/Slime/slime.h
    ./source/Entity/Alive/Enemy/Troll/troll.cpp
    ./source/Entity/Alive/Enemy/Troll/troll.h
)

set (
    movers
    ./source/Movers/enemy_mover.cpp
    ./source/Movers/enemy_mover.h
    ./source/Movers/hero_mover.cpp
    ./source/Movers/hero_mover.h
)

set (
    item
    ./source/Entity/Item/item.cpp
    ./source/Entity/Item/item.h
)

set (
    auxiliary
    settings/config.h
)

add_executable(
    OOP 
    source/main.cpp
    ${game}
    ${field}
    ${drawer}
    ${tile}
    ${auxiliary}
    ${entity}
    ${alive}
    ${item}
    ${movers}
)

target_link_libraries (OOP sfml-graphics sfml-window sfml-system)