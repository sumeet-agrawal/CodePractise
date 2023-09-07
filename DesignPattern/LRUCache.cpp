#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    list<int> cache;
    unordered_map<int, list<int>::iterator> mp;
    int cap{};
public:
    LRUCache(int val)
        : cap{val}
    {}
    void replace(int key)
    {
        if(cache.size() == cap)
        {
            if(mp.count(key))
                cache.erase(mp[key]);
            else
                mp.erase(cache.front()),
                cache.erase(cache.begin());
        }
        cache.push_back(key);
        mp[key] = --cache.end();
    }
    void print()
    {
        for(auto x: cache)
            cout<<x<<" ";
        cout<<"\n";
    }
};

int main()
{
    LRUCache ch(3);
    ch.replace(1);
    ch.replace(2);
    ch.replace(3);
    ch.replace(4);
    ch.replace(2);
    ch.replace(5);
    ch.print();

    return 0;
}