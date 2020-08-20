#include "Game.h"

void Game::Init()
{
	std::cout << "Enter the first player's deck with each card separated by a space. Hit ENTER when you are done:" << std::endl;
	p1.Init();

	std::cout << "Enter the second player's deck with each card separated by a space. Hit ENTER when you are done:" << std::endl;
	p2.Init();
}

void Game::Run()
{
	p1.PrintDeck();
	p2.PrintDeck();
}
