#include "enemy_mover.h"

EnemyMover::EnemyMover(Field *f) : field(f) {}

void EnemyMover::move()
{
    for (int i = 0; i < field->enemyTiles.size(); i++) {
        std::vector<Tile *> freeTiles;
        getValidAdjTiles(field->enemyTiles[i], freeTiles);
        Tile *tileToGo = freeTiles[rand() % freeTiles.size()];
        if (tileToGo == field->heroTile) {
            Hero *hero = dynamic_cast<Hero*>(tileToGo->getEntity());
            Enemy *enemy = dynamic_cast<Enemy*>(field->enemyTiles[i]->getEntity());
            
            hero->fight(*enemy);
            
            if (hero->isDead()) return;
        } else {
            tileToGo->setEntity(field->enemyTiles[i]->popEntity());
            field->enemyTiles[i] = tileToGo;
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

    for (auto tile: tiles) {
        if (tile->getType() == GROUND && 
           (!tile->getEntity() || typeid(*tile->getEntity()).name() == typeid(Hero).name())) {
            res.push_back(tile);
        }
    }
}
