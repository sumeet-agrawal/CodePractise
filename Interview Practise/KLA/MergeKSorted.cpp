#include <iostream>
#include <queue>
#include <vector>

std::vector<int> mergeKArrays(const std::vector<std::vector<int>>& arr)
{
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> q;
    for(int i{};i<arr.size();i++)
        q.push({arr[i][0], i, 0});
    std::vector<int> ans;
    while(!q.empty())
    {
        auto t = q.top();
        ans.push_back(t[0]);
        q.pop();
        if(t[2]+1<arr[t[1]].size())
            q.push({arr[t[1]][t[2]+1], t[1], t[2]+1});
    }
    return ans;
}

void printArray(const std::vector<int>& arr)
{
    for(const auto &x: arr)
        std::cout<<x<<' ';
    std::cout<<'\n';
}

int main()
{
    // Change N at the top to change number of elements
    // in an array
    std::vector<std::vector<int>> arr = { { 2, 6, 12, 34 },
                     { 1, 9, 20, 1000 },
                     { 23, 34, 90, 2000 } };
    
    std::cout << "Merged array is \n";
    printArray(mergeKArrays(arr));
  
    return 0;
}