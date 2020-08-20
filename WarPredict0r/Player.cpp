#include "Player.h"
#include <iostream>

Player::Player()
{
	
}

bool Player::DrawNext(std::vector<Card>& drawedCards, unsigned int amount)
{
	if (amount <= 3 && amount >= 1)
	{
		// if the player doesn't have enough cards, he loses
		if (deck.size() >= amount) return false;

		for (unsigned int i = 1; i <= amount; ++i)
		{
			drawedCards.emplace_back(deck.front());
			deck.erase(deck.begin());
		}
	}
	return true;
}

void Player::AppendToDeck(Card card)
{
	deck.insert(deck.begin(), card);
}

void Player::PrintDeck()
{
	for (const Card& card : deck)
	{
		std::cout << static_cast<int>(card) << " ";
	}
	std::cout << std::endl;
}
