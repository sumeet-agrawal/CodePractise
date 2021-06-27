#include <string>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>

class Database
{
private:
    int connection{ 0 };
public:
    Database()
        : connection(1)
    {}
    ~Database()
    {
        connection = 0;
    }
    int getValue() const
    {
        return connection;
    }
    void executeQuery(const std::string& str)
    {
        std::cout << "Following query is excuting\n";
        std::cout << str << "\n";
    }
};

/* Note, that this class is a singleton. */
class ObjectPool
{
private:
    Database* db{ nullptr };
    std::mutex mt;
    std::condition_variable cv;
    bool isConnected{ true };

    static ObjectPool* instance;
    ObjectPool() {}
public:
    ~ObjectPool()
    {
        std::cout << "Destroying pool\n";
        delete db;
        db = nullptr;
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
    Database* getConnection()
    {
        std::unique_lock<std::mutex> lock(mt);
        while (!isConnected)
        {
            cv.wait(lock);
        }
        if (!db)
            db = new Database;
        isConnected = true;
        return db;
    }
    void returnResource(Database* object)
    {
        isConnected = false;
        cv.notify_all();
    }
};
ObjectPool* ObjectPool::instance = nullptr;
int main()
{
    std::unique_ptr<ObjectPool> pool{ ObjectPool::getInstance() };
    Database* db = pool->getConnection();
    db->executeQuery("Insert into bookmarks where url = '' && user_id = ''");
    return 0;
}