#include <iostream>

class Fraction
{
public:
    Fraction(int a = 0, int b = 1)
        : m_numerator(a)
        , m_denominator(b)
    {
        reduce();
    }
    void print() const
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
private:
    int gcd(int a, int b)
    {
        if (a == 0)
            return 0;
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
    void reduce()
    {
        int gc = gcd(m_numerator, m_denominator);
        if (!gc)
            return;
        m_numerator /= gc;
        m_denominator /= gc;
    }
    int m_numerator{ 0 };
    int m_denominator{ 1 };
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

#include <iostream>

int main()
{
    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    f6.print();

    Fraction f7{ 0, 6 };
    f7.print();


    return 0;
}