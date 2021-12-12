#ifndef HERO_MOVEDR_H
#define HERO_MOVEDR_H

#include "../Structures/log_signal.h"
#include "../LogSystem/observed.h"

#include "../Field/field.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/enemy.h"

class HeroMover : public Observed
{
public:
    HeroMover(Field *);
    void move(Direction);
private:
    Field *field;
};

#endif // HERO_MOVEDR_H
