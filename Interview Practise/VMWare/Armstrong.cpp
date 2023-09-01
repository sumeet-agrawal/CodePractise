#include <iostream>
#include <math.h>

using namespace std;

bool isArmstrong(int n)
{
    int num{n}, ans{};
    int k = ceil(log10(n));
    cout<<k<<"\n";
    while(n)
    {
        ans+=pow(n%10, k);
        n/=10;
    }
    return ans==num;
}

int main()
{
    int n;
    cin>>n;
    if(isArmstrong(n))
        cout<<"It is armStrong\n";
    else
        cout<<"It is not armstrong\n";
    return 0;
}