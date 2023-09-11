#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> arr{1.3, 1.4, 1.5, 1.6};
    sort(arr.begin(), arr.end());
    int st{}, en = arr.size()-1;
    int ans{};
    while(st<=en)
    {
        if(st == en)
        {
            ans++;
            break;
        }
        if(arr[st]+arr[en]<=3.00)
            ans++,
            st++, en--;
        else
            ans++,
            en--;
    }
    cout<<"Answer bag "<<ans<<"\n";
    return 0;
}