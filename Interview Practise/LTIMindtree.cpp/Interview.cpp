#include <iostream>

using namespace std;


class Abc
{
private:
    int* a;
    int size;
public:
    /*Abc(int n)
        : a{n}
    {}*/
    Abc(const Abc& abc)
    {
        size = abc.size;
        a = new int(abc.size);
        for(int i{};i<size;i++)
            a[i] = abc.a[i];
    }
    int operator++()
    {
        a++;
        return a;
    }
    void print()
    {
        cout<<a<<"\n";
    }
};

template<typename T>
T add(const T& a, const T& b)
{
    return a+b;
}

class A
{

};

struct Node
{
    int val;
    Node* next;
    Node(int n): val{n}{}
};

void insert(int pos, int val, Node* head)
{
    Node* itr{head}, *prev{};
    int i{};
    while(itr && i<pos)
    {
        i++;
        prev = itr;
        itr = itr->next;
    }
    prev->next = new Node(val);
    prev->next->next = itr;
}

int main()
{
    vector<Shape> vec;
    vec.push_back(new Circle());
    vec[0]->printArea();
    int arr[] = {1, 5 , 7, 8, 12};
    int a{INT_MIN}, b{INT_MIN};
    for(auto x: arr)
    {
        if(x>a)
            b = a, a = x;
        else if(x>b)
            b = x;
    }
    cout<<b<<"\n";
    return 0;
}