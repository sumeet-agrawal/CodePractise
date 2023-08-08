#include <cstdint>
#include <iostream>

class RGBA
{
public: 
    using Channel = std::uint8_t;
private:
    Channel m_red{};
    Channel m_green{};
    Channel m_blue{};
    Channel m_alpha{};
public:
    RGBA(Channel r=0, Channel g=0, Channel b=0, Channel a=255)
        : m_red{r}
        , m_green{g}
        , m_blue{b}
        , m_alpha{a}
    {}
    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red)
			<< " g=" << static_cast<int>(m_green)
			<< " b=" << static_cast<int>(m_blue)
			<< " a=" << static_cast<int>(m_alpha)
			<< '\n';
    }
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}