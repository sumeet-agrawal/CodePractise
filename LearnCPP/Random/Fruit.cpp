#include <iostream>
#include <string>

class Fruit
{
public:
    Fruit(const std::string& n, const std::string& c)
        : m_name(n)
        , m_color(c)
    {}
    const std::string& getName() const { return m_name;}
    const std::string& getColor() const {return m_color;}
private: 
    std::string m_name{};
    std::string m_color{};
};

class Apple : public Fruit
{
public:
    Apple(const std::string& n, const std::string& c, double f)
        : Fruit(n, c)
        , m_fibre(f)
    {}
    friend std::ostream& operator<<(std::ostream& out, const Apple& a)
    {
        out<< "Apple("<<a.getName()<<", "<<a.getColor()<<", "<<a.m_fibre<<")";
    } 
private:
    double m_fibre{0};
};

class Banana: public Fruit
{
public:
    Banana(const std::string& n, const std::string& c)
        : Fruit(n, c)
    {}
    friend std::ostream& operator<<(std::ostream& out, const Banana& b)
    {
        out<< "Apple("<<b.getName()<<", "<<b.getColor()<<")";
    } 
};

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';
 
	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';
 
	return 0;
}