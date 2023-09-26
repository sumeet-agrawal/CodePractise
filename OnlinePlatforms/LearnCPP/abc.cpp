#include <iostream>

class Counter
{
private:
    int cnt{};
public:
    Counter() = default;
    ~Counter() = default;
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    Counter& operator++()
    {
        cnt++;
        return *this;
    }
    Counter& operator--()
    {
        cnt--;
        return *this;
    }
    int get() const { return cnt;}
};

template <typename T>
class SharedPtr
{
private:
    T* ptr{};
    Counter* cntr{};
public:
    SharedPtr(T* t)
        : ptr{t}
    {
        cntr = new Counter();
        ++(*cntr);
    }
    SharedPtr(const SharedPtr& sptr)
        : ptr{sptr.ptr}
        , cntr{sptr.cntr}
    {
        ++(*cntr);
    }
    SharedPtr& operator=(const SharedPtr& sptr)
    {
        ptr = sptr.ptr;
        cntr = sptr.cntr;
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
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
};
