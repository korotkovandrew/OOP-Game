#ifndef LOG_EVENT_H
#define LOG_EVENT_H

enum LogSignal { 
    HERO_CREATED, 
    HERO_MOVED,
    HERO_MOVEMENT_BLOCKED, 
    HERO_GOT_HIT,
    HERO_DEATH, 
    HERO_EXITED, 
    ENEMY_CREATED,
    ENEMY_GOT_HIT,
    ENEMY_MOVED, 
    ENEMY_DEATH, 
    ITEM_CREATED,
    ITEM_USED,
    FIGHT_STARTS,
    MISSION_COMPLETED,
    GAME_OVER,
    GAME_INTERRUPTED
};

#endif // LOG_EVENT_H
