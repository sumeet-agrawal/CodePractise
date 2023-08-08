#include<iostream>

int main()
{
    std::string_view arr[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::cout<<"Enter a name: ";
    std::string str;
    std::cin>>str;
    bool found{};
    for(auto &x: arr)
        if(x==str)
        {
            found = true;
            break;
        }
    std::cout<<str;
    if(found)
        std::cout<<" was found.\n";
    else
        std::cout<<" was not found.\n";
    return 0;
}