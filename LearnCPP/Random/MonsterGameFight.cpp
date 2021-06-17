#include <iostream>
#include <string>
#include <array>
#include <random> // for rand() and srand()
#include <ctime> // for time()

int getRandomNumber(int, int);

class Potion
{
public:
    enum class Type
    {
        Health,
        Strength,
        Poison,

        max_types
    };
    enum class Size
    {
        Small, 
        Medium,
        Large,

        max_sizes
    };
    Potion(Type t, Size s)
        : m_type(t)
        , m_size(s)
    {}
    const std::string getName() const 
    {
        switch (m_type)
        {
        case Type::Health:  return "Health";
        case Type::Strength:return "Strength";
        case Type::Poison:  return "Poison";
        default:
            break;
        }
        return "??";
    }
    const std::string getSizeName() const 
    {
        switch(m_size)
        {
        case Size::Small:   return "Small";
        case Size::Medium:  return "Medium";
        case Size::Large:   return "Large";
        default:
            break;
        }
        return "??";
    }
    static Potion getRandomPotion()
    {
        return {
            static_cast<Type>(getRandomNumber(0, static_cast<int>(Type::max_types) -1)),
            static_cast<Size>(getRandomNumber(0, static_cast<int>(Size::max_sizes) -1))
        };
    }
    Type getType() const { return m_type;}
    Size getSize() const { return m_size;}
private:
    Type m_type;
    Size m_size;
};

class Creature
{
public:
    Creature(const std::string& n, char s, int h, int d, int g)
        : m_name(n)
        , m_symbol(s)
        , m_health(h)
        , m_dpattack(d)
        , m_gold(g)
    {}

    const std::string& getName() const {return m_name;}
    char getSymbol() const {return m_symbol;}
    int getHealth() const {return m_health;}
    int getDPAttack() const { return m_dpattack;}
    int getGold() const {return m_gold;}

    void reduceHealth(int h) { m_health -= h;}
    bool isDead() { return (m_health <= 0);}
    void addGold(int g) { m_gold += g;}
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_dpattack;
    int m_gold;
};

class Player : public Creature
{
public:
    Player(const std::string& n, char s = '@', int h = 10, int d = 1, int g = 0)
        : Creature(n,s,h,d,g)
        , m_level(1)
    {}

    void levelUp() 
    { 
        m_level++;
        m_dpattack++;
    }
    int getLevel() const { return m_level;}
    bool hasWon() const { return m_level >= 20;}
    void drinkPotion(const Potion& pt)
    {
        static std::array<std::array<int, 3>, 3> potionTable
        {  
            {
            {2, 3, 5}, {1, 1, 2}, {-1, -2, -4}
            }
        };
        switch(pt.getType())
        {
        case Potion::Type::Health:
        case Potion::Type::Poison:
            m_health+= potionTable[static_cast<int>(pt.getType())][static_cast<int>(pt.getSize())];
            break;
        case Potion::Type::Strength: 
            m_dpattack+= potionTable[static_cast<int>(pt.getType())][static_cast<int>(pt.getSize())];
            break;
        default:
            std::cout<<"Wrong type\n";
        }
    }
private:
    int m_level;
};

class Monster : public Creature
{
public:
    enum class Type
    {
        dragon, 
        orc,
        slime,

        max_types
    };
    Monster(Type t)
        : Creature (getDefaultCreature(t))
    {
    }
    static Monster getRandomMonster()
    {
        int num = getRandomNumber(0, static_cast<int>(Type::max_types) - 1);
        return Monster(static_cast<Type>(num));
    }
private:
    static const Creature& getDefaultCreature(Type t)
    {
        static std::array<Creature, static_cast<int>(Type::max_types)> defaultMonsters{
            {
        { "dragon", 'D', 20, 4, 100 },
        { "orc", 'o', 4, 2, 25 },
        { "slime", 's', 1, 1, 10 } 
            }
        };
        return defaultMonsters[static_cast<std::size_t>(t)];    
    }
};

