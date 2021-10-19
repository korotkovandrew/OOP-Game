#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstddef>

#include "tile.h"

class Field
{
public:
    Field(const unsigned short* sample, size_t width, size_t height);
    ~Field();

    Field(const Field &);
    Field& operator=(const Field &);
    Field(Field &&);
    Field& operator=(Field &&);

    size_t getWidth() const;
    size_t getHeight() const;
    const Tile& getTile(size_t x, size_t y) const;

private:
    Tile **tiles;

    size_t width;
    size_t height;
};

#endif // FIELD_H
