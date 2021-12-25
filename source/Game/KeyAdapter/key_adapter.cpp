#include "key_adapter.h"

KeyAdapter::KeyAdapter()
    : moveUp(sf::Keyboard::W),
      moveDown(sf::Keyboard::S),
      moveLeft(sf::Keyboard::A),
      moveRight(sf::Keyboard::D) {}

EventReaction KeyAdapter::processKeyCode(sf::Keyboard::Key keyCode)
{
    if (keyCode == moveUp)
        return UP;
    else if (keyCode == moveDown)
        return DOWN;
    else if (keyCode == moveLeft)
        return LEFT;
    else if (keyCode == moveRight)
        return RIGHT;
    else if (keyCode == save)
        return SAVE;
    else if (keyCode == load)
        return LOAD;
    else return STOP;
}

void KeyAdapter::setControlKeyBinding(sf::Keyboard::Key moveUpKey,
                                      sf::Keyboard::Key moveDownKey,
                                      sf::Keyboard::Key moveLeftKey,
                                      sf::Keyboard::Key moveRightKey,
                                      sf::Keyboard::Key saveKey,
                                      sf::Keyboard::Key loadKey)
{
    moveUp    = moveUpKey;
    moveDown  = moveDownKey;
    moveLeft  = moveLeftKey;
    moveRight = moveRightKey;
    save      = saveKey;
    load      = loadKey;
}
