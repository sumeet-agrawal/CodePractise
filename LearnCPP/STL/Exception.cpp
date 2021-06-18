#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	int m_n;
	int m_d;
public:
	Fraction(int n = 0, int d = 1)
		: m_n(n)
		, m_d(d)
	{
		if (d == 0)
			throw std::runtime_error("Denominator is 0");
	}
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
	{
		out << "Fraction(" << f.m_n << "/" << f.m_d << ")";
		return out;
	}
};

int main()
{
	int a{}, b{};
	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;

	try
	{
		Fraction f{ a,b };
		std::cout << f << "\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "Invalid Fraction " << ex.what();
	}
	return 0;
}