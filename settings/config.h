#define TILESET_PATH "../images/tileset.png"
#define HERO_PATH "../images/hero.png"
#define ENEMIES_PATH "../images/enemies.png"
#define ITEMS_PATH "../images/items.png"
#define SAMPLE_PATH "../settings/sample.txt"
#define WINDOW_NAME "Korotkov Andrew's Game"
#define FONT_PATH "../fonts/Mellizan.otf"

#define FONT_SIZE 30
#define BG_COLOR 0, 0, 0

#define TILE_SIZE 32

// DIFFICULTY SETTINGS
#define DIFFICULTY 1// < 3
 
#define SLIMES(difficulty)    (difficulty * 3)
#define GOBLINS(difficulty)   (difficulty * 2 + 1)
#define TROLLS(difficulty)    (difficulty + 1)

#define HEALS(difficulty)     (difficulty + 1)
#define DAMAGEUPS(difficulty) (difficulty + 2)
#define ARMORUPS(difficulty)  (difficulty + 2)

#define HERO_HP(difficulty)   (80 + difficulty * 20) 
#define HERO_DMG(difficulty)  (10 + difficulty * 3) 

#define HEAL_VALUE 50
#define DAMAGE_UP_VALUE 3
#define ARMOR_UP_VALUE 4
