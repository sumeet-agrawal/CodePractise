#include <iostream>

class IntPair
{
private:
    int m_first{};
    int m_second{};
public:
    IntPair(){}
    IntPair(int a, int b)
        : m_first{a}
        , m_second{b}
    {}
    void set(int a, int b)
    {
        m_first = a;
        m_second = b;
    }
    void print()
    {
        std::cout<<"Pair("<<m_first<<", "<<m_second<<")\n";
    }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}