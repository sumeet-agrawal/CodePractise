#include <iostream>

int main()
{
    int out{1};
    while(out<=5)
    {
        int in{5};
        while(in>=1)
        {
            if(in>out)
                std::cout<<"  ";
            else
                std::cout<<in<<" ";
            in--;
        }
        std::cout<<"\n";
        out++;
    }
    return 0;
}