#ifndef FIELD_H
#define FIELD_H

#include <cstddef>

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
