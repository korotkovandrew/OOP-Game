#ifndef GOBLIN_H
#define GOBLIN_H

#include "../enemy.h"

class Goblin : public Enemy
{
public:
    Goblin(size_t hp, size_t dmg);
};

#endif 
