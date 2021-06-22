
#include <iostream>

constexpr int NA = -1;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void moveToEnd(int arr[], int size)
{
    int count_i{ size - 1 }, arr_i{ size - 1 };
    while (count_i >= 0)
    {
        if (arr[count_i] != NA)
        {
            swap(arr[arr_i], arr[count_i]);
            --arr_i;

        }
        --count_i;
    }
}
void printArray(int arr[], int size)
{
    for (int i{ 0 }; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void merge(int arr[], int sec[], int m, int n)
{
    int m_i{ m - 1 }, n_i{ 0 }, arr_i{ 0 };
    while (arr_i < m + n)
    {
        if ((n_i == n) || ((m_i < m + n) && (arr[m_i] < sec[n_i])))
            swap(arr[arr_i], arr[m_i++]);
        else if ((m_i == m + n) || ((n_i < n) && (sec[n_i] < arr[m_i])))
            swap(arr[arr_i], sec[n_i++]);
        arr_i++;
    }
}
int main()
{
    /* Initialize arrays */
    int mPlusN[] = { 2, 8, NA, NA, NA, 13, NA, 15, 20 };
    int N[] = { 5, 7, 9, 25 };

    int n = sizeof(N) / sizeof(N[0]);
    int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;

    /*Move the m elements at the end of mPlusN*/
    moveToEnd(mPlusN, m + n);

    /*Merge N[] into mPlusN[] */
    merge(mPlusN, N, m, n);

    /* Print the resultant mPlusN */
    printArray(mPlusN, m + n);

    return 0;
}