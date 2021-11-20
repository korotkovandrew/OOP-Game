#include "field_builder.h"

/* Constructors and Destructors */

FieldBuilder::FieldBuilder()
    : target(new Field()),
      samples(nullptr),
      samplesLength(0),
      difficulty(0) {}

FieldBuilder::~FieldBuilder() 
{
    reset();
}

/* Public Functions */

void FieldBuilder::loadSampleFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Read FieldSample File");

    file >> samplesLength;
    samples = new FieldSample[samplesLength];
    for (size_t i = 0; i < samplesLength; i++) {
        file >> samples[i].width >> samples[i].height;
        samples[i].content = new unsigned short[samples[i].width * samples[i].height];
        for (size_t j = 0; j < samples[i].width * samples[i].height; j++) {
            file >> samples[i].content[j];
        }
    }
    loaded = true;
    file.close();
}

void FieldBuilder::setDifficulty(Difficulty diff)
{
    difficulty = diff;
}

void FieldBuilder::spawnEntities(std::vector<Entity*> &entities)
{
    if (!loaded)
        throw std::runtime_error("Field samples was not loaded");

    std::vector<Tile*> freeTiles = getFreeTiles();
    
    if (freeTiles.size() < entities.size())
        throw std::runtime_error("Not enough tiles to place all the entities");

    for (auto entity: entities) {
        srand(time(NULL));
        size_t k = rand() % freeTiles.size();
        freeTiles[k]->setEntity(entity);
        freeTiles.erase(freeTiles.begin() + k);
    }
}

void FieldBuilder::spawnHero(Hero* hero)
{
    if (!loaded)
        throw std::runtime_error("Field samples was not loaded");

    bool found = false;
    for (size_t x = 0; x < target->getWidth(); x++) {
        for (size_t y = 0; y < target->getHeight(); y++) {
            if (target->tiles[x][y].getType() == ENTRANCE) {
                target->tiles[x][y].setEntity(hero);
                found = true;
                break;
            }
        }
        if (found) break;
    }
}

void FieldBuilder::build()
{
    if (!loaded)
        throw std::runtime_error("Field samples was not loaded");

    srand(time(NULL));
    size_t sampleNumber = rand() % samplesLength;

    size_t w = samples[sampleNumber].width;
    size_t h = samples[sampleNumber].height;

    target->setWidth(w);
    target->setHeight(h);
    target->tiles = new Tile *[w];
    for (size_t x = 0; x < w; x++) {
        target->tiles[x] = new Tile[h];
        for (size_t y = 0; y < h; y++) {
            target->tiles[x][y] = Tile((TileType)samples[sampleNumber].content[x + y * w]);
        }
    }
}

Field *FieldBuilder::getResult()
{
    Field *result = target;
    reset();
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
            if (target->tiles[x][y].isEmpty() &&
                target->tiles[x][y].isPassable() &&
                target->tiles[x][y].getType() != ENTRANCE)
            {
                result.push_back(&target->tiles[x][y]);
            }
        }
        
    }
    return result;
}

void FieldBuilder::reset()
{
    if (samples) {
        for (size_t i = 0; i < samplesLength; i++)
            delete[] samples[i].content;
        delete[] samples;
    }
    samples = nullptr;
    target = nullptr;
}
