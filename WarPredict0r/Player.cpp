#include "Player.h"

Player::Player()
{
	
}

bool Player::DrawNext(std::vector<Card>& drawedCards, unsigned int amount)
{
	if (deck.size() >= amount) return false;

	if (amount <= 3 && amount >= 1)
	{
		for (unsigned int i = 1; i <= amount; ++i)
		{
			drawedCards.emplace_back(deck.front());
			deck.pop();
		}
	}
	return true;
}

void Player::AppendToDeck(Card card)
{
	deck.push(card);
}
