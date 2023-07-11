#include <iostream>

enum class MonsterType {
    ogre
    , dragon
    , orc
    , giant_spider
    , slime
};

struct Monster
{
    MonsterType type{};
    std::string name{};
    int health{};
};

std::string_view getMonsterType(MonsterType type)
{
    using enum MonsterType;
    switch(type)
    {
        case ogre: return "Ogre";
        case dragon: return "Dragon";
        case orc: return "Orc";
        case giant_spider: return "Giant Spider";
        case slime: return "Slime";
        default : "???";
    }
}
void printMonster(const Monster& m)
{
    std::cout<<"This "<<getMonsterType(m.type)<<" is named "
            <<m.name<<" and has "<<m.health<<" health.\n";
}

int main()
{
    Monster org{MonsterType::ogre, "Torg", 145};
    Monster slime{MonsterType::slime, "Blurp", 23};

    printMonster(org);
    printMonster(slime);
    return 0;
}