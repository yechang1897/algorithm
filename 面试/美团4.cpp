#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    int x[n / 2 + 1];
    int y[n / 2 + 1];
    int idx = 1;
    for(int i = 1; i <= n/ 2; i++) x[i] = a[idx++];
    for(int i = 1; i <= n/ 2; i++) y[i] = a[idx++];

    int dp[n/2 + 1][n/2 + 1];
    for(int i = 1; i <= n / 2; i++) dp[i][0] = i;
    for(int i = 1; i <= n / 2; i++) dp[0][i] = i;

    for(int i = 1; i <= n /2; i++) {
        for(int j = 1; j <= n / 2; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if(x[i] == y[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n / 2][n / 2];
}