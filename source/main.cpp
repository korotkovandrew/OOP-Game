#include "./Game/game.h"
#include "./Game/game.cpp"

int main()
{
    Game<Rules<100, 100, 10, 4, // Hero stats
               3, 3, 2, // Enemies count
               20, 5, // Slime stats
               40, 10, // Goblin stats
               60, 15, // Troll stats
               2, 3, 3, // Items count
               50, 3, 4, // Items values
               true, // Is an exit necessary to win
               false // Are all the enemies must be beaten to win
               >> game;
    game.run();
    return 0;
}