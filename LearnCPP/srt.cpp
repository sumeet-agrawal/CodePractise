#include <iostream>

int main()
{
    int arr[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int n{ static_cast<int>(std::size(arr)) };

    for(int i{n-1};i>=0;i--)
        for(int j{};j<i;j++)
            if(arr[j]>arr[j+1])
                std::swap(arr[j], arr[j+1]);

    for(int i{0};i<n;i++)
        std::cout<<arr[i]<<" ";
    std::cout<<"\n";
    return 0;
}