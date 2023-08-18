#include <functional>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

int main()
{
    std::unordered_map<int, int> mp;
    std::function<bool(int ,int)> comp { [&](int a, int b){
        if(mp[a]!=mp[b])
            return mp[a]>mp[b];
        // there is something extremely wrong when mp[a]==mp[b]
        return false;
    }};
    std::map<int, int, std::function<bool(int ,int)>> mpr(comp);
    std::vector<int> arr{6,6,7,2,-6,6,7,6,-2,2,7,2,2,2,2,2,7, 6,6, 7,7,7,7,7,-7,-7,-7,-7,6, -6, -6, -6,-6};
    for(auto &x: arr)
    {
        if(x>0)
        {
            mp[x]++;
            mpr[x] = mp[x];
        }
        else{
            mp[-x]--;
            mpr[-x] = mp[-x];
        }
        for(auto &x: mp)
            std::cout<<x.first<<" "<<x.second<<" ";
        std::cout<<"||||";
        for(auto &x: mpr)
            std::cout<<x.first<<" "<<x.second<<" ";
        std::cout<<"\n";

    }
    return 0;
}