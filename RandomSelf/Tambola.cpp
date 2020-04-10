#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

int arr[91] = {0};
void printUsedNumbers(){
    for(int i = 1;i<91;i++){
        if(arr[i])
            cout<<i<<" ";
        if(i%10 == 0){
            cout<<endl;
        }
    }
}
int generateNew(){
    srand(3);
    int num =rand()%90 +1;
    while(arr[num] != 0){
        num = rand()%90 +1;
    }
    arr[num] = 1;
    return num;
}
int main(){
    int in, num;
    while(1){
        cout<<endl<<endl<<"Menu"<<endl<<"Press 1 & than enter for new number"<<endl;
        cout<<"Press 2 & than enter to show all the numbers so far"<<endl;
        cout<<"Press 3 to terminate tambola screen"<<endl;
        cout<<"Input :  ";
        cin>>in;
        switch(in){
            case 1: num = generateNew();
                    cout<<"New Number:...  "<<num<<"  ...";
                    break;
            case 2: cout<<"List of numbers"<<endl<<endl;
                    printUsedNumbers();
                    cout<<endl;
                    break;
            case 3: cout<<"It was nice playing with you !!!";
                    break;
            default:
                continue;
                break;
        }
        if(in == 3){
            break;
        }
    }
    return 0;
}
