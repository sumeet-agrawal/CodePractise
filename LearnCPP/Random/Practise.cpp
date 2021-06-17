#include <iostream>

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
    Apple(const std::string& c = "red", const std::string& n = "apple", double f = 0.0)
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
    Banana(const std::string& n = "banana", const std::string& c = "yellow")
        : Fruit(n, c)
    {}
    friend std::ostream& operator<<(std::ostream& out, const Banana& b)
    {
        out<< "Apple("<<b.getName()<<", "<<b.getColor()<<")";
    } 
};

class GrannySmith : public Apple
{
public:
    GrannySmith(const std::string& n = "granny smith apple", const std::string& c = "green")
        : Apple(c,n)
    {}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;
 
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	return 0;
}