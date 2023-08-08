#include <iostream>

int rec(int n)
{
    if(n<=0)
        return 1;
    return n*rec(n-1);
}

int main()
{
    for(int i{1};i<=7;i++)
        std::cout<<rec(i)<<" ";
    std::cout<<"\n";
    return 0;
}