#include "tile.h"

/* Constructors and Destructors */
Tile::Tile(unsigned short type) : type(type), entity(nullptr) 
{
    if (type >= NUMBER_OF_TYPES) 
        throw std::invalid_argument("Wrong Tile Type");
}

Tile::~Tile()
{
    if (this->entity) delete this->entity;
}

Tile &Tile::operator=(const Tile &other)
{
    this->type = other.type;
    // entity = new IEntity(other.entity);
    this->entity = other.entity;
}

/* Public Functions */
bool Tile::isEmpty() const
{
    return this->entity != nullptr;
}

bool Tile::isPassable() const
{
    return this->type != WALL;
}

unsigned short Tile::getType() const
{
    return this->type;
}

const IEntity& Tile::getEntity() const
{
    return *(this->entity);
}
