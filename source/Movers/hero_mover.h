#ifndef HERO_MOVER_H
#define HERO_MOVER_H

#include "../Field/field.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/enemy.h"

class HeroMover
{
public:
    HeroMover(Field *);

    void move(Direction);
private:
    Field *field;
};

#endif // HERO_MOVER_H
