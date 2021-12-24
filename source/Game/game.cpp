#include "game.h"

template <class Rules>
Game<Rules>::Game()
{
    initControl();
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
void Game<Rules>::initControl()
{
    keyAdapter = new KeyAdapter();
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
    reaction = UP;
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
            reaction = keyAdapter->processKeyCode(ev.key.code);
            if (reaction != STOP) movementMade = true;
        }
    }
}

template <class Rules>
void Game<Rules>::updateLogic()
{
    if (movementMade) {
        hMover->move(reaction);
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
