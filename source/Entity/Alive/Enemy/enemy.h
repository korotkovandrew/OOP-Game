#ifndef ENEMY_H
#define ENEMY_H

#include "../alive.h"

class Enemy : public Alive
{
public:
    Enemy(size_t hp, size_t dmg);
};

#endif // ENEMY_H