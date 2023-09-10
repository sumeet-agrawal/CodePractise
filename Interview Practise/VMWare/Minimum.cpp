#include <iostream>
#include <vector>

using namespace std;

int getMin(const vector<int>& vec, int st, int en)
{
    cout<<st<<" "<<en<<"\n";
    if(vec[st]<vec[en] || st==en)
        return vec[st];
    int mid = (st+en)/2;
    if(mid == st && vec[en]<vec[mid])
        return vec[en];
    if(vec[en]<vec[mid])
        return getMin(vec, mid, en);
    return getMin(vec, st, mid);
}

int main()
{
    vector<int> vec{3,4,5,6,7,1,2};
    cout<<getMin(vec, 0, vec.size()-1)<<"\n";
    return 0;
}