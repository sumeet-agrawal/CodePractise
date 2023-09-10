#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int SIZEOF(T& t)
{
    return (char*)(&t +1) - (char*)(&t);
}

struct Abc
{
    int a;
    double b;
    char c;
    string d;
    vector<int> e;
};

int main()
{
    Abc abc[5];
    cout<<SIZEOF(abc)<<"\n";
    return 0;
}