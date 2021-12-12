#ifndef ADAPTER_H
#define ADAPTER_H

#include <typeinfo>
#include <sstream>
#include <map>

#include "logger_pool.h"
#include "../Structures/log_signal.h"

class Hero; class Enemy; class Item; class Tile; class Game;

class Adapter
{
public:
    void convert(Hero* hero, LogSignal ev);
    void convert(Enemy* enemy, LogSignal ev);
    void convert(Item* item, LogSignal ev);
    void convert(Tile* tile, LogSignal ev);
    void convert(Game* game, LogSignal ev);

    void redirectToPool(std::string data) const;
};

#endif // ADAPTER_H
