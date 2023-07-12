#ifndef PLAYING_GAME
#define PLAYING_GAME

#include "Deck.hpp"

class Player
{
public:
    Player()
    {}
    bool drawCard(Deck& deck);
    int score() const   {return m_score;}
    void updateScore(int score) {m_score = score;}
private:
    int m_score{};
};

class BlackJack
{
public:
    enum Result
    {
        player_win
        , dealer_win
        , tie
    };
    int playerPlay();
    int dealerPlay();
    Result play();
private:
    Player m_player;
    Player m_dealer;
    Deck m_deck;
    const int g_maximumScore{21};
    const int g_decreaseAceScore{10};
    const int g_minDealerScore{17};
};

#endif