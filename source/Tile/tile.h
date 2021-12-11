#ifndef TILE_H
#define TILE_H

#include <stdexcept>

#include "../Entity/entity.h"
#include "../Structures/tile_type.h"

class Tile
{
public:
    Tile() = default;
    Tile(TileType type, size_t x, size_t y);
    ~Tile();

    Tile &operator=(const Tile &);

    TileType getType() const;
    bool isPassable() const;
    void clear();

    Entity *popEntity();
    Entity *getEntity() const;
    void setEntity(Entity *);
    
    size_t getX() const;
    size_t getY() const;

private:
    size_t x;
    size_t y;
    Entity *entity;
    TileType type;
};

#endif // TILE_H
