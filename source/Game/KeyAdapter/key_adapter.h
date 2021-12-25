#ifndef KEY_ADAPTER_H
#define KEY_ADAPTER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../../Structures/event_reaction.h"

class KeyAdapter
{
public:
    KeyAdapter();
    EventReaction processKeyCode(sf::Keyboard::Key keyCode);
    void setControlKeyBinding(sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key);
    sf::Keyboard::Key moveLeft;
    sf::Keyboard::Key moveRight;
    sf::Keyboard::Key moveUp;
    sf::Keyboard::Key moveDown;
};

#endif // KEY_ADAPTER_H
