#include <iostream>

template<typename T>
struct Triad
{
    T a{};
    T b{};
    T c{};
};

template<typename T>
void print(const Triad<T> &t)
{
    std::cout<<"["<<t.a<<", "<<t.b<<", "<<t.c<<"]";
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}