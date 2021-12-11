#include "enemy_mover.h"

EnemyMover::EnemyMover(Field *f) : field(f) {}

void EnemyMover::move()
{
    for (int i = 0; i < field->enemyTiles.size(); i++) {
        Enemy *enemy = dynamic_cast<Enemy*>(field->enemyTiles[i]->getEntity());
        std::vector<Tile *> freeTiles;
        getValidAdjTiles(field->enemyTiles[i], freeTiles);
        if (!freeTiles.empty()) {
            Tile *tileToGo = freeTiles[rand() % freeTiles.size()];
            Hero *hero = dynamic_cast<Hero*>(tileToGo->getEntity());
            if (hero) {
                hero->fight(*enemy);
                obs.submit(tileToGo, ENEMY_MOVED); 
            } else {
                tileToGo->setEntity(enemy);
                field->enemyTiles[i] = tileToGo;
                obs.submit(tileToGo, ENEMY_MOVED); 
            }
        }
    }
    
    auto it = std::remove_if(field->enemyTiles.begin(), 
                             field->enemyTiles.end(), 
                             [](Tile *enemyTile){ return dynamic_cast<Alive*>(enemyTile->getEntity())->isDead(); });
    field->enemyTiles.erase(it, field->enemyTiles.end());
}

void EnemyMover::getValidAdjTiles(Tile *tile, std::vector<Tile *> &res)
{
    std::vector<Tile *> tiles;
    size_t x = tile->getX();
    size_t y = tile->getY();
    tiles.push_back(&field->tiles[x + 1][y]);
    tiles.push_back(&field->tiles[x - 1][y]);
    tiles.push_back(&field->tiles[x][y - 1]);
    tiles.push_back(&field->tiles[x][y + 1]);


    for (auto t: tiles) {
        Hero *hero = dynamic_cast<Hero*>(t->getEntity());
        if ((t->getType() == GROUND && !t->getEntity()) || hero) {
            res.push_back(t);
        }
    }
}
