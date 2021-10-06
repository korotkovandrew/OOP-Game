#ifndef ITILE_H
#define ITILE_H

#include <SFML/Graphics.hpp>

class ITile
{
public:
  void virtual init(sf::Sprite sprite, int type, bool passable) = 0;
  bool virtual isPassable() = 0;
};

#endif // !ITILE_H
