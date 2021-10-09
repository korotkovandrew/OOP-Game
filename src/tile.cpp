#include "../include/tile.h"

// Constructors & Destructor

Tile::Tile() {}

Tile::Tile(sf::Sprite sprite, int type, bool passable)
: entity(nullptr),
  sprite(sprite),
  passable(passable),
  type(type) {}

Tile::~Tile() {}

Tile::Tile(const Tile& other)
: entity(nullptr),
  sprite(other.sprite),
  passable(other.passable),
  type(other.type) {}

Tile& Tile::operator=(const Tile& other)
{
  sprite   = other.sprite;
  passable = other.passable;
  type     = other.type;
  return *this;
}

// Public Functions

bool Tile::isPassable() { return passable; }

bool Tile::isEmpty() { return entity != nullptr; }

sf::Sprite& Tile::getSprite() { return sprite; }