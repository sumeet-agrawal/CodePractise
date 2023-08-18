#include <iostream>
#include <cmath>

constexpr int R = 6;
constexpr int C = 5;

void printMaxSubSquare(bool M[R][C])
{
    int S[R][C]{};

    for (int i{ 0 }; i < R; i++)
        S[i][0] = M[i][0];

    for (int i{ 0 }; i < C; ++i)
        S[0][i] = M[0][i];

    int maxs = 0;
    for (int i{ 1 }; i < R; ++i)
    {
        for (int j{ 1 }; j < C; ++j)
        {
            if (M[i][j] == 0)
            {
                S[i][j] = 0;
            }
            else
            {
                S[i][j] = std::min(S[i - 1][j], std::min(S[i - 1][j - 1], S[i][j - 1])) + 1;
                if (maxs < S[i][j])
                    maxs = S[i][j];
            }
        }
    }

    for (int i{ 0 }; i < maxs; i++)
    {
        for (int j{ 0 }; j < maxs; ++j)
            std::cout << 1 << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    bool M[R][C] = { {0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0} };

    printMaxSubSquare(M);
    return 0;
}