#include "tile.h"

/* Constructors and Destructors */
Tile::Tile(TileType type, size_t x, size_t y)
    : type(type),
      entity(nullptr),
      x(x),
      y(y) {}

Tile::~Tile()
{
    if (entity)
        delete entity;
}

Tile &Tile::operator=(const Tile &other)
{
    type = other.type;
    x = other.x;
    y = other.y;
    //? entity = new IEntity(other.entity);
    entity = other.entity;
}

/* Public Functions */
bool Tile::isPassable() const
{
    return type != WALL;
}

size_t Tile::getX() const
{
    return x;
}

size_t Tile::getY() const
{
    return y;
}

TileType Tile::getType() const
{
    return type;
}

Entity *Tile::getEntity() const
{
    return entity;
}

Entity *Tile::popEntity()
{
    Entity *e = entity;
    entity = nullptr;
    return e;
}

void Tile::setEntity(Entity *e)
{
    if (entity) delete entity;
    entity = e;
}
