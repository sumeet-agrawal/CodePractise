#ifndef MONSTER
#define MONSTER

#include "Creature.hpp"
#include "Random.hpp"

#include <array>

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types
    };
    Monster(Type type)
        : Creature{getCreature(type)}
    {}
    static Monster getRandomMonster(){ return {static_cast<Type>(Random::get(0,max_types-1))};}
private:
    static const Creature& getCreature(Type type)
    {
        static std::array<Creature, max_types> monsters{{
            {"dragon",   'D',    20, 4,  100},
            {"orc",      'o',    4,  2,  25},
            {"slime",    's',    1,  1,  10}
        }};
        return monsters[type];
    }
};

#endif
