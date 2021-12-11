#include "alive.h"

Alive::Alive(size_t hp, size_t dmg)
:   health(hp),
    damage(dmg),
    dead(0) { }

/* Public Functions */
size_t Alive::getDamage() const
{
    return damage;
}

size_t Alive::getHealth() const
{
    return health;
}
