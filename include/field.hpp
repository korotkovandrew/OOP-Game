#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>

#include "cell.hpp"

class Field
{
private:
    Cell **cells;

    size_t height;
    size_t width;

public:
    Field(size_t h, size_t w);
    virtual ~Field();
};

#endif