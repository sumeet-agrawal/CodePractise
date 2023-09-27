#include <iostream>

using namespace std;

class Counter
{
private:
    int cnt{};
public:
    Counter() = default;
    ~Counter() = default;

    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    Counter(Counter&&) = delete;
    Counter& operator=(Counter&&) = delete;

    int getCount() const { return cnt;}
    Counter& operator++() { cnt++; return *this;}
    Counter& operator--() { cnt--; return *this;}
};

template <typename T>
class SharedPtr
{
private:
    Counter* cntr{};
    T* ptr{};
public:
    explicit SharedPtr(T* res)
        : ptr{res}
        , cntr{new Counter()}
    {
        ++(*cntr);
    }
    ~SharedPtr()
    {
        --(*cntr);
        if(cntr->getCount())
            return;
        delete ptr;
        delete cntr;
    }
    SharedPtr(const SharedPtr& sptr)
        : ptr{sptr.ptr}
        , cntr{sptr.cntr}
    {
        ++(*cntr);
    }
    SharedPtr& operator=(const SharedPtr& sptr)
    {
        if(ptr == sptr.ptr)
            return *this;
        ptr = sptr.ptr;
        cntr = sptr.cntr;
        ++(*cntr);
        return *this;
    }
    T* operator->() { return ptr;}
    T& operator*() { return *ptr;}
    void printCount() { cout<<cntr->getCount()<<"\n";}
    T* get() const { return ptr;}
};

template <typename T>
class WeakPtr
{
private:
    T* ptr{};
public:
    WeakPtr(const SharedPtr<T>& sptr)
        : ptr{sptr.get()}
    {}
    WeakPtr& operator=(const SharedPtr<T>& sptr)
    {
        if(ptr == sptr.get())
            return *this;
        ptr = sptr.get();
        return *this;
    }
    WeakPtr(const WeakPtr& wptr)
        : ptr{wptr.ptr}
    {}
    WeakPtr& operator=(const WeakPtr& wptr)
    {
        if(ptr == wptr.ptr)
            return *this;
        ptr = wptr.ptr;
        return *this;
    }
    T* operator->() { return ptr;}
    T& operator*() { return *ptr;}
};

class Resource
{
private:
    static int getP() 
    { 
        static int n{};
        return ++n;
    }
public:
    void print()    { cout<<"Hello World "<<getP()<<"\n";}
    Resource() { cout<<"Resource created\n";}
    ~Resource(){ cout<<"Resource destroyed\n";}
};

int main()
{
    SharedPtr<Resource> sptr(new Resource());
    {
        WeakPtr<Resource> wptr{sptr};
        wptr->print();
        sptr.printCount();
        wptr->print();
    }
    cout<<"Here\n";
    {
        SharedPtr<Resource> nptr{sptr};
        nptr.printCount();
    }
    sptr->print();
    sptr.printCount();
    (*sptr).print();
    return 0;
}