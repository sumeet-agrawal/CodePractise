#include <iostream>
#include "constants.hpp"

double readHeight()
{
    double h{};
    std::cout<<"Enter the height of the tower in meters: ";
    std::cin>>h;
    return h;
}
void printAns(double t, double h)
{
    if(h>0)
        std::cout<<"At "<<t<<" seconds, the ball is at height: "<<h<<" meters\n";
    else
        std::cout<<"At "<<t<<" seconds, the ball is on the ground.\n";
}

void calcAndPrint(double h)
{
    double r{h}, t{};
    while(r>0)
    {
        r = h - (myConstants::gravity*t*t)/2.0;
        printAns(t, r);
        t++;
    }
}

int main()
{
    double h{readHeight()};
    calcAndPrint(h);
    return 0;
}