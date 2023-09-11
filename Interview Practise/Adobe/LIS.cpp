#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int>& arr)
{
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = 1;
    for(int i{1};i<n;i++)
        for(int j{};j<i;j++)
            if(arr[i]>arr[j] && dp[i]<dp[j]+1)
                dp[i] = dp[j]+1;
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> arr{ 3, 10, 2, 1, 20 };
    cout<<lis(arr)<<"\n";
    return 0;
}