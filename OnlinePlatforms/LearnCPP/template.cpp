#include <iostream>

template<typename T>
T add(T x, T y)
{
    return x+y;
}

template<typename T, typename S>
T mult(T x, S y)
{
    return x*y;
}

auto sub(auto x, auto y)
{
    return x-y;
}

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}