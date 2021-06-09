#include "constants.h"
#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>

using Deck = std::array<card, 52>;
constexpr int maxScore = 21;
constexpr int dealerStandScore = 17;

void printCard(const card& cd)
{
	switch (cd.r)
	{
	case rank::_2: std::cout << "2"; break;
	case rank::_3: std::cout << "3"; break;
	case rank::_4: std::cout << "4"; break;
	case rank::_5: std::cout << "5"; break;
	case rank::_6: std::cout << "6"; break;
	case rank::_7: std::cout << "7"; break;
	case rank::_8: std::cout << "8"; break;
	case rank::_9: std::cout << "9"; break;
	case rank::_10: std::cout << "10"; break;
	case rank::_J: std::cout << "J"; break;
	case rank::_Q: std::cout << "Q"; break;
	case rank::_K: std::cout << "K"; break;
	case rank::_A: std::cout << "A"; break;
	default: std::cout << "?";
	}
	switch (cd.s)
	{
	case suit::C: std::cout << "C"; break;
	case suit::D: std::cout << "D"; break;
	case suit::H: std::cout << "H"; break;
	case suit::S: std::cout << "S"; break;
	default: std::cout << "?";
	}
}

Deck createDeck()
{
	Deck deck{};
	Deck::size_type s{ 0 };
	for (int i{ 0 }; i < static_cast<int>(rank::max_ranks); i++)
	{
		for (int j{ 0 }; j < static_cast<int>(suit::max_suits); j++)
		{
			deck[s].r = static_cast<rank>(i);
			deck[s].s = static_cast<suit>(j);
			s++;
		}
	}
	return deck;
}

void printDeck(const Deck& deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
	std::cout << "\n";
}

void shuffleDeck(Deck& deck)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const card& cd)
{
	if (cd.r < rank::_10)
	{
		return static_cast<int>(cd.r) + 2;
	}
	else if (cd.r < rank::_A)
	{
		return 10;
	}
	else if (cd.r < rank::max_ranks)
	{
		return 11;
	}
	return -1;
}

bool requestHitOrStand(int& splayer)
{
	char ch{};
	std::cout << "Your score is : " << splayer << "\nEnter h(hit) or s(stand): ";
	std::cin >> ch;
	do
	{
		switch (ch)
		{
		case 'h':
			return true;
		case 's':
			return false;
		default:
			std::cout << "Wrong value entered, enter correct value h(hit) or s(stand): ";
			std::cin >> ch;
		}
	} while (true);
	std::cout << "Code should not be here\n";
	return false;
}

bool playerChance(const Deck& deck, Deck::size_type& top, int& splayer)
{
	while (true)
	{
		if (splayer > maxScore)
		{
			std::cout << "Score greater than max, player busted\n";
			return false;
		}
		if (requestHitOrStand(splayer))
		{
			splayer += getCardValue(deck[top++]);
		}
		else
		{
			return true;
		}
	}
	std::cout << "Code should not be here\n";
	return false;
}

bool dealerChance(const Deck& deck, Deck::size_type& top, int& sdealer)
{
	while (sdealer < dealerStandScore)
	{
		sdealer += getCardValue(deck[top++]);
		if (sdealer > maxScore)
		{
			std::cout << "Score greater than max, dealer busted\n";
			return false;
		}
	}
	return true;
}

bool playBlackJack(const Deck& deck)
{
	int splayer{ 0 };
	int sdealer{ 0 };
	Deck::size_type topIndex{ 0 };

	sdealer += getCardValue(deck[topIndex++]);
	std::cout << "Dealer Score: " << sdealer << "\n";

	splayer += getCardValue(deck[topIndex++]) + getCardValue(deck[topIndex++]);
	std::cout << "Player Score: " << splayer << "\n";

	if (!playerChance(deck, topIndex, splayer))
	{
		return false;
	}
	if (!dealerChance(deck, topIndex, sdealer))
	{
		return true;
	}
	std::cout << "Player: " << splayer << ", Dealer: " << sdealer << "\n";
	return splayer > sdealer;
}

int main()
{
	Deck deck{ createDeck() };
	shuffleDeck(deck);
	printDeck(deck);
	if (playBlackJack(deck))
	{
		std::cout << "Player wins!!!!\n";
	}
	else
	{
		std::cout << "Player loses!!!!\n";
	}
	return 0;
}