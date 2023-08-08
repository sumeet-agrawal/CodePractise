#include <iostream>

class Fruit
{
public:
    Fruit(std::string_view name, std::string_view color)
        : m_name{name}
        , m_color{color}
    {}
    std::string_view getName() const { return m_name;}
    std::string_view getColor() const { return m_color;}
private:
    std::string m_name{};
    std::string m_color{};
};

class Apple : public Fruit
{
public:
    Apple(std::string_view color = "red", std::string_view name = "apple")
        : Fruit{name, color}
    {}
    friend std::ostream& operator<<(std::ostream& out, const Apple& apple)
    {
        return out<<"Apple("<<apple.getName()<<", "<<apple.getColor()<<")";
    }
private:
    double m_fibre{};
};

class Banana : public Fruit
{
public:
    Banana(std::string_view name = "banana", std::string_view color = "yellow")
        : Fruit{name, color}
    {}
    friend std::ostream& operator<<(std::ostream& out, const Banana& banana)
    {
        return out<<"Banana("<<banana.getName()<<", "<<banana.getColor()<<")";
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith(std::string_view color = "green", std::string_view name = "granny smith apple")
        : Apple(name, color)
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