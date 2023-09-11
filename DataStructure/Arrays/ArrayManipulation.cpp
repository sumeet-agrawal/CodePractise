#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

vector<string> split_string(const string&);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n+2,0);
    long max=0;
    for(int i =0;i<queries.size();i++){
        arr[queries[i][0]]+=queries[i][2];
        arr[queries[i][1]+1]-=queries[i][2];
    }
    long num=0;
    for(int i=1;i<=n;i++){
        num+=arr[i];
        max = num>max?num:max;
    }
    return max;
}

int main()
{
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(const string& str)
{
    stringstream s(str);
    vector<string> ans{};
    string token{};
    while(s>>token)
        ans.push_back(token);
    return ans;
}