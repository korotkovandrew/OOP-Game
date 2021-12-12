#ifndef ENEMY_MOVEDR_H
#define ENEMY_MOVEDR_H

#include "../LogSystem/observed.h"

#include "../Structures/log_signal.h"

#include "../Field/field.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/enemy.h"

class EnemyMover : public Observed
{
public:
    EnemyMover(Field *);

    void move();
private:
    void getValidAdjTiles(Tile *, std::vector<Tile*> &);
    
    Field *field;
};

#endif // ENEMY_MOVEDR_H
