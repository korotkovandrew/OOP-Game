#include "adapter.h"

#include "../Tile/tile.h"
#include "../Entity/Item/item.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/Slime/slime.h"
#include "../Entity/Alive/Enemy/Goblin/goblin.h"
#include "../Entity/Alive/Enemy/Troll/troll.h"

void Adapter::convert(Hero* hero, LogSignal ev) 
{
    std::ostringstream osstr;
    osstr << "Hero (";
    osstr << "HP=" << std::to_string(hero->getHealth());
    osstr << " DMG=" << std::to_string(hero->getDamage());
    osstr << " ARMOR=" << std::to_string(hero->getArmor());
    osstr << ")";
    
    if (ev == HERO_GOT_HIT)
        osstr << " got hit by enemy in fight";
    else if (ev == HERO_CREATED)
        osstr << " was created";
    else if (ev == HERO_EXITED)
        osstr << " has left the field using exit";
    else if (ev == HERO_DEATH)
        osstr << " has died";
    else {
        std::cerr << ev << std::endl;
        throw std::runtime_error("Wrong signal passed in adapter Hero convert function");
    }

    redirectToPool(osstr.str());
}

void Adapter::convert(Enemy* enemy, LogSignal ev) 
{
    std::ostringstream osstr;
    Slime *slime = dynamic_cast<Slime *>(enemy); 
    Goblin *goblin = dynamic_cast<Goblin *>(enemy); 
    Troll *troll = dynamic_cast<Troll *>(enemy);
    if (slime) 
        osstr << "Slime";
    else if (goblin) 
        osstr << "Goblin";
    else if (troll) 
        osstr << "Troll";

    osstr << " (HP=" << std::to_string(enemy->getHealth());
    osstr << " DMG=" << std::to_string(enemy->getDamage()) << ") ";

    if (ev == ENEMY_GOT_HIT)
        osstr << "got hit by hero in fight";
    else if (ev == FIGHT_STARTS)
        osstr << "started to fight with hero";
    else if (ev == ENEMY_CREATED)
        osstr << "was created";
    else if (ev == ENEMY_DEATH)
        osstr << "was killed by hero";
    else {
        std::cerr << ev << std::endl;
        throw std::runtime_error("Wrong signal passed in adapter Enemy convert function");
    }

    redirectToPool(osstr.str());
}

void Adapter::convert(Item* item, LogSignal ev) 
{
    std::ostringstream osstr;
    ItemType itemType = item->getType();

    if (itemType == HEAL)
        osstr << "Healing";
    else if (itemType == DMG)
        osstr << "Damage up";
    else if (itemType == ARMOR)
        osstr << "Armor";
    
    osstr << " item ("; 
    osstr << std::to_string(item->getStat()); 
    osstr << ") ";

    if (ev == ITEM_CREATED) 
        osstr << "was created";
    else if (ev == ITEM_USED) 
        osstr << "was picked up by hero";
    else {
        std::cerr << ev << std::endl;
        throw std::runtime_error("Wrong signal passed in adapter Item convert function");
    }
    
    redirectToPool(osstr.str());
}

void Adapter::convert(Tile *tile, LogSignal ev) 
{
    std::ostringstream osstr;
    Entity *entity = tile->getEntity();
    Enemy *enemy = dynamic_cast<Enemy*>(entity);
    Hero *hero = dynamic_cast<Hero*>(entity);

    if (enemy && ev == ENEMY_MOVED)
    {
        Slime *slime = dynamic_cast<Slime *>(enemy); 
        Goblin *goblin = dynamic_cast<Goblin *>(enemy); 
        Troll *troll = dynamic_cast<Troll *>(enemy);
        if (slime) 
            osstr << "Slime";
        else if (goblin) 
            osstr << "Goblin";
        else if (troll) 
            osstr << "Troll";
        osstr << " (HP=" << enemy->getHealth();
        osstr << " DMG=" << enemy->getDamage();
        osstr << ") moves to tile (" << tile->getX() << ", " << tile->getY() << ")";
    }
    else if (hero && ev == HERO_MOVED)
    {
        Hero *hero = dynamic_cast<Hero*>(tile->getEntity());
        osstr << "Hero moves to tile (" << tile->getX() << ", " << tile->getY() << ")";
    }
    else if (ev == HERO_MOVEMENT_BLOCKED)
    {
        osstr << "Hero movement to tile (" << tile->getX() << ", " << tile->getY() << ") is blocked";
    }
    else {
        std::cerr << ev << std::endl;
        throw std::runtime_error("Wrong signal passed in adapter Tile convert function");
    }
    
    redirectToPool(osstr.str());
}

void Adapter::convert(Game* game, LogSignal ev) 
{
    std::ostringstream osstr;
    if (ev == GAME_OVER)
        osstr << "Game over";
    else if (ev == MISSION_COMPLETED)
        osstr << "Mission completed";
    else if (ev == GAME_INTERRUPTED)
        osstr << "Game was interrupted";
    else {
        std::cerr << ev << std::endl;
        throw std::runtime_error("Wrong signal passed in adapter Game convert function");
    }
    redirectToPool(osstr.str());
}


void Adapter::redirectToPool(std::string data) const
{
    LoggerPool *lp = LoggerPool::getInstance();
    lp->submitDataToLoggers(data);
}