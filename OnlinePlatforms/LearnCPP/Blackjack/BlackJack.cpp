#include "BlackJack.hpp"

#include <iostream>

bool Player::drawCard(Deck& deck)
{
    Card card{deck.dealCard()};
    m_score+=card.value();
    return card.rank()==Card::Rank::ace;
}

int BlackJack::playerPlay()
{
    char play{};
    int aceCntr{};
    if(m_player.drawCard(m_deck))
        aceCntr++;
    if(m_player.drawCard(m_deck))
        aceCntr++;
    do
    {
        std::cout<<"Current Score: "<<m_player.score()<<". Play h or s : ";
        std::cin>>play;
        if(play=='h')
        {
            if(m_player.drawCard(m_deck))
                aceCntr++;
        }
        if(m_player.score()>g_maximumScore && aceCntr)
            m_player.updateScore(m_player.score()-g_decreaseAceScore),
            aceCntr--;
    } while (play=='h' && m_player.score()<=g_maximumScore);
    return m_player.score();
}
int BlackJack::dealerPlay()
{
    m_dealer.drawCard(m_deck);
    while(m_dealer.score()<g_minDealerScore)
        m_dealer.drawCard(m_deck);
    return m_dealer.score();
}
BlackJack::Result BlackJack::play()
{
    m_deck.shuffle();
    int playerScore{playerPlay()};
    std::cout<<"Player Score: "<<playerScore<<"\n";
    if(playerScore>g_maximumScore)
        return Result::dealer_win;

    int dealerScore{dealerPlay()};
    std::cout<<"Dealer Score: "<<dealerScore<<"\n";
    if(dealerScore>g_maximumScore)
        return Result::player_win;

    if(playerScore > dealerScore)
        return Result::player_win;
    else if(playerScore < dealerScore)
        return Result::dealer_win;
    else
        return Result::tie;
}