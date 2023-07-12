#include <iostream>

void rec(unsigned int n)
{
    if(n==0)
        return;
    rec(n/2);
    std::cout<<(n&1);
}

int main()
{
    int input{};
    std::cin>>input;
    rec(static_cast<unsigned int>(input));
    return 0;
}