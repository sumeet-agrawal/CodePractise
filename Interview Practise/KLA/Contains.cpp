#include <iostream>
#include <unordered_map>

int main()
{
    std::string str{"this is a test string"}, pattern{"tist"};
    std::unordered_map<char, int> mp{};

    for(const auto& x: pattern)
        mp[x]++;
    
    int st{}, en{}, cnt{static_cast<int>(mp.size())}, ans{INT_MAX}, ans_st{};
    while(en<str.length())
    {
        mp[str[en]]--;
        if(!mp[str[en]])
            cnt--;
        while(!cnt)
        {
            if(en-st+1 < ans)
                ans = en-st+1,
                ans_st = st;
            
            mp[str[st]]++;
            if(mp[str[st]]==1)
                cnt++;
            st++;
        }
        en++;
    }
    if(ans!=INT_MAX)
        std::cout<<str.substr(ans_st, ans);
    else
        std::cout<<"String not found\n";
    return 0;
}