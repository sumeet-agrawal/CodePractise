#include "enums.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <random>

struct card
{
    Cards::ranks rank{};
    Cards::suits suit{};
};

using Deck = std::array<card, 52>;

void printCard(const card& crd)
{
    switch(crd.rank)
    {
        case Cards::ranks::two:
        case Cards::ranks::three:
        case Cards::ranks::four:
        case Cards::ranks::five:
        case Cards::ranks::six:
        case Cards::ranks::seven:
        case Cards::ranks::eight:
        case Cards::ranks::nine:
            std::cout<<static_cast<char>('2'+static_cast<int>(crd.rank)); break;
        case Cards::ranks::ten:
            std::cout<<'T'; break;
        case Cards::ranks::jack:
            std::cout<<'J'; break;
        case Cards::ranks::queen:
            std::cout<<'Q'; break;
        case Cards::ranks::king:
            std::cout<<'K'; break;
        case Cards::ranks::ace:
            std::cout<<'A'; break;
        default:
            std::cout<<'?'; break;
    }
    switch(crd.suit)
    {
        case Cards::suits::clubs:
            std::cout<<'C'; break;
        case Cards::suits::diamonds:
            std::cout<<'D'; break;
        case Cards::suits::hearts:
            std::cout<<'H'; break;
        case Cards::suits::spades:
            std::cout<<'S'; break;
        default:
            std::cout<<'?'; break;
    }
}

Deck createDeck()
{
    int ranks = static_cast<int>(Cards::ranks::max_ranks);
    int suits = static_cast<int>(Cards::suits::max_suits);

    Deck deck;
    for(int i{}, k=0; i<ranks; i++)
    {
        for(int j{}; j<suits; j++, k++)
        {
            deck[k].rank = static_cast<Cards::ranks>(i);
            deck[k].suit = static_cast<Cards::suits>(j);
        }
    }
    return deck;
}

void printDeck(const Deck& deck)
{
    for(const auto &x: deck)
        printCard(x),
        std::cout<<" ";
    std::cout<<"\n";
}

void shuffleDeck(Deck &deck)
{
    static std::mt19937_64 mt{static_cast<std::mt19937_64::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())};
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const card& crd)
{
    switch(crd.rank)
    {
        case Cards::ranks::two:
        case Cards::ranks::three:
        case Cards::ranks::four:
        case Cards::ranks::five:
        case Cards::ranks::six:
        case Cards::ranks::seven:
        case Cards::ranks::eight:
        case Cards::ranks::nine:
            return 2 + static_cast<int>(crd.rank);
        case Cards::ranks::ten:
        case Cards::ranks::jack:
        case Cards::ranks::queen:
        case Cards::ranks::king:
            return 10;
        case Cards::ranks::ace:
            return 11;
        default:
            return -1;
    }
}

int playerPlay(const Deck& deck, int &ind)
{
    int score{};
    int aceCntr{};
    if(deck[ind].rank == Cards::ranks::ace)
        aceCntr++;
    score+=getCardValue(deck[ind++]);
    if(deck[ind].rank == Cards::ranks::ace)
        aceCntr++;
    score+=getCardValue(deck[ind++]);
    char play{};
    do
    {
        std::cout<<"Current Score: "<<score<<". Play h or s : ";
        std::cin>>play;
        if(play=='h')
        {
            if(deck[ind].rank == Cards::ranks::ace)
                aceCntr++;
            score += getCardValue(deck[ind++]);
        }
        if(score>Cards::g_maxScore && aceCntr)
            score-= Cards::g_decreaseAceScore,
            aceCntr--;
    } while (play=='h' && score<=Cards::g_maxScore);
    return score;
}

int dealerPlay(const Deck& deck, int &ind)
{
    int score{};
    score+=getCardValue(deck[ind++]);
    while(score<Cards::g_minDealerScore)
        score += getCardValue(deck[ind++]);
    return score;
}

Cards::BlackJackResult playBlackjack(const Deck& deck)
{
    int ind{};
    
    int playerScore = playerPlay(deck, ind);
    std::cout<<"Player Score: "<<playerScore<<"\n";
    if(playerScore>Cards::g_maxScore)
        return Cards::BlackJackResult::dealer_win;

    int dealerScore = dealerPlay(deck, ind);
    std::cout<<"Dealer Score: "<<dealerScore<<"\n";
    if(dealerScore>Cards::g_maxScore)
        return Cards::BlackJackResult::player_win;

    if(playerScore > dealerScore)
        return Cards::BlackJackResult::player_win;
    else if(playerScore < dealerScore)
        return Cards::BlackJackResult::dealer_win;
    else
        return Cards::BlackJackResult::tie;
}

int main()
{
    Deck deck{createDeck()};
    shuffleDeck(deck);

    Cards::BlackJackResult result{playBlackjack(deck)};
    if (result== Cards::BlackJackResult::player_win)
        std::cout << "You win!\n";
    else if(result== Cards::BlackJackResult::dealer_win)
        std::cout << "You lose!\n";
    else
        std::cout<< "Its a tie!\n";
    
    return 0;
}