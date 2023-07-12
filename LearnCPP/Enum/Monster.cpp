#include <iostream>
#include "Random.hpp"
class Monster
{
public:
    enum Type {
        dragon
        , goblin
        , ogre
        , orc
        , skeleton
        , troll
        , vampire
        , zombie

        , max_types
    };
private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};
public:
    Monster(Type type, std::string_view name, std::string_view roar, int hit)
        : m_type{type}
        , m_name{name}
        , m_roar{roar}
        , m_hitPoints{hit}
    {}
    std::string_view getTypeString() const
    {
        switch(m_type)
        {
            case dragon: return "dragon";
            case goblin: return "goblin";
            case ogre: return "ogre";
            case orc: return "orc";
            case skeleton: return "skeleton";
            case troll: return "troll";
            case vampire: return "vampire";
            case zombie: return "zombie";
            default: return "???";
        }
    }
    void print() const
    {
        std::cout<<m_name<<" the "<<getTypeString()<<" has "<<m_hitPoints<<" hit points and says "<<m_roar<<"\n";
    }
};

namespace MonsterGenerator
{
    Monster generate()
    {
        static constexpr std::string_view s_name[]{"sumeet", "mohit", "sheetal", "tanya", "sunil", "sunita"};
        static constexpr std::string_view s_roar[]{"bark", "meow", "maah", "roar", "hisss", "rattle"};

        return { 
            static_cast<Monster::Type>(Random::get(0, static_cast<int>(Monster::max_types)-1)),
            s_name[Random::get(0,5)],
            s_roar[Random::get(0,5)],
            Random::get(1, 100)
         };
    }
}

int main()
{
	for(int i{};i<10;i++)
    {
        Monster m{ MonsterGenerator::generate() };
	    m.print();
    }

	return 0;
}