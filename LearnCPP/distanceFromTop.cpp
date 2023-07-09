#include <iostream>

double calc(double t, double h)
{
    double g = 9.8;
    return h - (g*t*t)/2.0;
}
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
void calcAndPrint(double h, double t)
{
    printAns(t,calc(t,h));
}
int main()
{
    double h{readHeight()};
    calcAndPrint(h,0);
    calcAndPrint(h,1);
    calcAndPrint(h,2);
    calcAndPrint(h,3);
    calcAndPrint(h,4);
    calcAndPrint(h,5);
    return 0;
}