#include "game.hpp"

// Main program entry
int main()
{
    Game game;
    game.Start();
    while (1)
    {
        /* code */
        game.Update();
    }
    
	return 0;
}
