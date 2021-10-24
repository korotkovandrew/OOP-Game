#include "game.h"

/* Constructors and Destructors */
Game::Game()
{
    sf::Vector2u tileSize(TILE_SIZE, TILE_SIZE);
    sf::Texture tileset;
    size_t samples_size;
    FieldSample *samples = loadSamplesFromFile(SAMPLE_PATH, samples_size);

    srand(time(NULL));
    size_t sampleNumber = rand() % samples_size;

    field = new Field(samples[sampleNumber].content,
                      samples[sampleNumber].width,
                      samples[sampleNumber].height);

    drawer = new Drawer(field);
    drawer->loadFromFile(TILESET_PATH, tileSize);

    window = new sf::RenderWindow(sf::VideoMode(samples[sampleNumber].width * tileSize.x,
                                                samples[sampleNumber].height * tileSize.y),
                                  WINDOW_NAME);

    for (size_t i = 0; i < samples_size; i++)
        delete[] samples[i].content;
    delete[] samples;
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
FieldSample *Game::loadSamplesFromFile(std::string fileName, size_t &n)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Read FieldSample File");

    file >> n;
    FieldSample *samples = new FieldSample[n];
    for (size_t i = 0; i < n; i++)
    {
        file >> samples[i].width >> samples[i].height;
        samples[i].content = new unsigned short[samples[i].width * samples[i].height];
        for (size_t j = 0; j < samples[i].width * samples[i].height; j++)
        {
            file >> samples[i].content[j];
        }
    }

    file.close();
    return samples;
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