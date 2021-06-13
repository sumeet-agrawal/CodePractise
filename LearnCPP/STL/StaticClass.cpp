#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <array>

class Monster
{
public:
	enum class Type
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		max_monsters_type
	};
	Monster(Type t, const std::string& n, const std::string& r, int h)
		: m_type(t)
		, m_name(n)
		, m_roar(r)
		, m_hit(h)
	{}
	void print()
	{
		std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hit << " hit points and says " << m_roar << "\n";
	}
private:
	std::string getTypeString(Type t)
	{
		switch (t)
		{
		case Type::Dragon: return "Dragon";
		case Type::Goblin: return "Goblin";
		case Type::Ogre: return "Ogre";
		case Type::Orc: return "Orc";
		case Type::Skeleton: return "Skeleton";
		case Type::Troll: return "Troll";
		case Type::Vampire: return "Vampire";
		case Type::Zombie: return "Zombie";
		default: return "?";
		}
	}

	Type m_type;
	std::string m_name;
	std::string m_roar;
	int m_hit;
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		return Monster{
			static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monsters_type) - 1)),
			m_names[getRandomNumber(0,m_names.size() - 1)],
			m_roars[getRandomNumber(0,m_roars.size() - 1)],
			getRandomNumber(1, 100) };
	}
private:
	static int getRandomNumber(int min, int max)
	{
		static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
		return std::uniform_int_distribution{ min, max }(mt);
	}
	static constexpr std::array m_names{ "Sumeet", "Sheetal", "Mohit", "Sunil", "Sunita", "Omprakash" };
	static constexpr std::array m_roars{ "Bow-Bow","Meow","Mehh","Ghrrrr","Hisss","Maaaa" };
};

int main()
{
	for (int i{ 0 }; i < 20; i++)
	{
		Monster m{ MonsterGenerator::generateMonster() };
		m.print();
	}

	return 0;
}