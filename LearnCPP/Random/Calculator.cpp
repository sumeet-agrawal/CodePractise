#include <iostream>
#include <functional>

using ArithematicFunction = std::function<int(int, int)>;

int getInteger()
{
	int num{};
	std::cout << "Enter number : ";
	std::cin >> num;
	return num;
}

char getOperator()
{
	char ch{};
	do
	{
		std::cout << "Enter operator(+,-,*,/) : ";
		std::cin >> ch;
	} while ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/'));
	return ch;
}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	return a / b;
}

ArithematicFunction getArithmeticFucntion(char ch)
{
	switch (ch)
	{
	default:
	case '+':
		return &add;
	case '-':
		return &subtract;
	case '*':
		return &multiply;
	case '/':
		return &division;
	}
}

int main()
{
	int a{ getInteger() };
	char ch{ getOperator() };
	int b{ getInteger() };

	int out = getArithmeticFucntion(ch)(a, b);

	std::cout << "Answer is : " << out << "\n";
	return 0;
}