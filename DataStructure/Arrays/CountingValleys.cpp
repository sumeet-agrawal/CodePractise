#include <string>
#include <iostream>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(string_view s) {
    int count =0,ans=0;
    for(auto x: s){
        if(x=='D')
            count--;
        else
            count++;
        if(count==0 && x=='U')
            ans++;
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    int result = countingValleys(s);

    cout << result << "\n";

    return 0;
}
