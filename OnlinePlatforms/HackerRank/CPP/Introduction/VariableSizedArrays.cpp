#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin>>n>>q;
    vector<vector<int>> vec, que;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        vector<int> vect;
        for(int j=0;j<temp;j++){
            int temp1;
            cin>>temp1;
            vect.push_back(temp1);
        }
        vec.push_back(vect);
    }
    for(int i =0;i<q;i++){
        vector<int> vect;
        for(int j=0;j<2;j++){
            int temp;
            cin>>temp;
            vect.push_back(temp);
        }
        que.push_back(vect);
    }
    for(int i=0;i<q;i++){
        cout<<vec[que[i][0]][que[i][1]]<<endl;
    }
    return 0;
}
