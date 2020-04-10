#include <iostream>
#include <cstdio>
using namespace std;

void printNum(int n)
{
    switch(n)
    {
        case 1: cout<<"one";break;
        case 2: cout<<"two";break;
        case 3: cout<<"three";break;
        case 4: cout<<"four";break;
        case 5: cout<<"five";break;
        case 6: cout<<"six";break;
        case 7: cout<<"seven";break;
        case 8: cout<<"eight";break;
        case 9: cout<<"nine";break;
    }
    cout<<endl;
}
int main() {
    // Complete the code.
    int a, b;
    cin>>a>>b;
    for(int i =a;i<=b;i++)
    {
        if(i>= 1 && i<=9 ){
            printNum(i);
        }
        else if(i%2){
            cout<<"odd"<<endl;
        }
        else{
            cout<<"even"<<endl;
        }
    }
    return 0;
}
