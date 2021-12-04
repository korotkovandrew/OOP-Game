#ifndef ENEMY_MOVER_H
#define ENEMY_MOVER_H

#include "../Field/field.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/enemy.h"

class EnemyMover
{
public:
    EnemyMover(Field *);

    void move();
private:
    void getValidAdjTiles(Tile *, std::vector<Tile*> &);
    
    Field *field;
};

#endif // ENEMY_MOVER_H
