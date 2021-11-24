#ifndef TILE_H
#define TILE_H

#include <stdexcept>

#include "../Entity/entity.h"

enum TileType
{
    WALL,
    GROUND,
    ENTRANCE,
    EXIT
};

class Tile
{
public:
    Tile() = default;
    Tile(TileType type);
    ~Tile();

    Tile &operator=(const Tile &);

    bool isEmpty() const;
    bool isPassable() const;

    TileType getType() const;
    
    Entity *getEntity() const;
    void setEntity(Entity *entity);  

private:
    Entity *entity;
    TileType type;
};

#endif // TILE_H