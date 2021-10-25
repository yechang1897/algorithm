#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> countZerosAndOnes(string s) {
    vector<int> res(2);
    for (char c : s) {
        if(c == '0') {
            res[0]++;
        } else {
            res[1]++;
        }
    }
    return res;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int s = (int)strs.size();
    vector<vector<vector<int>>> dp(s + 1, vector<vector<int>>(m + 1, vector(n  + 1,  0)));
    for (int i = 1; i <= s; i++) {
        vector<int> zeroAndOne = countZerosAndOnes(strs[i - 1]);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                if (zeroAndOne[0] > j || zeroAndOne[1] > k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                } else {
                    dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - zeroAndOne[0]][k - zeroAndOne[1]]);
                }
            }
        }
    }
    return dp[s][m][n];    
}

int findMaxForm_2(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string s : strs) {
        vector<int> zeroAndOne = countZerosAndOnes(s);
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if(i >= zeroAndOne[0] && j >= zeroAndOne[1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeroAndOne[0]][j - zeroAndOne[1]]);
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << findMaxForm_2(strs, m, n);
}