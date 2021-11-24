#ifndef ENEMY_H
#define ENEMY_H

#include "../alive.h"

class Enemy : public Alive
{
public:
    Enemy(unsigned int hp, unsigned int dmg);
};

#endif // ENEMY_H