#include "./Game/game.h"
#include "./Entity/Alive/Hero/hero.h"
#include "./Entity/Alive/Enemy/Slime/slime.h"

int main()
{
    Hero anton(20, 5);
    Slime bitch(20, 4);

    anton.fight(bitch);

    std::cout << anton.isDead() << bitch.isDead();


    // Game game;
    // game.run();
    return 0;
}