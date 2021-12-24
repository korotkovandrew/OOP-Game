#include "hero.h"

/* Constructors and Destructors */
Hero::Hero(size_t hp, size_t max_hp, size_t dmg, size_t armor)
    : Alive(hp, dmg),
      maxHealth(max_hp),
      armor(armor) 
{
    obs.submit(this, HERO_CREATED);
}

/* Public Functions */
void Hero::getHit(const Alive &other)
{
    obs.submit(this, HERO_GOT_HIT);
    size_t dmg = other.getDamage();
    if (dmg <= armor) return;
    dmg -= armor;
    if (dmg >= health) {
        dead = true;
        health = 0;
        obs.submit(this, HERO_DEATH);
    }
    else 
        health -= dmg;
}

void Hero::fight(Enemy &enemy)
{
    obs.submit(&enemy, FIGHT_STARTS);
    while (true)
    {
        enemy.getHit(*this);
        if (enemy.isDead()) return;
        getHit(enemy);
        if (isDead()) { 
            obs.submit(this, HERO_DEATH); 
            return; 
        }
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


bool Hero::isDead()
{
    return dead;
}

void Hero::use(Item &item)
{
    ItemType type = item.getType();
    size_t value = item.getStat();
    if (type == HEAL) {
        if (value + health > maxHealth) {
            health = maxHealth;
        }
        else {
            health += value;
        }
    }
    else if (type == DMG)
        damage += value; 
    else if (type == ARMOR)
        armor += value;
    obs.submit(&item, ITEM_USED);
}