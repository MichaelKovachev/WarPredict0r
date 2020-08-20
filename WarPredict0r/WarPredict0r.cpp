#include "Game.h"

int main()
{
    bool shouldGenerateShuffledDecks = true;
    Game game;
    game.Init(shouldGenerateShuffledDecks);
    game.Run();
}

