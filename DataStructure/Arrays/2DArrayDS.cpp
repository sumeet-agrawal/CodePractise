#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <limits>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(const vector<vector<int>>& arr) {
    int ans{INT_MIN};
    for(int j{};j<4;j++)
        for(int k{};k<4;k++){
            int t{arr[j][k]+arr[j][k+1]+arr[j][k+2]+arr[j+1][k+1]+arr[j+2][k]+arr[j+2][k+1]+arr[j+2][k+2]};
            ans = max(t, ans);
        }
    return ans;
}

int main()
{
    vector<vector<int>> arr(6, vector<int>(6));
    for (int i{}; i < 6; i++) {
        for (int j{}; j < 6; j++)
            cin >> arr[i][j];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
