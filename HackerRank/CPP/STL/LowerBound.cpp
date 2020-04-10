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
    vector<int> arr;
    for(int i =0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int num;
        cin>>num;
        if(arr[0]==num){
            cout<<"Yes "<<1<<endl;
        }
        else if(arr[0]>num){
            cout<<"No "<<1<<endl;
        }
        int high = arr.size() - 1, low = 0, mid;
       // cout<<num<<endl;
        for(int j=high;j>=low;j--){
            mid = (high + low)/2;
            //cout<<j<<" "<<high<<" "<<mid<<" "<<low<<endl;
            if(high-low>10){
                if(num > arr[mid]){
                    j = high;
                    low = mid;
                    continue;
                }
                else if(num <= arr[mid]){
                    high = mid;
                    j = mid;
                    continue;
                }
            }
            //cout<<j<<" "<<arr[j]<<endl;
            if(arr[j]>=num){
                
                continue;
            }
            else{
                if(arr[j+1] == num){
                    cout<<"Yes "<<(j+1)+1<<endl;
                }
                else{
                    cout<<"No "<<(j+1)+1<<endl;
                }
                break;
            }
        }
    }
    return 0;
}
