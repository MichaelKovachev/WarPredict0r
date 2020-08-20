#include "Game.h"

void Game::Init()
{
	p1.AppendToDeck(Player::Card::A);
}

void Game::Run()
{
	p1.PrintDeck();
}
