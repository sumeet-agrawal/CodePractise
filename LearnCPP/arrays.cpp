#include <iostream>

int main()
{
    constexpr int div[]{3, 5, 7, 11, 13, 17, 19};
    constexpr std::string_view out[]{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

    for(int i{1}; i<=150; ++i)
    {
        bool flag{};
        for(int j{0}, n = std::size(div); j<n; ++j)
            if(!(i%div[j]))
            {
                flag = true;
                std::cout<<out[j];
            }
        if(!flag)
            std::cout<<i;
        std::cout<<'\n';
    }
    return 0;
}