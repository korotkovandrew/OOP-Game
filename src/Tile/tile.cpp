#include "tile.h"

/* Constructors and Destructors */
Tile::Tile(TileType type) : type(type), entity(nullptr) { }

Tile::~Tile()
{
    if (entity) delete entity;
}

Tile &Tile::operator=(const Tile &other)
{
    type = other.type;
    //? entity = new IEntity(other.entity);
    entity = other.entity;
}

/* Public Functions */
bool Tile::isEmpty() const
{
    return entity != nullptr;
}

bool Tile::isPassable() const
{
    return type != WALL;
}

TileType Tile::getType() const
{
    return type;
}

Entity *Tile::getEntity() const
{
    return entity;
}

void Tile::setEntity(Entity *entity)
{
    this->entity = entity;
}