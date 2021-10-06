#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "field.h"

class Game
{
public:
  Game();
  ~Game();

  void run();

private:
  void updateEvents();
  void updateLogic();
  void render();

  sf::RenderWindow* window;
  sf::Event event;

  Field *field;
};

#endif // !GAME_H
