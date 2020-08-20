#include "Player.h"

#include <iostream>
#include <string>


void Player::Init()
{
	deck.reserve(deckSize);
	HandleInputToDeck();
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
		std::cout << MatchCardToString(card) << " ";
	}
	std::cout << std::endl;
}

void Player::HandleInputToDeck()
{
	std::string inputDeckStr;
	std::getline(std::cin, inputDeckStr);
	std::remove_if(inputDeckStr.begin(), inputDeckStr.end(), std::isspace);
	
	for (unsigned int iterationCount = 0, index = 0; iterationCount < deckSize; )    // index is the index in the string
	{
		// We need to handle the case where the card number is 10 separately
		if (inputDeckStr[index] == '1' 
			&& (index + 1) < inputDeckStr.length()
			&& inputDeckStr[index + 1] == '0')
		{
			deck.push_back(MatchStringToCard("10"));

			index += 2;
			++iterationCount;
			continue;
		}

		deck.push_back(MatchStringToCard(std::string(1, inputDeckStr[index])));
		++index;

		++iterationCount;
	}
}

Player::Card Player::MatchStringToCard(const std::string& str) const
{
	if (str == "10")          return Card::Ten;
	if (std::isdigit(str[0])) return Card(str[0] - '0');
	if (str == "A")           return Card(14);
	if (str == "K")           return Card(13);
	if (str == "Q")           return Card(12);
	if (str == "J")           return Card(11);

	return Card::Invalid;
}

const std::string Player::MatchCardToString(const Card card) const
{
	unsigned int intCard = static_cast<int>(card);

	if (intCard > 1 && intCard < 10) return std::string(1, intCard + '0');
	if (intCard == 10) return "10";
	if (intCard == 11) return "J";
	if (intCard == 12) return "Q";
	if (intCard == 13) return "K";
	if (intCard == 14) return "A";

	return "";
}
