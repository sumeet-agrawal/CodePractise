#include <iostream>

int readNumber()
{
	int x{};
	std::cout<<"Enter number : ";
	std::cin>>x;
	return x;
}

void writeAnswer(int x)
{
	std::cout<<"Sum is "<<x<<"\n";
}