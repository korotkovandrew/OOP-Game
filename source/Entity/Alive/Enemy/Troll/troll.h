#ifndef TROLL_H
#define TROLL_H

#include "../enemy.h"

class Troll : public Enemy
{
public:
    Troll(size_t hp = 60, size_t dmg = 15);
};

#endif // TROLL_H
