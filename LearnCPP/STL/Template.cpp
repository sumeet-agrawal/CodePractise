#include <iostream>
#include <string>

template<class T>
class Pair1
{
public:
	Pair1(const T& a, const T& b)
		: m_a(a)
		, m_b(b)
	{}
	const T& first() const { return m_a; }
	const T& second() const { return m_b; }
private:
	T m_a;
	T m_b;
};

template<class T1, class T2>
class Pair
{
public:
	Pair(const T1& a, const T2& b)
		: m_a(a)
		, m_b(b)
	{}
	const T1& first() const { return m_a; }
	const T2& second() const { return m_b; }
private:
	T1 m_a;
	T2 m_b;
};

template<class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& str, const T& t)
		: Pair<std::string, T>(str, t)
	{}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}