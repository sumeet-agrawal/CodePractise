#include <iostream>
#include <map>

int pageFaults(int arr[], int n, int capacity)
{
    std::map<int, int> mp;
    int pageFaults{ 0 };
    for (int i{ 0 }; i < n; i++)
    {
        if (mp.size() < capacity)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                pageFaults++;
            }
        }
        else
        {
            if (mp.find(arr[i]) == mp.end())
            {
                int lru = INT_MAX, val;
                for (auto& itr : mp)
                {
                    if (mp[itr.first] < lru)
                    {
                        lru = mp[itr.first];
                        val = itr.first;
                    }
                }
                mp.erase(val);
                pageFaults++;
            }
        }
        mp[arr[i]] = i;
    }
    return pageFaults;
}

int main()
{
    int pages[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    std::cout << pageFaults(pages, n, capacity);
    return 0;
}