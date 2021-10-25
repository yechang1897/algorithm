#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> nums(201, vector<int>(201));

int getMin(vector<vector<int>> nums) {
    int m = nums.size();
    int n = nums[0].size();
    int dp[m][n];
    dp[0][0] = nums[0][0];
    for(int i = 1; i < m;i++) {
        dp[0][i] = nums[0][i] + dp[0][i - 1];
    }
    for(int i = 1; i < n;i++) {
        dp[i][0] = nums[i][0] + dp[i - 1][0];
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + nums[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> nums = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout << getMin(nums) << endl;
    return 0;
}