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
	bool Init();
	// Returns true if the player had enough cards to draw the amount from
	bool DrawNext(std::vector<Card>& drawedCards, unsigned int amount = 1);
	
	// Adds a card to the bottom of the deck
	void AppendToDeck(Card card);
	void AppendToDeck(const std::vector<Card>& cards);

	// Use a custom deck
	void UseDeck(const std::vector<Card>& deck);

	void PrintDeck();

	unsigned int GetDeckIndex() const { return deckIndex; }

private:
	bool HandleInputToDeck();
	Card MatchStringToCard(const std::string& str) const;

public:
	static const std::string MatchCardToString(const Card card);

private:
	static constexpr unsigned int initialDeckSize = 26;
	std::vector<Card> deck;

	unsigned int deckIndex = 0;
};