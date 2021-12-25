#ifndef FIELD_H
#define FIELD_H

#include <cstddef>
#include <vector>
#include <algorithm>

#include "../Structures/event_reaction.h"
#include "../Tile/tile.h"

class Field
{
public:
    Field() = default;
    ~Field();

    Field(const Field &);
    Field& operator=(const Field &);
    Field(Field &&);
    Field& operator=(Field &&);

    void removeTile(std::vector<Tile *>&, Tile *);

    size_t getWidth() const;
    void setWidth(size_t);

    size_t getHeight() const;
    void setHeight(size_t);

    Tile **tiles;
    std::vector<Tile *> enemyTiles;
    std::vector<Tile *> itemTiles;
    Tile *heroTile;

private:
    size_t width;
    size_t height;
};

#endif // FIELD_H
