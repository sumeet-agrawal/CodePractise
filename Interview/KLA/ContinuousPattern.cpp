#include <iostream>

std::pair<std::string, int> calc(std::string str)
{
    int n = str.length();
    bool flag{};
    for(int i{1};i<=n;i++)
    {
        flag = false;
        for(int j{i};j<n;j+=i)
        {
            for(int k{};k<i;k++)
            {
                if(str[k]!=str[j+k])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            return {str.substr(0, i), i};
    }
    return {};
}

int main()
{
    auto t = calc("aabaabaab");
    std::cout<<t.first<<" "<<t.second<<"\n";
    return 0;
}