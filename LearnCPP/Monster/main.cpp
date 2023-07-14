#include "Monster.hpp"
#include "Player.hpp"
#include "Potion.hpp"

#include <iostream>

namespace game
{
    char getValidInput(char a='r', char b='f')
    {
        char ch{};
        while(ch!=a && ch!=b)
        {
            std::cin>>ch;
            if(std::cin.fail())
                std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        return ch;
    }
    bool attackMonster(Player& player, Monster& mns)
    {
        std::cout<<"You hit the "<<mns.getName()<<" for "<<player.getDPA()<<" damage.\n";
        mns.reduceHealth(player.getDPA());
        if(mns.isDead())
        {
            std::cout<<"You killed the "<<mns.getName()<<".\n";
            player.levelUp();
            std::cout<<"You are now level "<<player.getLevel()<<".\n";
            std::cout<<"You found "<<mns.getGold()<<" gold.\n";
            player.addGold(mns.getGold());
            if(Random::get(1,10)<=3)
            {
                std::cout<<"You found a mythical potion! Do you want to drink it? [y/n]: ";
                if(getValidInput('y','n')=='y')
                {
                    Potion p{};
                    player.drinkPotion(p);
                    std::cout<<p<<'\n';
                }
            }
        }
        return mns.isDead();
    }
    void attackPlayer(Player& player, const Monster& mns)
    {
        std::cout<<"The "<<mns.getName()<<" hit you for "<<mns.getDPA()<<" damage.\n";
        player.reduceHealth(mns.getDPA());
    }
    void fightMonster(Player& player, Monster& mns)
    {
        std::cout<<"(R)un or (F)ight: ";
        char input{getValidInput()};

        if(input=='f')
        {
            if(!attackMonster(player, mns))
            {
                attackPlayer(player, mns);
                if(!player.isDead())
                    fightMonster(player, mns);
            }
        }
        else
        {
            if(Random::get(0,1))
                std::cout<<"You successfully fled.\n";
            else
                std::cout<<"You failed to flee.\n",
                attackPlayer(player, mns);
        }
    }
}

int main()
{
    std::cout<<"Enter your name: ";
    std::string name{};
    std::cin>>name;
    std::cout<<"Welcome, "<<name<<'\n';

    Player player{name};

    while(!player.isDead() && !player.hasWon())
    {
        Monster mns{Monster::getRandomMonster()};
        std::cout<<"You have encountered a "<<mns.getName()<<" ("<<mns.getSymbol()<<").\n";

        game::fightMonster(player, mns);
    }

    if(player.isDead())
        std::cout<<"You died at level "<<player.getLevel()<<" and with "<<player.getGold()<<" gold.\n"
                    "Too bad you can’t take it with you!";
    else
        std::cout<<"You Won!!! You have "<<player.getGold()<<" gold.\n";

    return 0;
}