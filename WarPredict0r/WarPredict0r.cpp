#include "Game.h"
#include <string>
#include <iostream>

void HandleProgramModeArguments(bool& verbose, bool& randomShuffle);

int main(int argc, char* argv[])
{
    bool isVerbose = false, shouldGenerateShuffledDecks = false;
  
    HandleProgramModeArguments(isVerbose, shouldGenerateShuffledDecks);

    Game game;
    game.Init(isVerbose, shouldGenerateShuffledDecks);
    game.Run();
}

void HandleProgramModeArguments(bool& verbose, bool& randomShuffle)
{
    verbose = false;
    randomShuffle = false;

    std::cout << "Type in \"random shuffle\" to use randomly generated decks and then press ENTER.\nPress ENTER directly for manual entering of decks." << std::endl;
   
    std::string input;
    std::getline(std::cin, input);
    if (input == "random shuffle") randomShuffle = true;
    input.clear();

    std::cout << "Type in \"verbose\" to run the program in verbose mode and then press ENTER.\nPress ENTER directly for silent mode." << std::endl;
    std::getline(std::cin, input);
    if (input == "verbose") verbose = true;
    
    if (!verbose && !randomShuffle)
        std::cout << "Running program in default config - silent and manual entering" << std::endl;
}