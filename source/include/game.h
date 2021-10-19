#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../settings/config.h"
#include "field.h"
#include "field_painter.h"
#include "sample.h"

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

    FieldPainter* fieldPainter;
    Field* field;
};

#endif // GAME_H