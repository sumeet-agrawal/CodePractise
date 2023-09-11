#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPossible(const vector<int>& arr, const int& h, int k)
{
    int sum{};
    for(auto x: arr)
        sum += ceil((double)x/k),
        cout<<ceil((double)x/k)<<" ";
    cout<<"\n";
    cout<<k<<" "<<sum<<"\n";
    return sum<=h;
}

int minJobSpeed(const vector<int>& arr, const int& h)
{
    int n = arr.size();
    if(h<n)
        return -1;
    int low{1}, high{*max_element(arr.begin(), arr.end())}; 
    while(low<high)
    {
        int mid{(low+high)/2};
        if(isPossible(arr, h, mid))
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    vector<int> arr{3, 7, 6, 11};
    int h = 8;
    cout<<minJobSpeed(arr, h)<<"\n";
    return 0;
}