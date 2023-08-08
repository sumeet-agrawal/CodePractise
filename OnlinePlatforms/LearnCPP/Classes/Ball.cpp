#include <iostream>

class Ball
{
private:
    std::string m_color{};
    double m_radius{};
public:
    Ball(const double &rd)
        : Ball{"black", rd}
    {}
    Ball(std::string_view str = "black", const double rd = 10.0)
        : m_color{str}
        , m_radius{rd}
    {}
    void print()
    {
        std::cout<<"color: "<<m_color<<", radius: "<<m_radius<<"\n";
    }
};

int main()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}