class Game
{
public:
    Game(const std::string& player_name)
        : m_player(player_name)
        , m_monster(nullptr)
    {}
    void play()
    {
        while(!m_player.isDead() && !m_player.hasWon())
        {
            //The player encounters one randomly generated monster at a time.
            if(!m_monster)
            {
                createMonster();
            }
            
            //For each monster, the player has two choices: (R)un or (F)ight.
            if(getChoice() == 'f')
            {
                //If the player chooses to fight, the player attacks first. The monster's health is reduced by the player's damage.
                attackMonster();
                if(m_monster->isDead())
                {
                    //If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
                    m_player.addGold(m_monster->getGold());
                    m_player.levelUp();
                    std::cout<<"You killed the "<<m_monster->getName()<<".\nYou are now level "<<m_player.getLevel()<<".\nYou found "<<m_monster->getGold()<<" gold.\n";
                    deleteMonster();
                    potionProcess();
                }
                else
                {
                    //If the monster does not die, the monster attacks the player back. The player's health is reduced by the monster's damage.
                    attackPlayer();
                }
            }
            else
            {
                //If the player decides to Run, they have a 50% chance of escaping.
                if(getRandomNumber(0,1))
                {
                    //If the player escapes, they move to the next encounter with no ill effects.
                    std::cout<<"You successfully fled.\n";
                    deleteMonster();
                }
                else
                {
                    //If the player does not escape, the monster gets a free attack, and the player chooses their next action.
                    std::cout<<"You failed to flee.\n";
                    attackPlayer();
                }
            }
        }
    }
    void getResult()
    {
        if(m_player.hasWon())
        {
            std::cout<<"Congratulations!!!. You won.\n You have "<<m_player.getGold()<<" gold.\n";
        }
        else if(m_player.isDead())
        {
            std::cout<<"You died at level "<<m_player.getLevel()<<" and with "<<m_player.getGold()<<" gold.\nToo bad you can't take it with you!\n";
        }
    }
private:
    void potionProcess()
    {
        int num = getRandomNumber(1, 10);
        if(num<=3)
        {
            Potion p{Potion::getRandomPotion()};
            char ch;
            std::cout<<"You found a mythical potion! Do you want to drink it? [y/n]: ";
            std::cin>>ch;
            switch(ch)
            {
            case 'y':
                m_player.drinkPotion(p);
                std::cout<<"You drank a "<<p.getSizeName()<<" potion of "<<p.getName()<<"\n";
                break;
            case 'n':
            default:
                std::cout<<"You abondaned a "<<p.getSizeName()<<" potion of "<<p.getName()<<"\n";
            }
        }
    }
    void attackPlayer()
    {
        m_player.reduceHealth(m_monster->getDPAttack());
        std::cout<<"The "<<m_monster->getName()<<" hit you for "<<m_monster->getDPAttack()<<" damage.\n";
    }
    void attackMonster()
    {
        m_monster->reduceHealth(m_player.getDPAttack());
        std::cout<<"You hit the "<<m_monster->getName()<<" for "<<m_player.getDPAttack()<<" damage.\n";                
    }
    void deleteMonster()
    {
        delete m_monster;
        m_monster = nullptr;
    }
    void createMonster()
    {
        m_monster = new Monster(Monster::getRandomMonster());
        std::cout<<"You have encountered a "<<m_monster->getName()<<" ("<<m_monster->getSymbol()<<").\n";
    }
    char getChoice()
    {
        char ch{};
        do
        {
            std::cout<<"(r)un or (f)ight: ";
            std::cin>>ch;
        } while (ch!='r' && ch!='f');
        return ch;
    }
    Player m_player;
    Monster *m_monster;
};

int getRandomNumber(int min, int max)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    return std::uniform_int_distribution<int>{min, max}(mt);
}

int main()
{
	std::string player;
    std::cout<<"Enter your name: ";
    std::cin>>player;
    std::cout<<"Welcome, "<<player<<"\n";
    
    Game game{player};
    game.play();
    game.getResult();

	return 0;
}