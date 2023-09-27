#include <initializer_list>
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Vector
{
private:
    int capacity{};
    T* arr{};
    int en{};
public:
    Vector(int sz)
        : capacity{sz}
        , arr{new T[sz]}
        , en{sz}
    {}
    Vector()
        : Vector(1)
    {
        en = 0;
    }
    Vector(const initializer_list<T>& lt)
        : Vector(lt.size())
    {
        en = 0;
        for(auto& x: lt)
            arr[en++] = x;
    }
    Vector(Vector&& vec)
        : capacity{vec.capacity}
        , en{vec.en}
        , arr{move(vec.arr)}
    {}
    Vector& operator=(Vector&& vec)
    {
        delete[] arr;
        capacity = vec.capacity;
        en = vec.en;
        arr = move(vec.arr);
        return *this;
    }
    Vector(const Vector& vec)
        : Vector(vec.size())
    {
        memcpy(arr, vec.arr, vec.size()*sizeof(T));
    }
    Vector& operator=(const Vector& vec)
    {
        if(arr == vec.arr)
            return *this;
        if(size() < vec.size())
        {
            delete[] arr;
            T* temp = new T[capacity = vec.size()];
            arr = temp;
        }
        memcpy(arr, vec.arr, vec.size()*sizeof(T));
        en = vec.size();
        return *this;
    }
    Vector& operator=(const initializer_list<T>& lt)
    {
        delete[] arr;
        T* temp = new T[capacity = lt.size()];
        arr = temp;
        en = 0;
        for(auto x: lt)
            arr[en++] = x;
        return *this;
    }
    ~Vector()
    {
        delete[] arr;
    }
    void push_back(T val)
    {
        if(en<capacity)
        {
            arr[en++] = val;
            return;
        }
        T* temp = new T[capacity *= 2];
        memcpy(temp, arr, sizeof(T)*size());
        delete[] arr;
        arr = temp;
        arr[en++] = val;
    }
    void pop_back()
    {
        if(en)
            en--;
    }
    void resize(int nSize)
    {
        if(nSize<=capacity)
            return;
        T* temp = new T[capacity = nSize];
        memcpy(temp, arr, size()*sizeof(T));
        delete[] arr;
        arr = temp;
        en = nSize;
    }
    int size() const { return en;}
    int memSize() const { return capacity;}
    T* begin() const { return arr;}
    T* end() const { return arr+en;}
    T& operator[](const int ind)
    {
        assert((ind<en) && "Array index out of bounds");
        return arr[ind];
    }
    friend ostream& operator<<(ostream& out, const Vector<T>& ar)
    {
        out<<"[";
        for(auto& x: ar)
            out<<x<<", ";
        out<<"]";
        return out; 
    }
};

int main()
{
    Vector<int> vec({1,2,3,4,5});
    Vector<int> arr(vec);
    cout<<vec<<"\n";
    arr.push_back(6);
    cout<<arr<<"\n";
    return 0;
}