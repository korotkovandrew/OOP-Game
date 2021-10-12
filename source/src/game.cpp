#include "../include/game.h"

const int FIELD_TEMPLATE[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 2, 0, 1, 1, 1, 1, 1, 1, 0,
                              0, 1, 0, 1, 1, 1, 1, 0, 1, 0,
                              0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
                              0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
                              0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
                              0, 1, 0, 1, 1, 1, 1, 0, 1, 0,
                              0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
                              0, 1, 1, 1, 0, 1, 1, 1, 3, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 10;
const int TILE_SIZE = 32; // px
const char *TILESET = "../images/tiles.png";

// Constructor & Destructors
Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(FIELD_WIDTH*TILE_SIZE, FIELD_HEIGHT*TILE_SIZE), 
                                "The Game", 
                                sf::Style::Titlebar | sf::Style::Close);
  field = new Field(TILESET, 
                    FIELD_TEMPLATE,
                    TILE_SIZE,
                    FIELD_WIDTH, 
                    FIELD_HEIGHT);

  std::cout << field->getTile(1, 0).isPassable() << std::endl;
  std::cout << field->getTile(0, 0).isPassable() << std::endl;
  std::cout << field->getTile(0, 1).isPassable() << std::endl;
  std::cout << field->getTile(1, 1).isPassable() << std::endl;
  // window->setSize(sf::Vector2u(3u * FIELD_WIDTH * TILE_SIZE, 
                              //  3u * FIELD_HEIGHT * TILE_SIZE));
}

Game::~Game()
{ 
  delete window;
  delete field;
}

// Public Functions

void Game::run()

{
  while (window->isOpen())
  {
    updateEvents();
    updateLogic();
    render();
  }
}

// Private Functions

void Game::updateEvents()
{
  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
    }
  }
}

void Game::updateLogic()
{

}

void Game::render()
{
  window->clear();

  window->draw(*field);

  window->display();
}

