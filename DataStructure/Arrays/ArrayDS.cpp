#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

vector<string> split_string(const string& str)
{
    stringstream s(str);
    vector<string> ans{};
    string token{};
    while(s>>token)
        ans.push_back(token);
    return ans;
}

// Complete the reverseArray function below.
vector<int> reverseArray(vector<int>& a) {
    reverse(a.begin(), a.end());
    return a;
}

int main()
{
    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr;
    for (auto &x: arr_temp)
        arr.push_back(stoi(x));

    vector<int> res = reverseArray(arr);
    for (const auto &x: res)
        cout << x <<" ";
    cout << "\n";

    return 0;
}