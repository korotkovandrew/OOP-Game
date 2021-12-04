#ifndef ALIVE_H
#define ALIVE_H

#include "../entity.h"

class Alive : public Entity
{
public:
    Alive(size_t hp, size_t dmg);

    virtual void getHit(const Alive &);

    size_t getHealth() const;
    size_t getDamage() const;
    
    bool isDead() const;

protected:
    size_t health;
    size_t damage;
    bool dead;
};

#endif // ALIVE_H
