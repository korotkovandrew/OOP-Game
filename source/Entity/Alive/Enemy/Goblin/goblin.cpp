#include "./goblin.h"

/* Constructors and Destructors */
Goblin::Goblin(size_t hp, size_t dmg)
: Enemy(hp, dmg) 
{
    obs.submit(this, ENEMY_CREATED);
}
