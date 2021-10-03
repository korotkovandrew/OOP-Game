#include "../include/field.hpp"
#include "../include/cell.hpp"

Field::Field(size_t h, size_t w) : height(h), width(w)
{
    cells = new Cell* [height];
    for (int i = 0; i < height; i++) {
        cells[i] = new Cell[width];
    }
}

Field::~Field() 
{
    for (int i = 0; i < height; i++) {
        delete [] cells[i];
    }
    delete [] cells;
}