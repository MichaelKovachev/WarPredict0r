#pragma once

#include "Player.h"

class Game
{
public:
	void Init(bool verbose, bool shouldGenerateShuffledDecks);
	void Run();

private:
	void SimulateRound();
	void GenerateShuffledRandomDecks();
	void PrintRoundInfo(const std::vector<Player::Card>& p1CardsAtRound, const std::vector<Player::Card>& p2CardsAtRound);
	void PrintRoundWinMessage();

private:
	bool isOver = false;

	bool verbose = false;
	bool shuffleRandomly = false;

	Player p1;
	Player p2;

	unsigned int winner = 0;
	unsigned long roundCount = 0;
};

