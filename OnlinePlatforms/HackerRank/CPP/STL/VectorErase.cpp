#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }  
    cin>>n;
    vec.erase(vec.begin()+n-1);
    int a,b;
    cin>>a>>b;
    vec.erase(vec.begin()+a-1,vec.begin()+b-1);
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
