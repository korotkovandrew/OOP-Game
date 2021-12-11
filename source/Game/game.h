#ifndef GAME_H
#define GAME_H

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../Drawer/drawer.h"

#include "../../settings/config.h"

#include "../Field/field.h"
#include "../Field/field_builder.h"

#include "../Entity/Alive/Enemy/Goblin/goblin.h"
#include "../Entity/Alive/Enemy/Troll/troll.h"
#include "../Entity/Alive/Enemy/Slime/slime.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Item/item.h"

#include "../Movers/enemy_mover.h"
#include "../Movers/hero_mover.h"

#include "../Structures/log_signal.h"
#include "../LogSystem/observer.h"
#include "../LogSystem/logger_pool.h"
#include "../LogSystem/Loggers/console_logger.h"
#include "../LogSystem/Loggers/file_logger.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void initField();
    void initWindow();
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
    Direction dir;

    EnemyMover *eMover;
    HeroMover *hMover;
    Drawer *drawer;
    Field *field;
    Observer obs;
};

#endif // GAME_H
