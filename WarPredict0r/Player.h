#pragma once

#include <queue>
#include <vector>

class Player
{
public:
	enum class Card
	{
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		J = 11,
		Q = 12,
		K = 13,
		A = 14
	};

public:
	Player();

	// Returns true if the player had enough cards to draw the amount from
	bool DrawNext(std::vector<Card>& drawedCards, unsigned int amount = 1);
	void AppendToDeck(Card card);

private:
	std::queue<Card> deck;
};

