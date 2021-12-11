#ifndef RULES_H
#define RULES_H

typedef struct { size_t health, maxHealth, damage, armor; } HeroStats;
typedef struct { size_t health, damage; } EnemyStats;
typedef struct { size_t light, normal, hard; } EnemiesCount;
typedef struct { size_t heal, damageUp, armorUp; } ItemsStats;

template <HeroStats HS, 
          EnemyStats ES_LIGHT, 
          EnemyStats ES_NORMAL, 
          EnemyStats ES_HARD, 
          ItemsStats IS>
class Rules
{
private:
    /* data */ye 
public:
    Rules(/* args */);
    ~Rules();
};

#endif // RULES_H
