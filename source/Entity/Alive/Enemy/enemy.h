#ifndef ENEMY_H
#define ENEMY_H

#include "../alive.h"

class Enemy : public Alive, public Observed
{
public:
    Enemy(size_t hp, size_t dmg);
    void getHit(const Alive &other);

    bool isDead();
};

#endif // ENEMY_H