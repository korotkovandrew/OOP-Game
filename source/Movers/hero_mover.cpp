#include "hero_mover.h"

HeroMover::HeroMover(Field *f) : field(f) {}

void HeroMover::move(Direction dir)
{
    
    size_t x = field->heroTile->getX(), dx = 0;
    size_t y = field->heroTile->getY(), dy = 0;
    Hero *hero = dynamic_cast<Hero *>(field->heroTile->getEntity());

    if      (dir == UP)    dy--;
    else if (dir == DOWN)  dy++;
    else if (dir == LEFT)  dx--;
    else if (dir == RIGHT) dx++;
    
    Tile *destination = &field->tiles[x + dx][y + dy];
    Entity *ent = destination->getEntity();
    Enemy *enemy = dynamic_cast<Enemy *>(ent);
    Item *item = dynamic_cast<Item *>(ent);

    if (!destination->isPassable()) { 
        obs.submit(destination, HERO_MOVEMENT_BLOCKED);
        return;
    };

    if (!ent) {
        destination->setEntity(field->heroTile->popEntity());
        field->heroTile = destination;
        obs.submit(destination, HERO_MOVED);
        return;
    }

    if (item) {
        hero->use(*item);
        field->removeTile(field->itemTiles, destination);
    }
    else if (enemy) {
        hero->fight(*enemy);
        if (hero->isDead()) return;
        field->removeTile(field->enemyTiles, destination);
    }
    
    destination->setEntity(field->heroTile->popEntity());
    field->heroTile = destination;
    obs.submit(destination, HERO_MOVED);
}
