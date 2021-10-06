#include "../include/tile.h"
Tile::Tile() { }

Tile::~Tile() { }

Tile::Tile(const Tile& other)
: sprite(other.sprite),
  passable(other.passable),
  type(other.type) {}

Tile& Tile::operator=(const Tile& other)
{
  sprite   = other.sprite;
  passable = other.passable;
  type     = other.type;
  return *this;
}

void Tile::init(sf::Sprite sprite, int type, bool passable)
{
  this->sprite = sprite;
  this->passable = passable;
  this->type = type;
}

bool Tile::isPassable() { return passable; }

sf::Sprite& Tile::getSprite() { return sprite; }