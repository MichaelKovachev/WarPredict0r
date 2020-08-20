#pragma once
#include <iostream>
#include <queue>
#include <vector>

class Player
{
public:
	enum class Card : unsigned char
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
		A = 14,
		Invalid = 0
	};

public:
	Player() = default;
	void Init();
	// Returns true if the player had enough cards to draw the amount from
	bool DrawNext(std::vector<Card>& drawedCards, unsigned int amount = 1);
	
	// Adds a card to the bottom of the deck
	void AppendToDeck(Card card);
	void PrintDeck();

private:
	void HandleInputToDeck();
	Card MatchStringToCard(const std::string& str) const;
	const std::string MatchCardToString(const Card card) const;
private:
	static constexpr unsigned int deckSize = 26;
	std::vector<Card> deck;
};
