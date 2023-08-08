#include <iostream>

int main()
{
    int smaller{}, larger{};
    std::cout<<"Enter an integer: ";
    std::cin>>smaller;
    std::cout<<"Enter a larger integer: ";
    std::cin>>larger;
    if(smaller>larger)
    {
        std::cout<<"Swapping the values\n";
        std::swap(smaller, larger);
    }
    std::cout<<"The smaller value is "<<smaller<<"\nThe larger value is "<<larger<<"\n";

    return 0;
}