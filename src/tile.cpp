#include "../include/tile.h"

Tile::Tile()
{
  // ??? 
}
Tile::~Tile()
{
  // ???
}

void Tile::init(sf::Sprite sprite, bool passable)
{
  this->sprite = sprite;
  this->passable = passable;
}

bool Tile::isPassable() { return passable; }

sf::Sprite& Tile::getSprite() { return sprite; }