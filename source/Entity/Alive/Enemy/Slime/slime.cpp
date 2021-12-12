#include "./slime.h"

/* Constructors and Destructors */
Slime::Slime(size_t hp, size_t dmg)
: Enemy(hp, dmg) 
{
    obs.submit(this, ENEMY_CREATED);
}
