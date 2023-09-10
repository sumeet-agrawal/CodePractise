#include <iostream>
#include <vector>

using namespace std;

int cnt{};

int count(int n, vector<int>& dp)
{
    cnt++;
    if(n<=2)
        return n;
    if(dp[n])
        return dp[n];
    return dp[n] = count(n-1, dp)+count(n-2, dp);
}

int main()
{
    int n = 10;
    vector<int> dp(n+1, 0);
    cout<<count(n, dp)<<" "<<cnt<<"\n";
    return 0;
}