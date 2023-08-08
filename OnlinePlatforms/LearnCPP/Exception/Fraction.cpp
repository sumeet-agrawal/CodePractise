#include <iostream>
#include <stdexcept>

class Fraction
{
public:
    Fraction(int x, int y)
        : m_n{x}
        , m_d{y}
    {
        if(!y)
            throw std::runtime_error("Invalid denominator\n");
    }
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
    {
        return out<<f.m_n<<'/'<<f.m_d;
    }
private:
    int m_n{0};
    int m_d{1};
};

int main()
{
    int x{}, y{};
    std::cout<<"Enter the numerator: ";
    std::cin>>x;
    std::cout<<"Enter the denominator: ";
    std::cin>>y;
    try{
        Fraction f{x,y};
        std::cout<<f<<"\n";
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what();
    }
    return 0;
}