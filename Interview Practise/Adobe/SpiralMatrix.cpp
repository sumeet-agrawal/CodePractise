#include <iostream>

#define R 4
#define C 4

void spiralPrint(int mat[R][C], int i, int j, int m, int n)
{
    if (i >= m || j >= n)
        return;
    if (i < m)
        for (int p{ j }; p < n; p++)
        {
            std::cout << mat[i][p] << " ";
        }
    i++;
    if (j < n)
        for (int p{ i }; p < m; p++)
        {
            std::cout << mat[p][n - 1] << " ";
        }
    n--;
    if (i < m)
        for (int p{ n - 1 }; p >= j; p--)
        {
            std::cout << mat[m - 1][p] << " ";
        }
    m--;
    if (j < n)
        for (int p{ m - 1 }; p >= i; p--)
        {
            std::cout << mat[p][j] << " ";
        }
    j++;
    spiralPrint(mat, i, j, m, n);
}

int main()
{
    int a[R][C] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };

    // Function Call
    spiralPrint(a, 0, 0, R, C);
    return 0;
}