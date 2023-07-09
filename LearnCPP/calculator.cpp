#include <iostream>
using namespace std;

double read()
{
    double x{};
    cout<<"Enter a double value: ";
    cin>>x;
    return x;
}

char symbol()
{
    char ch;
    cout<<"Enter one of the following: +, -, *, or /: ";
    cin>>ch;
    return ch;
}

void evaluate(double x, double y, char operation)
{
    if (operation == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (operation == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (operation == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (operation == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
    double x{read()}, y{read()};
    char ch{symbol()};
    evaluate(x, y, ch);
    return 0;
}