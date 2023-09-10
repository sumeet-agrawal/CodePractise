#include <iostream>

using namespace std;

void swapp(int& a, int& b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

int main()
{
    int a{5}, b{8};
    cout<<a<<" "<<b<<"\n";
    swapp(a,b);
    cout<<a<<" "<<b<<"\n";
    return 0;
}