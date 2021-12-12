#ifndef ITEM_H
#define ITEM_H

#include "../entity.h"
#include "../../LogSystem/observer.h"
#include "../../Structures/item_type.h"

class Item : public Entity, public Observed
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
