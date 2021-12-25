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
void Game<Rules>::save(const char *filename)
{
    std::ofstream fout;
    fout.open(filename, std::ofstream::trunc);
    if (!fout.is_open()) 
        throw std::runtime_error("Could not open the file to save the game");

    fout.write((char*)&rules.slimeStats, sizeof(EnemyStats));
    fout.write((char*)&rules.goblinStats, sizeof(EnemyStats));
    fout.write((char*)&rules.trollStats, sizeof(EnemyStats));
    fout.write((char*)&rules.itemsValues, sizeof(ItemsValues));
    fout.write((char*)&rules.winConditions, sizeof(WinConditions));

    size_t fieldWidth = field->getWidth();
    size_t fieldHeight = field->getHeight();
    
    fout.write((char*)&fieldWidth, sizeof(size_t));
    fout.write((char*)&fieldHeight, sizeof(size_t));

    for (size_t x = 0; x < fieldWidth; x++) {
        for (size_t y = 0; y < fieldHeight; y++) {
            TileType tileType = field->tiles[x][y].getType();
            fout.write((char*)&tileType, sizeof(TileType));
        }
    }

    Tile *heroTile = field->heroTile;
    Hero *hero = dynamic_cast<Hero*>(heroTile->getEntity());
    size_t heroX = field->heroTile->getX();
    size_t heroY = field->heroTile->getY();
    size_t heroHealth = hero->getHealth();
    size_t heroMaxHealth = hero->getMaxHealth();
    size_t heroDamage = hero->getDamage();
    size_t heroArmor = hero->getArmor();
    fout.write((char*)&heroX, sizeof(size_t));
    fout.write((char*)&heroY, sizeof(size_t));
    fout.write((char*)&heroHealth, sizeof(size_t));
    fout.write((char*)&heroMaxHealth, sizeof(size_t));
    fout.write((char*)&heroDamage, sizeof(size_t));
    fout.write((char*)&heroArmor, sizeof(size_t));

    size_t enemiesCount = field->enemyTiles.size();
    fout.write((char*)&enemiesCount, sizeof(size_t));
    for (auto enemyTile: field->enemyTiles) {
        Entity *entity = enemyTile->getEntity();

        Enemy *enemy = dynamic_cast<Enemy*>(entity);
        Slime *slime = dynamic_cast<Slime*>(entity);
        Goblin *goblin = dynamic_cast<Goblin*>(entity);
        Troll *troll = dynamic_cast<Troll*>(entity);

        size_t enemyX = enemyTile->getX();
        size_t enemyY = enemyTile->getY();
        fout.write((char*)&enemyX, sizeof(size_t));
        fout.write((char*)&enemyY, sizeof(size_t));

        size_t enemyType;
        if (slime) enemyType = 0;
        else if (goblin) enemyType = 1;
        else if (troll) enemyType = 2;
        fout.write((char*)&enemyType, sizeof(size_t));
    }

    size_t itemsCount = field->itemTiles.size();
    fout.write((char*)&itemsCount, sizeof(size_t));
    for (auto itemTile: field->itemTiles) {
        Item *item = dynamic_cast<Item*>(itemTile->getEntity());
    
        size_t itemX = itemTile->getX();
        size_t itemY = itemTile->getY();
        fout.write((char*)&itemX, sizeof(size_t));
        fout.write((char*)&itemY, sizeof(size_t));

        ItemType itemType = item->getType();
        fout.write((char*)&itemType, sizeof(ItemType));
    }

    fout.close();
}

