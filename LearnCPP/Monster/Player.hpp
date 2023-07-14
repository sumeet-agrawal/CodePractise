#ifndef PLAYER
#define PLAYER

#include "Creature.hpp"
#include "Potion.hpp"

class Player : public Creature
{
public:
    Player(std::string_view name)
        : Creature{name, '@', 10, 1, 0}
    {}
    void levelUp() { m_level++; m_damagePerAttack++;}
    const int getLevel() const { return m_level;}
    const bool hasWon() const { return m_level >= 20;}
    void drinkPotion(const Potion& p)
    {
        switch(p.getType())
        {
            case Potion::health:
                p.getSize() == Potion::large ? reduceHealth(-5) : reduceHealth(-2);
                break;
            case Potion::strength:
                m_damagePerAttack += 1;
                break;
            case Potion::poison:
                reduceHealth(1);
                break;
        }
    }
private: 
    int m_level{1};
};

#endif