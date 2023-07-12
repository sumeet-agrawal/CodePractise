#include <iostream>
#include <functional>

int read()
{
    std::cout<<"Enter a integer :";
    int input{};
    std::cin>>input;
    return input;
}
char operation()
{
    char op{' '};
    while (op!='+' && op!='-' && op!='*' && op!='/')
    {
        std::cout<<"Enter a operation + - * / :";
        std::cin>>op;
    }
    return op;
}
int add(int x, int y) { return x+y;}
int subtract(int x, int y) { return x-y;}
int multiply(int x, int y) { return x*y;}
int divide(int x, int y) { return x/y;}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
    switch(op)
    {
        case '+' : return &add;
        case '-' : return &subtract;
        case '*' : return &multiply;
        case '/' : return &divide;
    }
    return nullptr;
}
int main()
{
    int a{read()}, b{read()};
    ArithmeticFunction func{getArithmeticFunction(operation())};
    std::cout<<func(a, b);
    return 0;
}