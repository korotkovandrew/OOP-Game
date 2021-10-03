#ifndef CELL_HPP
#define CELL_HPP

#include "entity.hpp"

class Cell
{
private:
    Entity *container;
    bool state;

public:
    Cell(Entity *ent = nullptr, bool state = true);
    ~Cell();

    void put(Entity *ent);

    void clear();
};

#endif