#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned count(unsigned n, unsigned s, unsigned p, unsigned q){
    unsigned sz = 1<<31;
    vector<bool> vec(sz);
    unsigned a = s%sz;
    vec[a] = true;
    int count = 1;
    for(int i =1;i<n;i++){
        a*=p;
        a+=q;
        a%=sz;
        if(!vec[a]){
            count++;
            vec[a] = true;
        }
        else{
            return count;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unsigned n = 0, s = 0, p = 0, q = 0;
    cin>>n>>s>>p>>q;
    cout<<count(n,s,p,q)<<endl;  
    return 0;
}
