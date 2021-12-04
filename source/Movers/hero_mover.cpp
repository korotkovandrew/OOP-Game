#include "hero_mover.h"

HeroMover::HeroMover(Field *f) : field(f) {}

void HeroMover::move(Direction dir)
{
    size_t x = field->heroTile->getX();
    size_t y = field->heroTile->getY();
    size_t dx = 0;
    size_t dy = 0;
    Hero *hero = dynamic_cast<Hero *>(field->heroTile->getEntity());

    switch (dir)
    {
    case UP:    dy--; break;
    case DOWN:  dy++; break;
    case LEFT:  dx--; break;
    case RIGHT: dx++; break;
    }
    
    Tile *destination = &field->tiles[x + dx][y + dy];
    Entity *ent = destination->getEntity(); 
    Enemy *enemy = nullptr;
    Item *item = nullptr;

    if (!destination->isPassable())
    {
        // std::cout << "movement blocked from (" << x << ", " << y << ")" << " to (" << x + dx << ", " << y + dy << ")" << std::endl;
        return;
    }

    if (!ent)
    {
        destination->setEntity(field->heroTile->popEntity());
        field->heroTile = destination;
        return;
    }
    auto destEntityType = typeid(*ent).name();

    if (destEntityType == typeid(Item).name())
    {
        item = dynamic_cast<Item *>(ent);
        hero->use(*item);
        field->removeTile(field->itemTiles, destination);
    }
    else
    {
        enemy = dynamic_cast<Enemy *>(ent);
        hero->fight(*enemy);
        if (hero->isDead()) return;
        field->removeTile(field->enemyTiles, destination);
    }
    
    destination->setEntity(field->heroTile->popEntity());
    field->heroTile = destination;
}
