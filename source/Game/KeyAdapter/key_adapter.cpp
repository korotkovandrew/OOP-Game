#include "key_adapter.h"

EventReaction KeyAdapter::processKeyCode(sf::Keyboard::Key keyCode)
{
    if (keyCode == sf::Keyboard::W || 
        keyCode == sf::Keyboard::S || 
        keyCode == sf::Keyboard::A || 
        keyCode == sf::Keyboard::D) 
    {
        if (keyCode == sf::Keyboard::W)
            return UP;
        else if (keyCode == sf::Keyboard::S)
            return DOWN;
        else if (keyCode == sf::Keyboard::A) 
            return LEFT;
        else if (keyCode == sf::Keyboard::D) 
            return RIGHT;
    }
    return STOP;
}