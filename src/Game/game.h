#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../../settings/config.h"
#include "../Field/field.h"
#include "../Drawer/drawer.h"
#include "../Structs/sample.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void updateEvents();
    void updateLogic();
    void render();

    FieldSample* loadSamplesFromFile(std::string fileName, size_t& n);

    sf::RenderWindow* window;
    sf::Event ev;

    Drawer* drawer;
    Field* field;
};

#endif // GAME_H