#include <iostream>
#include <functional>

using namespace std;

int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}

int main()
{
    function<int(int, int)> func;
    //int (*func)(int, int);
    bool flag{true};
    if(flag)
        func = add;
    else
        func = sub;
    int a{2}, b{3};
    cout<<func(a, b);
    return 0;
}