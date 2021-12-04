#include "game.h"

Game::Game()
{       
    initField();
    initWindow();
    initDrawer();
    initLogic();
}

Game::~Game()
{
    delete field;
    delete drawer;
    delete window;
    delete eMover;
    delete hMover;
}

void Game::run()
{
    while (window->isOpen())
    {
        updateEvents();
        updateLogic();
        render();
    }
}

void Game::initField()
{
    FieldBuilder fbuilder;
    fbuilder.loadSampleFromFile(SAMPLE_PATH);

    fbuilder.setDifficulty((Difficulty)DIFFICULTY);
    fbuilder.spawnEnemies();
    fbuilder.spawnItems();
    fbuilder.spawnHero();
    
    field = fbuilder.getResult();
}

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(field->getWidth() * TILE_SIZE,
                                                field->getHeight() * TILE_SIZE + FONT_SIZE),
                                  WINDOW_NAME,
                                  sf::Style::Close | sf::Style::Titlebar);
}

void Game::initDrawer()
{
    drawer = new Drawer(field, sf::Vector2u(TILE_SIZE, TILE_SIZE));
    drawer->loadTileset(TILESET_PATH);
    drawer->loadHero(HERO_PATH);
    drawer->loadEnemies(ENEMIES_PATH);
    drawer->loadItems(ITEMS_PATH);
    drawer->loadFont(FONT_PATH, FONT_SIZE);
}

void Game::initLogic()
{
    eMover = new EnemyMover(field);
    hMover = new HeroMover(field);
    dir = UP;
    movementMade = false;
    changed = false;
    gameOver = false;
}

void Game::updateEvents()
{
    while (window->pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
        if (!movementMade && ev.type == sf::Event::KeyPressed) {
            auto hTile = field->heroTile;
            size_t x = hTile->getX();
            size_t y = hTile->getY();
            if (ev.key.code == sf::Keyboard::W || ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::A || ev.key.code == sf::Keyboard::D) 
            {
                if (ev.key.code == sf::Keyboard::W)
                    dir = UP;
                else if (ev.key.code == sf::Keyboard::S)
                    dir = DOWN;
                else if (ev.key.code == sf::Keyboard::A) 
                    dir = LEFT;
                else if (ev.key.code == sf::Keyboard::D) 
                    dir = RIGHT;
                movementMade = true;
            }
        }
    }
}

void Game::updateLogic()
{
    if (movementMade) {
        hMover->move(dir);

        eMover->move();
        
        movementMade = false;
        changed = true;
    }

    if (changed) {
        checkHero(); 
        changed = false; 
    }
    if (gameOver) window->close();
}

void Game::render()
{
    window->clear(sf::Color(BG_COLOR));

    drawer->draw(*window);

    window->display();
}

void Game::checkHero()
{
    if (dynamic_cast<Hero*>(field->heroTile->getEntity())->isDead()) 
        gameOver = true;
    else if (field->heroTile->getType() == EXIT) { 
        // drawer->displayMessage();
        gameOver = true;
    }
}
