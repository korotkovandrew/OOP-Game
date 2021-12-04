#include "hero.h"

/* Constructors and Destructors */
Hero::Hero(size_t hp, size_t dmg)
    : Alive(hp, dmg),
      maxHealth(hp),
      armor(0) {}

/* Public Functions */
void Hero::getHit(const Alive &other)
{
    size_t dmg = other.getDamage();
    if (dmg <= armor) return;
    dmg -= armor;
    if (dmg >= health) {
        dead = true;
        health = 0;
    }
    else 
        health -= dmg;
}

void Hero::fight(Enemy &enemy)
{
    while (true)
    {
        enemy.getHit(*this);
        if (enemy.isDead()) return;
        getHit(enemy);
        if (isDead()) return;
    }
}

size_t Hero::getArmor() const
{
    return armor;
}

size_t Hero::getMaxHealth() const
{
    return maxHealth;
}

void Hero::use(Item &item)
{
    ItemType type = item.getType();
    size_t value = item.getStat();
    switch (type)
    {
        case HEAL:
            if (value + health > maxHealth) 
                health = maxHealth;
            else
                health += value;
            break;
        case DMG:
            damage += value; 
            break;
        case ARMOR:
            armor += value; 
            break;
    }
}