template <class Rules>
bool Game<Rules>::load(const char *filename)
{
    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open())
        throw std::runtime_error("Could not open the file to load the game");

    if (!fin.read((char*)&rules.slimeStats, sizeof(EnemyStats))) return false;
    if (!fin.read((char*)&rules.goblinStats, sizeof(EnemyStats))) return false;
    if (!fin.read((char*)&rules.trollStats, sizeof(EnemyStats))) return false;
    if (!fin.read((char*)&rules.itemsValues, sizeof(ItemsValues))) return false;
    if (!fin.read((char*)&rules.winConditions, sizeof(WinConditions))) return false;

    Field *newField = new Field();
    size_t fieldWidth;
    size_t fieldHeight;
    if (!fin.read((char*)&fieldWidth, sizeof(size_t))) return false;
    if (!fin.read((char*)&fieldHeight, sizeof(size_t))) return false;

    newField->setHeight(fieldHeight);
    newField->setWidth(fieldWidth);
    newField->tiles = new Tile *[fieldWidth];
    for (size_t x = 0; x < fieldWidth; x++) {
        newField->tiles[x] = new Tile [fieldHeight];
        for (size_t y = 0; y < fieldHeight; y++) {
            TileType tileType;
            if (!fin.read((char*)&tileType, sizeof(TileType))) return false;
            if (tileType > EXIT || tileType < WALL) return false;
            newField->tiles[x][y] = Tile(tileType, x, y);
        }
    }

    size_t heroX;
    size_t heroY;
    size_t heroHealth, heroMaxHealth, heroDamage, heroArmor;
    if (!fin.read((char*)&heroX, sizeof(size_t))) return false;
    if (!fin.read((char*)&heroY, sizeof(size_t))) return false;
    if (!fin.read((char*)&heroHealth, sizeof(size_t))) return false;
    if (!fin.read((char*)&heroMaxHealth, sizeof(size_t))) return false;
    if (!fin.read((char*)&heroDamage, sizeof(size_t))) return false;
    if (!fin.read((char*)&heroArmor, sizeof(size_t))) return false;

    Hero *newHero = new Hero(heroHealth, heroMaxHealth, heroDamage, heroArmor);
    newField->heroTile = &newField->tiles[heroX][heroY];
    newField->tiles[heroX][heroY].setEntity(newHero);

    size_t enemiesCount;
    if (!fin.read((char*)&enemiesCount, sizeof(size_t))) return false;
    
    for (size_t i = 0; i < enemiesCount; i++) {
        size_t enemyX;
        size_t enemyY;
        if (!fin.read((char*)&enemyX, sizeof(size_t))) return false;
        if (!fin.read((char*)&enemyY, sizeof(size_t))) return false;

        size_t enemyType;
        if (!fin.read((char*)&enemyType, sizeof(size_t))) return false;

        Enemy *enemy;
        if (enemyType == 0)
            enemy = new Slime(rules.slimeStats.health, rules.slimeStats.damage);
        else if (enemyType == 1)
            enemy = new Goblin(rules.goblinStats.health, rules.goblinStats.damage);
        else if (enemyType == 2)
            enemy = new Troll(rules.trollStats.health, rules.trollStats.damage);
        else 
            return false;

        newField->tiles[enemyX][enemyY].setEntity(enemy);
        newField->enemyTiles.push_back(&newField->tiles[enemyX][enemyY]);
    }

    size_t itemsCount;
    if (!fin.read((char*)&itemsCount, sizeof(size_t))) return false;

    for (size_t i = 0; i < itemsCount; i++) {
        size_t itemX;
        size_t itemY;
        if (!fin.read((char*)&itemX, sizeof(size_t))) return false;
        if (!fin.read((char*)&itemY, sizeof(size_t))) return false;

        ItemType itemType;
        if (!fin.read((char*)&itemType, sizeof(ItemType))) return false;

        size_t stat;
        if (itemType == HEAL)
            stat = rules.itemsValues.heal;
        else if (itemType == DMG)
            stat = rules.itemsValues.damageUp;
        else if (itemType == ARMOR)
            stat = rules.itemsValues.armorUp;
        else 
            return false;

        newField->tiles[itemX][itemY].setEntity(new Item(itemType, stat));
        newField->itemTiles.push_back(&newField->tiles[itemX][itemY]);
    }

    if (fin.read(nullptr, sizeof(nullptr))) return false;
    fin.close();

    delete field;
    delete drawer;
    delete eMover;
    delete hMover;

    field = newField;
    delete window;
    window = new sf::RenderWindow(sf::VideoMode(field->getWidth() * TILE_SIZE,
                                                field->getHeight() * TILE_SIZE + FONT_SIZE),
                                  WINDOW_NAME,
                                  sf::Style::Close | sf::Style::Titlebar);

    drawer = new Drawer(field, sf::Vector2u(TILE_SIZE, TILE_SIZE));
    drawer->loadTileset(TILESET_PATH);
    drawer->loadHero(HERO_PATH);
    drawer->loadEnemies(ENEMIES_PATH);
    drawer->loadItems(ITEMS_PATH);
    drawer->loadFont(FONT_PATH, FONT_SIZE);

    eMover = new EnemyMover(field);
    hMover = new HeroMover(field);

    return true;
}

template <class Rules>
void Game<Rules>::initControl()
{
    keyAdapter = new KeyAdapter();
    keyAdapter->setControlKeyBinding(sf::Keyboard::Up,
                                     sf::Keyboard::Down,
                                     sf::Keyboard::Left,
                                     sf::Keyboard::Right,
                                     sf::Keyboard::Num1,
                                     sf::Keyboard::Num2);
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
                          rules.itemsValues);
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
            if (reaction == SAVE) {
                save("../saves/save.txt");
            }
            else if (reaction == LOAD) {
                if (!load("../saves/save.txt"))
                    std::cerr << "Loading Failed. Save file is broken";
            }
            else if (reaction != STOP) {
                movementMade = true;
            }
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
