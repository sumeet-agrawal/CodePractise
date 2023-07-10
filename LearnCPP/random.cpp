#include <iostream>
#include <unordered_map>
#include <random>

int main()
{
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution ran{ 0, 9 };
    std::unordered_map<int, int> mp;
    for(int i{};i<1000000;i++)
        mp[ran(mt)]++;
    for(auto &x: mp)
        std::cout<<x.second<<" ";
    std::cout<<"\n";

    return 0;
}