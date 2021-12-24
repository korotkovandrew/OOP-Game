#ifndef RULES_STRUCTURES
#define RULES_STRUCTURES

typedef struct { size_t health, maxHealth, damage, armor; } HeroStats;
typedef struct { size_t health, damage; } EnemyStats;
typedef struct { size_t light, normal, hard; } EnemiesCount;
typedef struct { size_t heal, damageUp, armorUp; } ItemsValues;
typedef struct { size_t heal, damageUp, armorUp; } ItemsCount;
typedef struct { bool necessaryExit, allEnemiesMustBeBeaten; } WinConditions;

#endif // RULES_STRUCTURES
