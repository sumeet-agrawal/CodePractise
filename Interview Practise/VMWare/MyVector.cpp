#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T>
class Vector
{
private:
    T* arr;
    int size{};
    int cur{};
public:
    Vector()
        : size{1}
    {
        arr = new T[1];
    }
    Vector(int sz)
        : size{sz}
    {
        arr = new T[sz];
    }
    Vector(initializer_list<T> lt)
    {
        arr = new T[size = lt.size()];
        for(auto &x: lt)
            arr[cur++] = x;
    }
    ~Vector()
    {
        delete[] arr;
    }
    void push_back(T a)
    {
        if(cur < size)
        {
            arr[cur++] = a;
            return;
        }
        T* temp = new T[size *= 2];
        for(int i{};i<cur;i++)
            temp[i] = arr[i];
        
        delete[] arr;
        arr = temp;
        arr[cur++] = a;
    }
    void pop_back()
    {
        if(cur>0)
            cur--;
    }
    void insert(int a, T ind)
    {
        int i{cur};
        while(i>ind)
            arr[i] = arr[i-1],
            i--;
        arr[ind] = a;
    }
    T& operator[](const int& ind)
    {
        if(ind>=cur)
        {
            cout<<"Array index out of bound\n";
            exit(0);
        }
        return arr[ind];
    }
    friend ostream& operator<<(ostream& out, const Vector<T>& ar)
    {
        out<<"[";
        for(int i{};i<ar.cur;i++)
            out<<ar.arr[i]<<", ";
        out<<"]";
        return out; 
    }
    int currentSize()  const { return cur;}
    int sz() const { return size;}
    void resize(int a)
    {
        if(a>size)
        {
            T* temp = new T[a];
            for(int i{};i<cur;i++)
                temp[i] = arr[i];
            
            delete[] arr;
            arr = temp;
        }
        else if(a<cur)
            cur = a;
    }
    T* begin()  { return arr;}
    T* end()    { return arr+cur;}
};

int main()
{
    Vector<int> vec{1, 3, 4, 5, 7, 10};
    cout<<vec<<"\n";
    vec[3] = 100;
    cout<<vec<<"\n";
    Vector<string> arr{"Sumeet", "Mohit", "Sunil", "Sunita", "Sheetal"};
    cout<<arr.sz()<<" "<<arr.currentSize()<<"\n";
    arr.push_back("Jayesh");
    arr.resize(3);
    cout<<arr.sz()<<" "<<arr.currentSize()<<"\n";
    cout<<arr<<"\n";
    for(auto itr = arr.begin();itr != arr.end();itr++)
        cout<<*itr<<" ";
    cout<<"\n";
    for(auto &x: arr)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}