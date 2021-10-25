#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    for(vector<int> vec : envelopes) {
        for(int i : vec) {
            std::cout << i << " ";
        }
        std::cout << endl;
    }
    int n = envelopes.size();
    vector<int> dp(n, 0);
    int res;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0])
            {
                temp = max(temp, dp[j]);
            } 
        }
        dp[i] = temp + 1;
        res = max(dp[i], res);
    }
    // int lastenv = 0;
    // for (int i = 1; i < n; i++) {     
    //         if (envelopes[i][1] > envelopes[i - 1][1] && envelopes[i][0] > envelopes[i - 1][0])
    //         {
    //             dp[i] = dp[i - 1] + 1; 
    //         } 
    //     dp[i] = temp + 1;
    //     res = max(dp[i], res);
    // }
    for(int j : dp) {
        std::cout << j << " ";
    }
    return res;
}

int main() {
    vector<vector<int>> envelopes = {{10,8},{1,12},{6,15},{2,18}};
    std::cout << maxEnvelopes(envelopes) << endl;
}