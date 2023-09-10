#include <iostream>
#include <vector>

using namespace std;

void quick(vector<int>& vec, int start, int end)
{
    if(end<=start)
        return;
    int j{start};
    for(int i{start};i<end;i++)
        if(vec[i]<vec[end])
            swap(vec[i], vec[j++]);
    swap(vec[j], vec[end]);

    quick(vec, start, j-1);
    quick(vec, j+1, end);
}

int main()
{
    vector<int> vec{3, 8, 5, 1, 9, 4, 2, 7, 6, 0};
    quick(vec, 0, vec.size()-1);
    for(auto x: vec)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}