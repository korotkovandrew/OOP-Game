#ifndef FIELD_BUILDER_H
#define FIELD_BUILDER_H

#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "../../settings/config.h"
#include "field.h"
#include "../Entity/Alive/Hero/hero.h"
#include "../Entity/Alive/Enemy/Slime/slime.h"
#include "../Entity/Alive/Enemy/Goblin/goblin.h"
#include "../Entity/Alive/Enemy/Troll/troll.h"

enum Difficulty {EASY, NORMAL, HARD};

typedef struct
{
    unsigned short *content;
    size_t width;
    size_t height; 
} FieldSample;

class FieldBuilder
{
public:
    FieldBuilder();

    void loadSampleFromFile(std::string fileName);

    void setDifficulty(Difficulty);
    void spawnEnemies();
    void spawnItems();
    void spawnHero();

    Field *getResult();

private:
    std::vector<Tile*> getFreeTiles();

    bool loaded;
    Difficulty difficulty;
    Field *target;
};

#endif // FIELD_BUILDER_H
