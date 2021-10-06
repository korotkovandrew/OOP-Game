#ifndef TILE_H
#define TILE_H

#include "itile.h"

#include <SFML/Graphics.hpp>

class Tile : public ITile
{
public:
  Tile();
  ~Tile();

  Tile(const Tile& other);
  Tile& operator=(const Tile& other);

  Tile(Tile&& other);
  Tile& operator=(Tile&& other);
  
  void init(sf::Sprite sprite, int type, bool passable) override;

  bool isPassable();

  sf::Sprite& getSprite();

private:
  sf::Sprite sprite;
  
  bool passable;
  int type;
};

#endif // !TILE_H
