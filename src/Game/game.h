#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../../settings/config.h"
#include "../Field/field.h"
#include "../Field/field_builder.h"
#include "../Drawer/drawer.h"

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

    void updateEvents();
    void updateLogic();
    void render();

    sf::RenderWindow *window;
    sf::Event ev;

    Drawer *drawer;
    Field *field;
};

#endif // GAME_H