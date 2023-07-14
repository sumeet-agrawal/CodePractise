#ifndef CREATURE
#define CREATURE

#include <string>

class Creature
{
private:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_gold{};
protected:
    int m_damagePerAttack{};
public:
    Creature() = default;
    Creature(std::string_view name, char c, int health, int dpa, int gold)
        : m_name{name}
        , m_symbol{c}
        , m_health{health}
        , m_gold{gold}
        , m_damagePerAttack{dpa}
    {}
    std::string_view getName() const { return m_name;}
    char getSymbol() const { return m_symbol;}
    int getHealth() const { return m_health;}
    int getDPA() const { return m_damagePerAttack;}
    int getGold() const { return m_gold;}
    void reduceHealth(int x) { m_health -= x;}
    bool isDead() const { return m_health <= 0;}
    void addGold(int x) { m_gold += x;}
};

#endif