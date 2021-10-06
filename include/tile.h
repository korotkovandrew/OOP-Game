#ifndef TILE_H
#define TILE_H

#include "itile.h"

#include <SFML/Graphics.hpp>

class Tile : public ITile
{
public:
  Tile();
  ~Tile();
  
  void init(sf::Sprite sprite, bool passable);

  bool isPassable();

  sf::Sprite& getSprite();

private:
  sf::Sprite sprite;
  
  bool passable;
  int type;
};

#endif // !TILE_H
