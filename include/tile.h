#ifndef TILE_H
#define TILE_H

#include "itile.h"

#include <SFML/Graphics.hpp>

class Tile : public ITile
{
public:
  Tile();
  Tile(sf::Sprite sprite, int type, bool passable);
  ~Tile();

  Tile(const Tile& other);
  Tile& operator=(const Tile& other);

  bool isPassable(); 
  bool isEmpty(); 

  sf::Sprite& getSprite();

private:
  sf::Sprite sprite;

  // NOT VOID but entity domen class
  void *entity;
  
  bool passable;
  int type;
};

#endif // !TILE_H
