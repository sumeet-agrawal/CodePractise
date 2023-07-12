#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using Numbers = std::vector<int>;

namespace config
{
    constexpr int min_random{2};
    constexpr int max_random{4};
    constexpr int abs_difference{4};
}

int getStartingPosition()
{
    int start{};
    std::cout<<"Start where? ";
    std::cin>>start;
    return start;
}
int getTotalCount()
{
    int total{};
    std::cout<<"How many? ";
    std::cin>>total;
    return total;
}
int getRandom(int min, int max)
{
    static std::mt19937_64 mt{static_cast<std::mt19937_64::result_type>
                                (std::chrono::steady_clock::now().time_since_epoch().count())};
    return std::uniform_int_distribution{min, max}(mt);
}

Numbers generateVector()
{
    int start{getStartingPosition()};
    int total{getTotalCount()};
    int ran{getRandom(config::min_random, config::max_random)};

    Numbers vec(total);

    for(int i{};i<total;i++, start++)
        vec[i] = start*start*ran;
    
    std::cout<<"I generated "<<total<<" square numbers. "
                    "Do you know what each number is after multiplying it by "<<ran<<"?\n";
    return vec;
}
int guess()
{
    std::cout<<"> ";
    int n{};
    std::cin>>n;
    return n;
}
bool findAndRemove(Numbers& vec, int n)
{
    auto pos = std::find(vec.begin(), vec.end(), n);
    if(pos!=vec.end())
    {
        vec.erase(pos);
        return true;
    }
    return false;
}
void printSuccess(int size)
{
    if(size)
        std::cout<<"Nice! "<<size<<" number(s) left.\n";
    else
        std::cout<<"Nice! You found all numbers, good job!\n";
}
void printFailure(int closest, int n)
{
    if(std::abs(closest-n)<=config::abs_difference)
        std::cout<<n<<" is wrong! Try "<<closest<<" next time.\n";
    else
        std::cout<<n<<" is wrong!\n";
}
int findClosest(Numbers& vec, int n)
{
    return *std::min_element(vec.begin(), vec.end(), [n](int a, int b)
    {
        return std::abs(n-a)<std::abs(n-b);
    });
}
bool play(Numbers& vec)
{
    int n{guess()};
    if(findAndRemove(vec, n))
    {
        printSuccess(vec.size());
        return vec.size();
    }
    else
    {
        int closest{findClosest(vec, n)};
        printFailure(closest, n);
        return false;
    }
}

int main()
{
    Numbers vec{generateVector()};

    while(play(vec));

    return 0;
}