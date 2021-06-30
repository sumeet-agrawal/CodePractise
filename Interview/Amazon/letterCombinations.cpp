#include <iostream>
#include <string>
#include <queue>

void letterCombinations(int arr[], int n)
{
    std::string pad[]{ "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
    std::queue<std::string> que{};
    que.push("");
    while (!que.empty() && que.front().length() < n)
    {
        std::string s = que.front();
        que.pop();
        for (auto a : pad[arr[s.length()]])
        {
            que.push(s + a);
        }
    }
    while (!que.empty())
    {
        std::cout << que.front() << " ";
        que.pop();
    }
}

int main()
{
    int number[] = { 2, 3 };
    int n = sizeof(number) / sizeof(number[0]);

    // Function call
    letterCombinations(number, n);

    return 0;
}