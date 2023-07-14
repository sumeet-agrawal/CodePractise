#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2
{
public:
    FixedPoint2(std::int16_t a=0, std::int8_t b=0)
        : m_nonFractional{a}
        , m_fractional{b}
    {
        updateSign();
    }
    FixedPoint2(double d) :
		m_nonFractional{ static_cast<std::int16_t>(std::trunc(d)) },
		m_fractional{ static_cast<std::int8_t>(std::round(d * 100) - m_nonFractional * 100) }
	{
        updateSign();
    }
    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
    {
        return out<<static_cast<double>(fp);
    }
    friend std::istream& operator>>(std::istream& in, FixedPoint2& fp)
    {
        double db{};
        in>>db;
        fp = FixedPoint2{db};
        return in;
    }
    operator double() const
    {
        return m_nonFractional + static_cast<double>(m_fractional)/100;
    }
    bool operator==(const FixedPoint2& fp)
    {
        return (m_fractional==fp.m_fractional) && (m_nonFractional==fp.m_nonFractional);    
    }
    FixedPoint2 operator-() const
    {
        return { 
            static_cast<std::int16_t>(-m_nonFractional), 
            static_cast<std::int8_t>(-m_fractional)
        };
    }
    friend FixedPoint2 operator+(const FixedPoint2& f1, const FixedPoint2& f2)
    {
        return {static_cast<double>(f1)+static_cast<double>(f2)};
    }
private:
    void updateSign()
    {
        if(m_fractional<0 || m_nonFractional<0)
        {
            if(m_nonFractional>0)
                m_nonFractional = -m_nonFractional;
            if(m_fractional>0)
                m_fractional = -m_fractional;
        }
    }
    std::int16_t m_nonFractional{};
    std::int8_t m_fractional{};
};

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}