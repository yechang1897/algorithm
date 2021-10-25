#include<iostream>

using namespace std;

int cuttingRope(int n) {
    if(n == 2) return 1;
    if(n == 3) return 2;
    int sum = 0;
    while(n >= 3) {
        n -= 3;
        sum++;
    }
    if(n == 2) return pow(3, sum) * 2;
    if(n == 1) return pow(3, sum - 1) * 4;
    return pow(3, sum);
}
//动态规划写法
int cuttingRope2(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[2] = 1;
        for(int i = 3; i < n + 1; i++) {
            for(int j = 2; j < i; j++) {
                dp[i] = max(dp[i],max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }

int main() {
    int n = 10;
    cout << cuttingRope(n);
    return 0;
}

/**
36
**/