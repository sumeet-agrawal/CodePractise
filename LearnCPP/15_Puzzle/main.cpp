#include "Board.hpp"
#include "Direction.hpp"

#include <iostream>
#include <limits>

namespace userInputs
{
    bool isValid(char ch)
    {
        switch(ch)
        {
            case 'w':
            case 'a':
            case 's':
            case 'd':
            case 'q':
                return true;
        }
        return false;
    }
    char getCommandFromUser()
    {
        char ch{};
        while(!isValid(ch))
        {
            std::cin>>ch;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
        }
        return ch;
    }
    Direction getDirectionFromCommand(char ch)
    {
        switch(ch)
        {
            case 'w': return {Direction::up};
            case 'a': return {Direction::left};
            case 's': return {Direction::down};
            case 'd': return {Direction::right};
        }
        return {Direction::max_directions};
    }
}

int main()
{
    Board board{};
    std::cout << board;

    std::cout << "Enter a command: ";

    while(!board.isSolved())
    {
        char input{userInputs::getCommandFromUser()};
        std::cout<<"Valid command: "<<input<<'\n';
        if(input == 'q')
        {
            std::cout<<"\n\nBye!\n\n";
            return 0;
        }
        Direction dir{userInputs::getDirectionFromCommand(input)};
        std::cout << "You entered direction: " << dir << '\n';

        board.moveTile(dir);
        std::cout<<board<<"\n";
    }

    std::cout<<"\n\nYou won!\n\n";
    
    return 0;
}
