#include "BlackJack.hpp"

#include <iostream>

int main()
{
    BlackJack game{};
    BlackJack::Result result{game.play()};
    if (result== BlackJack::Result::player_win)
        std::cout << "You win!\n";
    else if(result== BlackJack::Result::dealer_win)
        std::cout << "You lose!\n";
    else
        std::cout<< "Its a tie!\n";
    
    return 0;
}