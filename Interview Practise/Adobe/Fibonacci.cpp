#include <iostream>

/*int countWays(int n)
{
    if (n <= 1)
        return n;
    return countWays(n - 1) + countWays(n - 2);
}*/

/*int countWays(int n)
{
    int arr[6];
    arr[0] = 0; arr[1] = 1;
    for (int i{ 2 }; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}*/

int countWays(int n)
{
    int prev{ 0 }, cur{ 1 }, temp{ 0 };
    for (int i{ 2 }; i < n; i++)
    {
        temp = prev + cur;
        prev = cur;
        cur = temp;
    }
    return temp;
}

int main()
{
    int s = 5;

    std::cout << "Number of ways = " << countWays(s + 1);

    return 0;
}

//0 1 1 2 