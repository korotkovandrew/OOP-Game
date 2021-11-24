#include "alive.h"

Alive::Alive(unsigned int hp, unsigned int dmg)
:   health(hp),
    damage(dmg),
    dead(0) { }

void Alive::getHit(const Alive &other)
{
    if (other.getDamage() > health) 
        dead = true;
    else 
        health -= other.getDamage();
}

unsigned int Alive::getDamage() const
{
    return damage;
}

bool Alive::isDead() const
{
    return dead;
}