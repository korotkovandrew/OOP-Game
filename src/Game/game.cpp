#include "game.h"

/* Constructors and Destructors */
Game::Game()
{   
    initField();
    initWindow();
    initDrawer();
}

Game::~Game()
{
    delete field;
    delete drawer;
    delete window;
}

/* Public Functions */
void Game::run()
{
    while (window->isOpen())
    {
        this->updateEvents();
        this->updateLogic();
        this->render();
    }
}

/* Private Functions */

void Game::initField()
{
    FieldBuilder fbuilder;
    fbuilder.loadSampleFromFile(SAMPLE_PATH);
    fbuilder.build();
    
    field = fbuilder.getResult();
    std::cout << field->getWidth() << " " << field->getHeight() << std::endl;
}

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(field->getWidth() * TILE_SIZE,
                                                field->getHeight() * TILE_SIZE),
                                  WINDOW_NAME);
}

void Game::initDrawer()
{
    drawer = new Drawer(field);
    drawer->loadFromFile(TILESET_PATH, sf::Vector2u(TILE_SIZE, TILE_SIZE));
}


void Game::updateEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        if (ev.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateLogic()
{
}

void Game::render()
{
    this->window->clear(sf::Color(50, 50, 50));

    this->window->draw(*drawer);

    this->window->display();
}