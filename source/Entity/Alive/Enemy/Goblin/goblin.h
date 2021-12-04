#ifndef GOBLIN_H
#define GOBLIN_H

#include "../enemy.h"

class Goblin : public Enemy
{
public:
    Goblin(size_t hp = 40, size_t dmg = 10);
};

#endif 
