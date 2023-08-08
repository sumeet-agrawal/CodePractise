#include <iostream>

struct Foo1
{
    short a{}; // will have 2 bytes of padding after a
    
    short c{}; // will have 2 bytes of padding after c
    int b{};
};

struct Foo2
{
    int b{};
    short a{};
    short c{};
};

int main()
{
    std::cout << sizeof(Foo1) << '\n'; // prints 12
    std::cout << sizeof(Foo2) << '\n'; // prints 8

    return 0;
}