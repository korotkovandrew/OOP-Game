#ifndef HERO_H
#define HERO_H

#include "../alive.h"
#include "../../Item/item.h"
#include "../Enemy/enemy.h"

class Hero : public Alive
{
public:
    Hero(size_t hp = 100, size_t dmg = 10);
    void fight(Enemy &);
    void getHit(const Alive &);

    size_t getArmor() const;
    size_t getMaxHealth() const;
    bool isDead() const;

    void use(Item &);
private:
    size_t armor;
    size_t maxHealth;
    Observer obs;
};

#endif
