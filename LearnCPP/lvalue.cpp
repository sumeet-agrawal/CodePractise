#include <iostream>

int main()
{
    int* number{(int*)0x46329};
    std::cout<<*number;
    return 0;
}