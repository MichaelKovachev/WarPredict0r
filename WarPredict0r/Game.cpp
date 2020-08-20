#include "Game.h"
#include <random>

void Game::Init(bool verbose, bool shouldGenerateShuffledDecks)
{
	this->verbose = verbose;
	if (!shouldGenerateShuffledDecks)
	{
		std::cout << "Enter the first player's deck with each card separated by a space. Hit ENTER when you are done:" << std::endl;
		if (!p1.Init()) { isOver = true; return; }

		std::cout << "Enter the second player's deck with each card separated by a space. Hit ENTER when you are done:" << std::endl;
		if (!p2.Init()) { isOver = true; return; }
	}
	else
	{
		GenerateShuffledRandomDecks();
	}
}

void Game::Run()
{
	while (!isOver)
	{
		SimulateRound();
	}
}

void Game::SimulateRound()
{
	++roundCount;
	std::vector<Player::Card> p1CardsAtRound;
	if (!p1.DrawNext(p1CardsAtRound)) 
	{ 
		if(verbose) PrintRoundInfo(p1CardsAtRound, std::vector<Player::Card>());

		isOver = true; 
		winner = 1; 
		PrintRoundWinMessage();
		return; 
	}

	std::vector<Player::Card> p2CardsAtRound;
	if (!p2.DrawNext(p2CardsAtRound))
	{
		if(verbose) PrintRoundInfo(p1CardsAtRound, p2CardsAtRound);

		isOver = true;
		winner = 2;
		PrintRoundWinMessage();
		return;
	}

	while (*(p1CardsAtRound.end() - 1) == *(p2CardsAtRound.end() - 1))
	{
		if (!p1.DrawNext(p1CardsAtRound, 3))
		{
			if(verbose) PrintRoundInfo(p1CardsAtRound, p2CardsAtRound);
			
			isOver = true; 
			winner = 1; 
			PrintRoundWinMessage();
			return;
		}
		if (!p2.DrawNext(p2CardsAtRound, 3))
		{
			if(verbose) PrintRoundInfo(p1CardsAtRound, p2CardsAtRound);
			
			isOver = true; 
			winner = 2; 
			PrintRoundWinMessage();
			return;
		}
	}

	std::vector<Player::Card> currentRoundCards;
	currentRoundCards.insert(currentRoundCards.end(), p1CardsAtRound.begin(), p1CardsAtRound.end());
	currentRoundCards.insert(currentRoundCards.end(), p2CardsAtRound.begin(), p2CardsAtRound.end());

	if (*(p1CardsAtRound.end() - 1) > * (p2CardsAtRound.end() - 1))
	{
		p1.AppendToDeck(currentRoundCards);
		if (verbose) std::cout << "Player 1 won round.";
	}
	else
	{
		p2.AppendToDeck(currentRoundCards);
		if (verbose) std::cout << "Player 2 won round.";
	}
	if(verbose) PrintRoundInfo(p1CardsAtRound, p2CardsAtRound);
}

void Game::GenerateShuffledRandomDecks()
{
	std::vector<Player::Card> completeCardDeck;
	completeCardDeck.reserve(52);
	for (int i = 0; i < 4; ++i) // 4 colors
		for (int j = 2; j <= 14; ++j) // 12 cards from each color
			completeCardDeck.push_back(Player::Card(j));

	std::random_device rd;
	auto rng = std::default_random_engine{ rd() };

	std::shuffle(completeCardDeck.begin(), completeCardDeck.end(), rng);

	std::vector<Player::Card> p1Deck;
	p1Deck.reserve(26);
	std::vector<Player::Card> p2Deck;
	p2Deck.reserve(26);

	for (int i = 0; i < completeCardDeck.size(); ++i)
	{
		if (i % 2 == 0)
			p1Deck.push_back(completeCardDeck[i]);
		else
			p2Deck.push_back(completeCardDeck[i]);
		
	}

	p1.UseDeck(p1Deck);
	p2.UseDeck(p2Deck);
}

void Game::PrintRoundInfo(const std::vector<Player::Card>& p1CardsAtRound, const std::vector<Player::Card>& p2CardsAtRound)
{
	std::cout << " | cards: ";
	for (const Player::Card& card : p1CardsAtRound)
	{
		std::cout << Player::MatchCardToString(card) << " ";
	}
	std::cout << "against ";
	for (const Player::Card& card : p2CardsAtRound)
	{
		std::cout << Player::MatchCardToString(card) << " ";
	}
	std::cout << std::endl;
}

void Game::PrintRoundWinMessage()
{
	std::cout << "Player " << winner << " won!" << std::endl;
	std::cout << "Number of rounds played: " << roundCount << std::endl;
}
