#ifndef TILE_H
#define TILE_H

#include <stdexcept> 

#include "entity.h"

enum TileType {WALL, GROUND, ENTRANCE, EXIT, NUMBER_OF_TYPES};

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

private:
    Entity *entity;
    unsigned short type;
};

#endif // TILE_H