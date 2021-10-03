#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "../include/field.hpp"

class Game
{
private:
    sf::RenderWindow *window;

    Field *field;

public:
    Game();
    virtual ~Game();
    
    // Functions

    void run();
};

#endif