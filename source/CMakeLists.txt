cmake_minimum_required(VERSION 3.0.0)
project(SFMLtest VERSION 0.1.0)

set (
  src
  ./src/main.cpp
  ./src/game.cpp
  ./src/tile.cpp
  ./src/field.cpp
  ./include/game.h
  ./include/tile.h
  ./include/itile.h
  ./include/field.h
)

add_executable(SFMLtest ${src})
target_link_libraries(SFMLtest sfml-graphics sfml-system sfml-window)
