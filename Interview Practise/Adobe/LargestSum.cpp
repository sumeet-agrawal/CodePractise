#include <iostream>
#include <vector>

using namespace std;

int lSum(const vector<int>& arr)
{
    int maxSoFar{}, maxEndingHere{};
    for(auto &x: arr)
    {
        maxEndingHere += x;
        maxSoFar = max(maxEndingHere, maxSoFar);
        if(maxEndingHere <0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

int main()
{
    vector<int> arr{ -2, -3, 4, -1, -2, 1, 5, -3 };
    cout<<lSum(arr)<<"\n";
    return 0;
}