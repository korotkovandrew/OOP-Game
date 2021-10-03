#include "../include/config.hpp"

#include "../include/game.hpp"
#include "../include/field.hpp"

Game::Game() 
{
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_INIT_SIZE), WINDOW_NAME);

    field = new Field(FIELD_HEIGHT, FIELD_WIDTH);
}

Game::~Game()
{
    delete this->window;
    delete this->field;
}

void Game::run()
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

	    window->clear(sf::Color(0,0,100,0));
        window->display();
    }
}