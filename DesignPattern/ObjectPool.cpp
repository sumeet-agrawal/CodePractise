#include <string>
#include <iostream>
#include <list>
#include <memory>

class Resource
{
private:
    int value{ 0 };
public:
    Resource()
    {}
    void reset()
    {
        value = 0;
    }
    int getValue() const
    {
        return value;
    }
    void setValue(int number)
    {
        value = number;
    }
};

/* Note, that this class is a singleton. */
class ObjectPool
{
private:
    std::list<Resource*> resources;

    static ObjectPool* instance;
    ObjectPool() {}
public:
    ~ObjectPool()
    {
        std::cout << "Destroying pool\n";
        while (!resources.empty())
        {
            Resource* obj = resources.front();
            resources.pop_front();
            delete obj;
            obj = nullptr;
        }
        resources.clear();
        instance = nullptr;
    }
    static ObjectPool* getInstance()
    {
        if (!instance)
        {
            instance = new ObjectPool;
        }
        return instance;
    }
    Resource* getResource()
    {
        if (resources.empty())
        {
            std::cout << "Creating new." << std::endl;
            return new Resource;
        }
        else
        {
            std::cout << "Reusing existing." << std::endl;
            Resource* resource = resources.front();
            resources.pop_front();
            return resource;
        }
    }
    void returnResource(Resource* object)
    {
        object->reset();
        resources.push_back(object);
    }
};
ObjectPool* ObjectPool::instance = nullptr;
int main()
{
    std::unique_ptr<ObjectPool> pool{ ObjectPool::getInstance() };
    Resource* one;
    Resource* two;
    /* Resources will be created. */
    one = pool->getResource();
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
    two = pool->getResource();
    two->setValue(20);
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
    pool->returnResource(one);
    pool->returnResource(two);
    /* Resources will be reused.
     * Notice that the value of both resources were reset back to zero.
     */
    one = pool->getResource();
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
    two = pool->getResource();
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    return 0;
}