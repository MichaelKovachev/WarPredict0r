#include "Player.h"

#include <iostream>
#include <string>
#include <array>


void Player::Init()
{
	//deck.reserve(initialDeckSize);
	HandleInputToDeck();
}

bool Player::DrawNext(std::vector<Card>& drawnCards, unsigned int amount)
{
	if (amount <= 3 && amount >= 1)
	{
		// if the player doesn't have enough cards, he loses
		if (amount > deck.size()) return false;

		for (unsigned int i = 1; i <= amount; ++i)
		{
			drawnCards.push_back(deck[0]);
			deck.erase(deck.begin());
			
		}
	}
	return true;
}

void Player::AppendToDeck(Card card)
{
	deck.push_back(card);
}

void Player::AppendToDeck(const std::vector<Card>& cards)
{
	for (const auto& card : cards)
		AppendToDeck(card);
}

void Player::UseDeck(const std::vector<Card>& deck)
{

	this->deck = deck;
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
	
	for (unsigned int iterationCount = 0, index = 0; iterationCount < initialDeckSize; )    // index is the index in the string
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

const std::string Player::MatchCardToString(const Card card)
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
