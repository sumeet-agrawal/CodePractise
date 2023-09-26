#include <iostream>

template<typename T>
class UniquePtr
{
private:
    T* t;
public:
    UniquePtr(T* obj = nullptr)
        : t{obj}
    {}
    ~UniquePtr()
    {
        delete t;
    }
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr(const UniquePtr&) = delete;

    UniquePtr& operator=(UniquePtr&& other)
    {
        t = std::move(other.t);
        other.t = nullptr;
        return *this;
    }
    UniquePtr(UniquePtr&& other)
    {
        t = std::move(other.t);
        other.t = nullptr;
    }
    T& operator*()  {return *t;}
    T* get()    { return t;}
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource";
		return out;
	}
};

void takeOwnership(UniquePtr<Resource> res)
{
     if (res.get())
          std::cout << *res << '\n';
} // the Resource is destroyed here

int main()
{
    UniquePtr<Resource> ptr{ new Resource()};

//    takeOwnership(ptr); // This doesn't work, need to use move semantics
    takeOwnership(std::move(ptr)); // ok: use move semantics

    std::cout << "Ending program\n";

    return 0;
}