#include <iostream>

class Counter
{
private:
    unsigned int m_counter{};
public:
    Counter()
        : m_counter{}
    {}
    ~Counter()  {}
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    void operator++(){m_counter++;}
    void operator++(int){m_counter++;}
    void operator--(){m_counter--;}
    void operator--(int){m_counter--;}
    int get() { return m_counter;}
};

template<typename T>
class SharedPtr
{
private:
    T* t{};
    Counter* m_counter{};
public:
    explicit SharedPtr(T* obj = nullptr)
        : t{obj}
    {
        m_counter = new Counter();
        (*m_counter)++;
    }
    SharedPtr(SharedPtr& ptr)
    {
        t = ptr.t;
        m_counter = ptr.m_counter;
        (*m_counter)++;
    }
    ~SharedPtr()
    {
        (*m_counter)--;
        if(!m_counter->get())
        {
            delete t;
            delete m_counter;
        }
    }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Resource* res { new Resource };
	SharedPtr<Resource> ptr1 { res };
	{
		SharedPtr<Resource> ptr2 { res }; // create ptr2 directly from res (instead of ptr1)

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, and the allocated Resource is destroyed

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed again