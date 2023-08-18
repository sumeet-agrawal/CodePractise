#include <iostream>

int binarySearch(int arr[], int s, int e, int num)
{
    if (s > e)
        return -1;
    int m = (s + e) / 2;
    if (arr[m] == num)
        return m;
    else if (arr[m] < num)
        return binarySearch(arr, m + 1, e, num);
    else
        return binarySearch(arr, s, m - 1, num);
}
int findPos(int arr[], int num)
{
    int s{ 0 }, e{ 1 };
    while (num > arr[e])
    {
        s = e;
        e <<= 1;
    }
    return binarySearch(arr, s, e, num);
}
int main()
{
    int arr[] = { 3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170 };
    int ans = findPos(arr, 10);
    if (ans == -1)
        std::cout << "Element not found";
    else
        std::cout << "Element found at index " << ans;
    return 0;
}