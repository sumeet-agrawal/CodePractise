#include <iostream>
#include <list>
#include <unordered_map>
#include <mutex>

using namespace std;

class LRUCache
{
private:
    list<int> cache;
    unordered_map<int, list<int>::iterator> mp;
    int cap{};
    mutex mtx;
public:
    LRUCache(int val)
        : cap{val}
    {}
    void replace(int val)
    {
        lock_guard<mutex> lg(mtx);
        if(mp.count(val))
            cache.erase(mp[val]);
        else if(cache.size() >= cap)
            mp.erase(cache.back()),
            cache.pop_back();
        cache.push_front(val);
        mp[val] = cache.begin();
    }
};