#include "field_builder.h"

/* Constructors and Destructors */
FieldBuilder::FieldBuilder()
    : target(new Field()),
      difficulty(NORMAL),
      loaded(false) {}

/* Public Functions */
void FieldBuilder::loadSampleFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Read FieldSample File");

    FieldSample *samples;
    size_t samplesLength;
    
    file >> samplesLength;
    samples = new FieldSample[samplesLength];
    for (size_t i = 0; i < samplesLength; i++) {
        file >> samples[i].width >> samples[i].height;
        samples[i].content = new unsigned short[samples[i].width * samples[i].height];
        for (size_t j = 0; j < samples[i].width * samples[i].height; j++) {
            file >> samples[i].content[j];
        }
    }
    file.close();

    srand(time(NULL));
    size_t n = rand() % samplesLength;
    size_t w = samples[n].width;
    size_t h = samples[n].height;

    target->setWidth(w);
    target->setHeight(h);
    target->tiles = new Tile *[w];
    for (size_t x = 0; x < w; x++) {
        target->tiles[x] = new Tile[h];
        for (size_t y = 0; y < h; y++) {
            target->tiles[x][y] = Tile((TileType)samples[n].content[x + y * w], x, y);
        }
    }

    loaded = true;
}

void FieldBuilder::setDifficulty(Difficulty dif)
{
    difficulty = dif;
}

void FieldBuilder::spawnEnemies()
{
    if (!loaded) 
        throw std::runtime_error("Tilemap must be loaded before spawning enemies");

    std::vector<Tile*> tiles = getFreeTiles();
    size_t easyEnemies   = SLIMES(difficulty);
    size_t normalEnemies = GOBLINS(difficulty);
    size_t hardEnemies   = TROLLS(difficulty);

    if (easyEnemies + normalEnemies + hardEnemies > tiles.size())
        throw std::runtime_error("Not enough space to spawn enemies");

    std::vector<Enemy *> enemies;
    for (size_t i = 0; i < easyEnemies; i++)
        enemies.push_back(new Slime);
    for (size_t i = 0; i < normalEnemies; i++)
        enemies.push_back(new Goblin);
    for (size_t i = 0; i < hardEnemies; i++)
        enemies.push_back(new Troll);


    srand(time(0));
    for (auto enemy: enemies) {
        size_t tile = rand() % tiles.size();
        tiles[tile]->setEntity(enemy);
        target->enemyTiles.push_back(tiles[tile]);
        tiles.erase(tiles.begin() + tile);
    }
}

void FieldBuilder::spawnItems()
{
    if (!loaded) 
        throw std::runtime_error("Tilemap must be loaded before spawning items");

    std::vector<Tile*> tiles = getFreeTiles();
    size_t healings  = HEALS(difficulty);
    size_t damageUps = DAMAGEUPS(difficulty);
    size_t armorUps  = ARMORUPS(difficulty);
    
    if (healings + damageUps + armorUps > tiles.size())
        throw std::runtime_error("Not enough space to spawn items");

    std::vector<Item *> items;
    
    for (size_t i = 0; i < healings; i++)
        items.push_back(new Item(HEAL, HEAL_VALUE));
    for (size_t i = 0; i < damageUps; i++)
        items.push_back(new Item(DMG, DAMAGE_UP_VALUE));
    for (size_t i = 0; i < armorUps; i++)
        items.push_back(new Item(ARMOR, ARMOR_UP_VALUE));


    srand(time(0));
    for (auto item: items) {
        size_t tile = rand() % tiles.size();
        tiles[tile]->setEntity(item);
        target->itemTiles.push_back(tiles[tile]);
        tiles.erase(tiles.begin() + tile);
    }
}

void FieldBuilder::spawnHero()
{
    if (!loaded) 
        throw std::runtime_error("Tilemap must be loaded before spawning a hero");

    Hero *hero = new Hero(HERO_HP(difficulty), HERO_DMG(difficulty));

    for (size_t x = 0; x < target->getWidth(); x++) {
        for (size_t y = 0; y < target->getHeight(); y++) {
            if (target->tiles[x][y].getType() == ENTRANCE) {
                target->tiles[x][y].setEntity(hero);
                target->heroTile = &target->tiles[x][y];
            }
        }      
    }
}

Field *FieldBuilder::getResult()
{
    Field *result = target;
    target = nullptr;
    return result;
}

/* Private Functions */
std::vector<Tile*> FieldBuilder::getFreeTiles()
{
    std::vector<Tile*> result; 
    size_t w = target->getWidth();
    size_t h = target->getHeight();
    for (size_t x = 0; x < w; x++) {
        for (size_t y = 0; y < h; y++) {
            if (!target->tiles[x][y].getEntity() &&
                target->tiles[x][y].isPassable() &&
                target->tiles[x][y].getType() == GROUND) {
                result.push_back(&target->tiles[x][y]);
            }
        }
    }
    return result;
}
