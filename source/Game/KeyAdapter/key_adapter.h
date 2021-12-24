#ifndef KEY_ADAPTER_H
#define KEY_ADAPTER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../../Structures/event_reaction.h"

class KeyAdapter
{
public:   
    EventReaction processKeyCode(sf::Keyboard::Key keyCode);
};

#endif // KEY_ADAPTER_H
