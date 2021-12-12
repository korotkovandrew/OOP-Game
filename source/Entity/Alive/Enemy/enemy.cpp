#include "enemy.h"

/* Constructors and Destructors */
Enemy::Enemy(size_t hp, size_t dmg) : Alive(hp, dmg) {}

void Enemy::getHit(const Alive &other)
{
    obs.submit(this, ENEMY_GOT_HIT);
    if (other.getDamage() >= health) {
        dead = true;
        health = 0;
    }
    else 
        health -= other.getDamage();
}

bool Enemy::isDead()
{
    if (dead) obs.submit(this, ENEMY_DEATH);
    return dead;
}
