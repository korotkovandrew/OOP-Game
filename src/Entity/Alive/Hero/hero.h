#ifndef HERO_H
#define HERO_H

#include "../alive.h"
#include "../Enemy/enemy.h"

class Hero : public Alive
{
public:
    Hero(unsigned int hp, unsigned int dmg);
    void fight(Enemy &);
};

#endif // HERO_H
