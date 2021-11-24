#ifndef FIELD_H
#define FIELD_H

#include <cstddef>

#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/enemy.h"
// #include "../Entity/Item/item.h"
#include "../Tile/tile.h"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Field
{
public:
    Field() = default;
    ~Field();

    Field(const Field &);
    Field& operator=(const Field &);
    Field(Field &&);
    Field& operator=(Field &&);

    // void move(size_t x, size_t y, Direction dir);
    void move(size_t x, size_t y, size_t dest_x, size_t dest_y);

    void remove(size_t x, size_t y);

    size_t getWidth() const;
    void setWidth(size_t);

    size_t getHeight() const;
    void setHeight(size_t);
    
    Tile **tiles;

private:
    size_t width;
    size_t height;
};

#endif // FIELD_H
