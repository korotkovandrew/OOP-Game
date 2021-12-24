#ifndef TROLL_H
#define TROLL_H

#include "../enemy.h"

class Troll : public Enemy
{
public:
    Troll(size_t hp, size_t dmg);
};

#endif // TROLL_H
