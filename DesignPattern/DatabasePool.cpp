#include <string>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>
#include <condition_variable>

class Database
{
private:
    int connection{ 0 };
public:
    Database()
        : connection{1}
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
    bool isConnected{ false };

    ObjectPool() {}
public:
    ~ObjectPool()
    {
        std::cout << "Destroying pool\n";
        delete db;
        db = nullptr;
    }
    static ObjectPool* getInstance()
    {
        static ObjectPool* instance = new ObjectPool();
        return instance;
    }
    Database* getConnection()
    {
        std::unique_lock<std::mutex> lock(mt);
        cv.wait(lock, [&](){return !isConnected;});
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
int main()
{
    Database* db = ObjectPool::getInstance()->getConnection();
    db->executeQuery("Insert into bookmarks where url = '' && user_id = ''");
    ObjectPool::getInstance()->returnResource(db);
    return 0;
}