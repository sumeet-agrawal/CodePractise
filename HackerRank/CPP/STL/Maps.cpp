#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include<string>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string, int> mp;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int qur;string str;int num;
        cin>>qur;
        
        switch(qur){
            case 1:{
                cin>>str>>num;
                auto itr = mp.find(str);
                if(itr != mp.end()){
                    itr->second+=num;
                }
                else{
                    mp.insert({str,num});
                }
                break;
            }
            case 2:{
                cin>>str;
                auto itr  = mp.find(str);
                if(itr != mp.end()){
                    mp.erase(itr);
                }
                break;
            }
            case 3:{
                cin>>str;
                auto iter1 = mp.find(str);
                if(iter1 != mp.end()){
                    cout<<iter1->second<<endl;
                }
                else{
                    cout<<0<<endl;
                }
                break;
            }
        }
    }  
    return 0;
}
