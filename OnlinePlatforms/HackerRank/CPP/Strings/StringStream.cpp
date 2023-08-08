#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> vec;
    stringstream ss(str);
    char ch = ',';
    while(ch == ','){
        int num ;
        ch = ' ';
        ss>>num>>ch;
        //cout<<num<<" "<<ch;
        vec.push_back(num);
    }
    return vec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
