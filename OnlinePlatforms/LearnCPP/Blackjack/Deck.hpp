#ifndef PLAYING_DECK
#define PLAYING_DECK

#include "Card.hpp"

#include <array>

class Deck
{
public:
    Deck()
    {
        int ranks = static_cast<int>(Card::Rank::max_ranks);
        int suits = static_cast<int>(Card::Suit::max_suits);

        for(int i{}, k=0; i<ranks; i++)
            for(int j{}; j<suits; j++, k++)
                m_deck[k] = { static_cast<Card::Rank>(i), static_cast<Card::Suit>(j)};
    }
    void print() const;
    void shuffle();
    const Card& dealCard();
private:
    std::array<Card, 52> m_deck{};
    int m_cardIndex{};
};

#endif