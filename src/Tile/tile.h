#ifndef TILE_H
#define TILE_H

#include <stdexcept>

#include "../Interfaces/entity.h"
#include "tile_type_enum.h"

class Tile
{
public:
    Tile() = default;
    Tile(unsigned short type);
    ~Tile();

    Tile& operator=(const Tile&);
    
    bool isEmpty() const;
    bool isPassable() const;

    unsigned short getType() const;
    const Entity& getEntity() const;

private:
    Entity *entity;
    unsigned short type;
};

#endif // TILE_H