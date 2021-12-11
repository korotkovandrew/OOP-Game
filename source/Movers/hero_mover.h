#ifndef HERO_MOVEDR_H
#define HERO_MOVEDR_H

#include "../Structures/log_signal.h"

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
    Observer obs;
};

#endif // HERO_MOVEDR_H
