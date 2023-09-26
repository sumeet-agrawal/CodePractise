#include <iostream>

using namespace std;

class Counter
{
private:
    int m_counter{};
public:
    Counter() = default;
    ~Counter() = default;
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    Counter& operator++()   { m_counter++;  return *this;}
    Counter& operator--()   { m_counter--;  return *this;}
    int get() const { return m_counter;}
};

template <typename T>
class SharedPtr
{
private:
    T* ptr{};
    Counter* cntr{};
public:
    SharedPtr(T* t = nullptr)
        : ptr{t}
        , cntr{new Counter()}
    {
        ++(*cntr);
    }
    ~SharedPtr()
    {
        --(*cntr);
        if(cntr->get())
            return;
        delete ptr;
        delete cntr;
    }
    SharedPtr(const SharedPtr& p)
    {
        ptr = p.ptr;
        cntr = p.cntr;
        ++(*cntr);
    }
    SharedPtr& operator=(const SharedPtr& p)
    {
        ptr = p.ptr;
        cntr = p.cntr;
        ++(*cntr);
        return *this;
    }
    int getCount() const     { return cntr->get();}
};

class Resource
{
public:
    Resource()  { cout<<"Resource Allocated\n";}
    ~Resource()  { cout<<"Resource De-allocated\n";}
};

int main()
{
    SharedPtr<Resource> ptr1(new Resource());
    cout<<"Counter: "<<ptr1.getCount()<<"\n";
    {
        SharedPtr<Resource> ptr2 = ptr1;
        cout<<"Counter: "<<ptr2.getCount()<<"\n";
    }
    cout<<"Counter: "<<ptr1.getCount()<<"\n";
    return 0;
}