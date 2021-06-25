#include <iostream>

int closestRoot(int num)
{
    if (num <= 0)
        return 0;
    int start = 0, end = num / 2;
    int mid;
    int ans{ 0 };

    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == num) {
            ans = mid;
            break;
        }
        else if (mid* mid < num) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }

    int temp1 = ans * ans;
    int temp2 = (ans + 1) * (ans + 1);
    temp1 = num > temp1 ? num - temp1 : temp1 - num;
    temp2 = num > temp2 ? num - temp2 : temp2 - num;
    return temp1 < temp2 ? ans : ans + 1;
}

int main()
{
    int num{ 0 };
    std::cin >> num;
    std::cout << closestRoot(num) << "\n";
    return 0;
}