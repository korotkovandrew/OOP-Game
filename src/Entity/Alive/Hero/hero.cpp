#include "hero.h"

Hero::Hero(unsigned int hp, unsigned int dmg)
    : Alive(hp, dmg)
{
}

void Hero::fight(Enemy &enemy)
{
    while (true)
    {
        this->getHit(enemy);
        if (this->isDead())
            return;
        enemy.getHit(*this);
        if (enemy.isDead())
            return;
    }
}
