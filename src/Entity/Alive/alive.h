#ifndef ALIVE_H
#define ALIVE_H

#include "../entity.h"

class Alive : public Entity
{
public:
    Alive(unsigned int hp, unsigned int dmg);
    ~Alive();

    bool isDead() const;
    unsigned int getDamage() const;
    void getHit(const Alive &);

private:
    unsigned int health;
    unsigned int damage;
    bool dead;
};

#endif // ALIVE_H
