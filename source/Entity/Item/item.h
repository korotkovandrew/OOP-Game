#ifndef ITEM_H
#define ITEM_H

#include "../entity.h"

enum ItemType {HEAL, DMG, ARMOR};

class Item : public Entity
{
public:
    Item(ItemType type, size_t stat);

    ItemType getType() const;
    size_t getStat() const;
private:
    ItemType type;
    size_t stat;
};

#endif // ITEM_H
