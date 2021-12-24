#ifndef RULES_H
#define RULES_H

#include "../../Structures/rules_structures.h"

template<class Rules> class Game;
class FieldBuilder;

template <size_t HERO_HEALTH, size_t HERO_MAX_HEALTH, size_t HERO_DAMAGE, size_t HERO_ARMOR,
          size_t SLIME_COUNT, size_t GOBLIN_COUNT, size_t TROLL_COUNT, 
          size_t SLIME_HEALTH, size_t SLIME_DAMAGE, 
          size_t GOBLIN_HEALTH, size_t GOBLIN_DAMAGE, 
          size_t TROLL_HEALTH, size_t TROLL_DAMAGE, 
          size_t HEALING_COUNT, size_t DAMAGE_UP_COUNT, size_t ARMOR_UP_COUNT,
          size_t HEALING_VALUE, size_t DAMAGE_UP_VALUE, size_t ARMOR_UP_VALUE,
          bool NECESSARY_EXIT,
          bool ALL_ENEMIES_MUST_BE_BEATEN>
class Rules
{
    friend class Game<Rules>;
private:
    HeroStats heroStats = {HERO_HEALTH, HERO_MAX_HEALTH, HERO_DAMAGE, HERO_ARMOR};
    EnemiesCount enemiesCount = {SLIME_COUNT, GOBLIN_COUNT, TROLL_COUNT};
    EnemyStats slimeStats = {SLIME_HEALTH, SLIME_DAMAGE};
    EnemyStats goblinStats = {GOBLIN_HEALTH, GOBLIN_DAMAGE};
    EnemyStats trollStats = {TROLL_HEALTH, TROLL_DAMAGE};
    ItemsCount itemsCount = {HEALING_COUNT, DAMAGE_UP_COUNT, ARMOR_UP_COUNT};
    ItemsValues itemsStats = {HEALING_VALUE, DAMAGE_UP_VALUE, ARMOR_UP_VALUE};
    WinConditions winConditions = {NECESSARY_EXIT, ALL_ENEMIES_MUST_BE_BEATEN};
};

#endif // RULES_H
