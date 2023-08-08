#include "Card.hpp"

#include <iostream>

void Card::print() const
{
    switch(m_rank)
    {
        case Rank::two:
        case Rank::three:
        case Rank::four:
        case Rank::five:
        case Rank::six:
        case Rank::seven:
        case Rank::eight:
        case Rank::nine:
            std::cout<<static_cast<char>('2'+static_cast<int>(m_rank)); break;
        case Rank::ten:
            std::cout<<'T'; break;
        case Rank::jack:
            std::cout<<'J'; break;
        case Rank::queen:
            std::cout<<'Q'; break;
        case Rank::king:
            std::cout<<'K'; break;
        case Rank::ace:
            std::cout<<'A'; break;
        default:
            std::cout<<'?'; break;
    }
    switch(m_suit)
    {
        case Suit::clubs:
            std::cout<<'C'; break;
        case Suit::diamonds:
            std::cout<<'D'; break;
        case Suit::hearts:
            std::cout<<'H'; break;
        case Suit::spades:
            std::cout<<'S'; break;
        default:
            std::cout<<'?'; break;
    }
}
int Card::value() const
{
    switch(m_rank)
    {
        case Rank::two:
        case Rank::three:
        case Rank::four:
        case Rank::five:
        case Rank::six:
        case Rank::seven:
        case Rank::eight:
        case Rank::nine:
            return 2 + static_cast<int>(m_rank);
        case Rank::ten:
        case Rank::jack:
        case Rank::queen:
        case Rank::king:
            return 10;
        case Rank::ace:
            return 11;
        default:
            return -1;
    }
}
Card::Rank Card::rank() const
{
    return m_rank;
}