#include "Deck.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>

void Deck::print() const
{
    for(const auto &x: m_deck)
        x.print(),
        std::cout<<" ";
    std::cout<<"\n";
}
void Deck::shuffle()
{
    static std::mt19937_64 mt{static_cast<std::mt19937_64::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}
const Card& Deck::dealCard()
{
    return m_deck[m_cardIndex++];
}