#pragma once

#include "Player.h"

class Game
{
public:
	void Init(bool shouldGenerateShuffledDecks);
	void Run();

private:
	void SimulateRound();
	void GenerateShuffledRandomDecks();
	void PrintRoundInfo(const std::vector<Player::Card>& p1CardsAtRound, const std::vector<Player::Card>& p2CardsAtRound);

private:
	bool isOver = false;
	//bool shouldCreateRandomDecks = true;

	Player p1;
	Player p2;

	unsigned int winner = 0;
};

