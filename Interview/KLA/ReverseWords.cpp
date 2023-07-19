#include <iostream>
#include <algorithm>

std::string_view reverseWords(std::string str)
{
    std::reverse(str.begin(), str.end());
    int i{}, j{}, n = str.length();
    while(str[i]==' ')
        i++;
    j=i;
    while(i<n)
    {
        if(i+1==n || str[i]==' ')
        {
            if(j<i)
                std::reverse(str.begin()+j, str.begin()+i);
            j = i+1;
        }
        i++;
    }
    return str;
}

int main()
{
    std::string s{"i like this program very much"};
    std::cout<<reverseWords(s)<<"\n";
    return 0;
}