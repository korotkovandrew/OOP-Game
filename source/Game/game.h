#ifndef GAME_H
#define GAME_H

#include <string>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../Drawer/drawer.h"

// SETTINGS
#include "Rules/rules.h"
#include "../../settings/config.h"

// FIELD
#include "../Field/field.h"
#include "../Field/field_builder.h"

// ENTITIES
#include "../Entity/Alive/Enemy/Goblin/goblin.h"
#include "../Entity/Alive/Enemy/Troll/troll.h"
#include "../Entity/Alive/Enemy/Slime/slime.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Item/item.h"

// MOVERS
#include "../Movers/enemy_mover.h"
#include "../Movers/hero_mover.h"

// LOGGER
#include "../Structures/log_signal.h"
#include "../LogSystem/observed.h"
#include "../LogSystem/logger_pool.h"
#include "../LogSystem/Loggers/console_logger.h"
#include "../LogSystem/Loggers/file_logger.h"

// CONTROL
#include "KeyAdapter/key_adapter.h"

template <class Rules>
class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void save();
    bool load();
    
    void initField();
    void initWindow();
    void initControl();
    void initDrawer();
    void initLogic();
    void initLogSystem();

    void updateEvents();
    void updateLogic();
    void render();

    void checkHero();
    bool isMissionCompleted();
    void displayWinMessage();

    sf::RenderWindow *window;
    sf::Event ev;
    
    bool movementMade;
    bool changed;
    bool missionCompleted;
    bool gameOver;
    EventReaction reaction;

    EnemyMover *eMover;
    HeroMover *hMover;
    Drawer *drawer;
    Field *field;
    KeyAdapter *keyAdapter;

    Rules rules;
};

#endif // GAME_H
