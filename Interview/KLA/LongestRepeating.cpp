#include<iostream>
#include <vector>

std::string_view longestRepeatedSubstring(std::string_view str)
{
    int n{static_cast<int>(str.length())}, ans_ind{}, ans_len{};
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1));
    for(int i{1};i<=n;i++)
    {
        for(int j{i+1};j<=n;j++)
        {
            if(str[i-1]==str[j-1] && (j-i) > dp[i-1][j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            if(dp[i][j] > ans_len)
            {
                ans_len = dp[i][j];
                ans_ind = i;
            }
        }
    }
    if(ans_len)
        return str.substr(ans_ind-ans_len, ans_len);
    return "";
}

int main()
{
    std::string str{"geeksforgeeks"};
    std::cout << longestRepeatedSubstring(str);
    return 0;
}