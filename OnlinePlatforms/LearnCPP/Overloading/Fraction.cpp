#include <iostream>
#include <numeric>

class Fraction
{
public:
    Fraction() = default;
    Fraction(int n, int d =1)
        : m_n{n}
        , m_d{d}
    {
        reduce();
    }
    void reduce()
    {
        int g{std::gcd(m_n, m_d)};
        if(g)
        {
            m_n/=g;
            m_d/=g;
        }
    }
    void print() const
    {
        std::cout<<m_n<<'/'<<m_d<<'\n';
    }
    friend Fraction operator*(const Fraction& f, int a);
    friend Fraction operator*(int a, const Fraction& f);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);
    bool operator==(const Fraction& f) const { return (m_n==f.m_n) && (m_d==f.m_d);}
    bool operator!=(const Fraction& f) const { return !(*this == f);}
    bool operator<(const Fraction& f) const { return m_n*f.m_d < m_d*f.m_n;}
    bool operator>=(const Fraction& f) const { return !(*this < f);}
    bool operator>(const Fraction& f) const { return f < *this;}
    bool operator<=(const Fraction& f) const { return !(f < *this);}
private:
    int m_n{};
    int m_d{1};
};

Fraction operator*(const Fraction& f, int a)
{
    return f*Fraction{a};
}

Fraction operator*(int a, const Fraction& f)
{
    return f*a;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return {f1.m_n*f2.m_n, f1.m_d*f2.m_d};
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out<<f.m_n<<'/'<<f.m_d;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    in>>f.m_n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in>>f.m_d;
    f.reduce();
    return in;
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}