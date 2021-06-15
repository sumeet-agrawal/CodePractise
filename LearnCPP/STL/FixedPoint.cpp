#include <iostream>
#include <cmath>

class FixedPoint2
{
public:
	FixedPoint2(std::int16_t nf, std::int8_t f)
		: m_nf(nf)
		, m_f(f)
	{
		if (m_nf < 0 || m_f < 0)
		{
			if (m_nf > 0)
				m_nf = -m_nf;
			if (m_f > 0)
				m_f = -m_f;
		}
	}
	FixedPoint2(double d)
	{
		double temp_d = std::round(d * 100);
		m_nf = static_cast<int>(temp_d / 100);
		m_f = static_cast<int>(temp_d) % 100;
		if (m_nf < 0 || m_f < 0)
		{
			if (m_nf > 0)
				m_nf = -m_nf;
			if (m_f > 0)
				m_f = -m_f;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& num)
	{
		out << (num.m_nf) + (static_cast<double>(num.m_f) / 100);
		return out;
	}
	operator double() const
	{
		return (m_nf)+(static_cast<double>(m_f) / 100);;
	}
	FixedPoint2& operator+(const FixedPoint2& fd)
	{
		double d = (static_cast<double>(m_nf) * 100) + static_cast<double>(m_f)
			+ (static_cast<double>(fd.m_nf) * 100) + static_cast<double>(fd.m_f);
		m_nf = static_cast<std::int16_t>(d / 100);
		m_f = static_cast<int>(d) % 100;
		return *this;
	}
	bool operator==(const FixedPoint2& fd)
	{
		return (m_nf == fd.m_nf) && (m_f == fd.m_f);
	}
	FixedPoint2& operator-()
	{
		m_nf = -m_nf;
		m_f = -m_f;
		return *this;
	}
	friend std::istream& operator>>(std::istream& in, FixedPoint2& fd)
	{
		double d{};
		in >> d;
		fd = FixedPoint2(d);
		return in;
	}
private:
	std::int16_t m_nf{};
	std::int8_t m_f{};
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