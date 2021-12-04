#ifndef SLIME_H
#define SLIME_H

#include "../enemy.h"

class Slime : public Enemy
{
public:
    Slime(size_t hp = 20, size_t dmg = 5);
};

#endif // SLIME_H
