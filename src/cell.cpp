#include "../include/cell.hpp"
#include "../include/entity.hpp"

Cell::Cell(Entity *entity, bool state) 
    : container(entity), state(state)
{

}

Cell::~Cell()
{
    
}

void Cell::put(Entity *ent) { container = ent; }

void Cell::clear() { container = nullptr; }

