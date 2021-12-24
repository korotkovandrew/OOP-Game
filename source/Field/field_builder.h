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

#include "../Structures/field_sample.h"
#include "../Structures/rules_structures.h"

enum Difficulty {EASY, NORMAL, HARD};

class FieldBuilder
{
public:
    FieldBuilder(HeroStats heroStats,
                 EnemiesCount enemiesCount,
                 EnemyStats slimeStats,
                 EnemyStats goblinStats,
                 EnemyStats trollStats,
                 ItemsCount itemsCount,
                 ItemsValues itemsValues);

    void loadSampleFromFile(std::string fileName);

    void spawnEnemies();
    void spawnItems();
    void spawnHero();

    Field *getResult();

private:
    std::vector<Tile*> getFreeTiles();

    bool loaded;
    Field *target;

    HeroStats heroStats;
    EnemiesCount enemiesCount;
    EnemyStats slimeStats;
    EnemyStats goblinStats;
    EnemyStats trollStats;
    ItemsCount itemsCount;
    ItemsValues itemsValues;
};

#endif // FIELD_BUILDER_H
