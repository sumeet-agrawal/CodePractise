#include <iostream>
#include "Random.hpp"

int getGuess(int count)
{
    while(true)
    {
        std::cout<<"Guess #"<<count<<": ";
        int guess;
        std::cin>>guess;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(guess<1 || guess>100)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return guess;
    }
}

bool play(int generatedNUmber)
{
    int guessCount{1};
    while(guessCount<=7)
    {
        int guess{getGuess(guessCount)};
        if(guess==generatedNUmber)
            return true;
        else if(guess > generatedNUmber)
            std::cout<<"Your guess is too high.\n";
        else
            std::cout<<"Your guess is too low.\n";
        guessCount++;
    }
    return false;
    
}

void playgame()
{
    char ch{'y'};
    while(ch =='y')
    {
        std::cout<<"Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

        int generatedNUmber = Random::get(1, 100);
        if(play(generatedNUmber))
            std::cout<<"Correct! You win!\n";
        else
            std::cout<<"Sorry, you lose. The correct number was "<<generatedNUmber<<".\n";
        
        do
        {
            std::cout<<"Would you like to play again (y/n)? ";
            std::cin>>ch;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while(ch!='y' && ch!='n');
    }
    std::cout<<"Thank you for playing.\n";
}

int main()
{
    playgame();
    return 0;
}