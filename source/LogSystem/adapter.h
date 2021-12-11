#ifndef ADAPTER_H
#define ADAPTER_H

#include <typeinfo>
#include <sstream>

#include "logger_pool.h"
#include "../Structures/log_signal.h"

class Hero; class Enemy; class Item; class Tile; class Game;

class Adapter
{
public:
    void convert(const Hero* hero, LogSignal ev) const;
    void convert(const Enemy* enemy, LogSignal ev) const;
    void convert(const Item* item, LogSignal ev) const;
    void convert(const Tile* tile, LogSignal ev) const;
    void convert(const Game* game, LogSignal ev) const;

    void redirectToPool(std::string data) const;
};

#endif // ADAPTER_H
