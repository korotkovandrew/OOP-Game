#include "game.h"

template <class Rules>
Game<Rules>::Game()
{
    initLogSystem();
    initField();
    initWindow();
    initDrawer();
    initLogic();
}

template <class Rules>
Game<Rules>::~Game()
{
    delete field;
    delete drawer;
    delete window;
    delete eMover;
    delete hMover;
}

template <class Rules>
void Game<Rules>::run()
{
    while (window->isOpen())
    {
        updateEvents();
        updateLogic();
        render();
    }
}

template <class Rules>
void Game<Rules>::initField()
{
    FieldBuilder fbuilder(rules.heroStats,
                          rules.enemiesCount,
                          rules.slimeStats,
                          rules.goblinStats,
                          rules.trollStats,
                          rules.itemsCount,
                          rules.itemsStats);
    fbuilder.loadSampleFromFile(SAMPLE_PATH);

    fbuilder.spawnEnemies();
    fbuilder.spawnItems();
    fbuilder.spawnHero();
    
    field = fbuilder.getResult();
}

template <class Rules>
void Game<Rules>::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(field->getWidth() * TILE_SIZE,
                                                field->getHeight() * TILE_SIZE + FONT_SIZE),
                                  WINDOW_NAME,
                                  sf::Style::Close | sf::Style::Titlebar);
}

template <class Rules>
void Game<Rules>::initDrawer()
{
    drawer = new Drawer(field, sf::Vector2u(TILE_SIZE, TILE_SIZE));
    drawer->loadTileset(TILESET_PATH);
    drawer->loadHero(HERO_PATH);
    drawer->loadEnemies(ENEMIES_PATH);
    drawer->loadItems(ITEMS_PATH);
    drawer->loadFont(FONT_PATH, FONT_SIZE);
}

template <class Rules>
void Game<Rules>::initLogic()
{
    eMover = new EnemyMover(field);
    hMover = new HeroMover(field);
    dir = UP;
    movementMade = false;
    missionCompleted = false;
    changed = false;
    gameOver = false;
}

template <class Rules>
void Game<Rules>::initLogSystem()
{
    LoggerPool *loggerPool = LoggerPool::getInstance();
    loggerPool->pushLogger(new ConsoleLogger());
    loggerPool->pushLogger(new FileLogger());
}

template <class Rules>
void Game<Rules>::updateEvents()
{
    while (window->pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();             
            }
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

template <class Rules>
void Game<Rules>::updateLogic()
{
    if (movementMade) {
        hMover->move(dir);

        eMover->move();
        
        movementMade = false;
        changed = true;
    }

    if (!missionCompleted) missionCompleted = isMissionCompleted();

    if (changed) checkHero(); 
    if (gameOver) window->close();
}

template <class Rules>
void Game<Rules>::render()
{
    window->clear(sf::Color(BG_COLOR));
    drawer->draw(*window);
    window->display();
}

template <class Rules>
void Game<Rules>::checkHero()
{
    Hero *hero = dynamic_cast<Hero*>(field->heroTile->getEntity());
    if (hero->isDead()) {
        gameOver = true;
    }
    else if (rules.winConditions.necessaryExit)
        if (missionCompleted &&
            field->heroTile->getType() == EXIT) { 
        gameOver = true;
    }
    changed = false; 
}

template <class Rules>
bool Game<Rules>::isMissionCompleted()
{
    if (rules.winConditions.allEnemiesMustBeBeaten) {
        missionCompleted = field->enemyTiles.empty();
    }
    else {
        missionCompleted = field->enemyTiles.size()/2;
    }

    return missionCompleted;
}
