#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count(string s)
{
    int sum{};
    for(auto x: s)
        sum+=x-'0';
    int cnt{};
    for(auto x: s)
    {
        int d{x-'0'};
        int k{(sum-d)%3};
        switch(d%3)
        {
            case 0:
                cnt+=3;
                break;
            case 1:
                if(k==0)
                    cnt+=4;
                else if(k==1)
                    cnt+=3;
                else
                    cnt+=2;
                break;
            case 2:
                if(k==0)
                    cnt+=4;
                else if(k==1)
                    cnt+=2;
                else
                    cnt+=3;
                break;
        }
    }
    if(sum%3==0)
        cnt++;
    return cnt;
}

int main()
{
    vector<string> v{"23", "0081", "022"};
    for(auto &x: v)
        cout<<count(x)<<"\n";
    return 0;
}

//NUll check for string
//Bucket count could be faster