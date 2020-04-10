#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    //cout<<"Hello World"<<endl;
    deque<int> que;
    for(int i =0;i<k;i++){
        if(que.empty()){
            que.push_back(i);
        }
        else {
            while(!que.empty() && arr[i]>=arr[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }
    }
    for(int i =k, j=0;i<n;i++,j++){
        cout<<arr[que.front()]<<" ";
        if(j == que.front()){
            que.pop_front();
        }
        if(que.empty()){
            que.push_back(i);
        }
        else {
            while(!que.empty() && arr[i]>=arr[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }
    }
    cout<<arr[que.front()]<<endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
