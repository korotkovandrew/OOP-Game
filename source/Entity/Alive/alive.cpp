#include "alive.h"

Alive::Alive(size_t hp, size_t dmg)
:   health(hp),
    damage(dmg),
    dead(0) { }

/* Public Functions */
void Alive::getHit(const Alive &other)
{
    if (other.getDamage() >= health) {
        dead = true;
        health = 0;
    }
    else 
        health -= other.getDamage();
}

size_t Alive::getDamage() const
{
    return damage;
}

size_t Alive::getHealth() const
{
    return health;
}

bool Alive::isDead() const
{
    return dead;
}
