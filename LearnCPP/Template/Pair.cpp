#include <iostream>

template<typename T, typename S>
class Pair
{
public:
    Pair(const T& x, const S& y)
        : m_first{x}
        , m_second{y}
    {}
    T& first() { return m_first;}
    S& second() { return m_second;}
    const T& first() const { return m_first;}
    const S& second() const { return m_second;}
private:
    T m_first{};
    S m_second{};
};

template<typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
    StringValuePair(std::string_view s, const S& x)
        : Pair<std::string, S>{static_cast<std::string>(s), x}
    {}
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}