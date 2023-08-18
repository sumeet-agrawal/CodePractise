#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>

int main()
{
    std::ifstream f("input.txt");
    std::string str{};
    std::unordered_map<std::string, int> mp{};
    while(f.good())
    {
        f>>str;
        mp[str]++;
    }
    std::priority_queue<std::pair<int, std::string>> q{};
    for(auto &x: mp)
        q.push({x.second, x.first});
    int k{10};
    while(!q.empty() && k--)
    {
        std::cout<<q.top().first<<" "<<q.top().second<<"\n";
        q.pop();
    }
    return 0;
}