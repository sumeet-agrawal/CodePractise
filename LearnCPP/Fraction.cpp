#include <iostream>

struct Fraction
{
    int numerator{ 0 };
    int denominator{ 1 };
};

void getFraction(Fraction &f)
{
    std::cout << "Enter a value for numerator: ";
    std::cin >> f.numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> f.denominator;
    std::cout << '\n';
}

Fraction multiply(const Fraction& f1, const Fraction& f2)
{
    return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
}

void printFraction(const Fraction& f)
{
    std::cout << f.numerator << '/' << f.denominator << '\n';
}

int main()
{
    Fraction f1{};
    getFraction(f1);
    Fraction f2{};
    getFraction(f2);

    std::cout << "Your fractions multiplied together: ";

    printFraction(multiply(f1, f2));

    return 0;
}