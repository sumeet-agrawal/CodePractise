#include <iostream>
#include <vector>

using namespace std;

string prefix(const vector<string>& arr)
{
    int n = arr[0].size();
    for(auto &x: arr)
    {
        int i{}, k = min(n, (int)x.size());
        for(;i<k;i++)
        {
            if(x[i] != arr[0][i])
                break;
        }
        n = i;
    }
    return arr[0].substr(0, n);
}

int main()
{
    vector<string> arr{"geeksforgeeks", "geeks", "geek", "geezer"};
    cout<<prefix(arr)<<"\n";
    return 0;
}