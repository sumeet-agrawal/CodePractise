#include <iostream>
#include <algorithm>
#include <utility>

std::pair<int, int> findMaxGuests(int arv[], int ex[], int n)
{
    std::sort(arv, arv + n);
    std::sort(ex, ex + n);
    int max{ 0 }, max_index{ 0 };
    int i{ 0 }, j{ 0 }, count{ 0 };
    while (i < n)
    {
        if (arv[i] <= ex[j])
        {
            count++;
            if (count > max)
            {
                max = count;
                max_index = i;
            }
            i++;
        }
        else
        {
            count--;
            j++;
        }
    }
    return { max, arv[max_index] };
}

std::ostream& operator<<(std::ostream& out, std::pair<int, int> p)
{
    out << p.first << " " << p.second;
    return out;
}

int main()
{
    int arrl[] = { 1, 2, 10, 5, 5 };
    int exit[] = { 4, 5, 12, 9, 12 };
    int n = sizeof(arrl) / sizeof(arrl[0]);
    std::cout << findMaxGuests(arrl, exit, n) << "\n";
    return 0;
}