#include <iostream>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

class LFUCache
{
private:
    int cap{};
    unordered_map<int, int> freq;
    map<int, list<int>> mp;
    unordered_map<int, list<int>::iterator> mpitr;
public:
    LFUCache(int val)
        : cap{val}
    {}
    void replace(int key)
    {
        if(freq.size() < cap)
        {
            if(freq.count(key))
                mp[freq[key]].erase(mpitr[key]);
        }
        else
        {
            if(freq.count(key))
                mp[freq[key]].erase(mpitr[key]);
            else
            {
                int k = *mp.begin()->second.begin();
                mp[freq[k]].erase(mpitr[k]);
                if(!mp[freq[k]].size())
                    mp.erase(freq[k]);
                mpitr.erase(k);
                freq.erase(k);
            }
        }
        freq[key]++;
        mp[freq[key]].push_back(key);
        auto ptr = mp[freq[key]].end();
        mpitr[key] = --ptr;
    }
    void print()
    {
        for(auto &x: freq)
            cout<<"["<<x.first<<","<<x.second<<"] ";
        cout<<"\n";
    }
};

int main()
{
    LFUCache ch(3);
    ch.replace(1);
    ch.replace(2);
    ch.replace(3);
    ch.replace(4);
    ch.replace(2);
    ch.replace(5);
    ch.print();
    return 0;
}