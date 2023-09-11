#include <iostream>

using namespace std;

class A
{
protected:
    string name;
public:
    A(string_view sv)
        : name{sv}
    {}
};
class B: public A
{
public:
    B(string_view sv)
        : A(sv)
    {}
    void print()
    {
        cout<<name<<"\n";
    }
};

int main()
{
    B b("Sumeet");
    b.print();
    return 0;
}