#include "item.h"

Item::Item(ItemType type = HEAL, size_t stat = 10)
    : stat(stat),
      type(type) {}

ItemType Item::getType() const
{
    return type;
}

size_t Item::getStat() const
{
    return stat;
}
