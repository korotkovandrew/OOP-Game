#ifndef SLIME_H
#define SLIME_H

#include "../enemy.h"

class Slime : public Enemy
{
public:
    Slime(size_t hp, size_t dmg);
};

#endif // SLIME_H
