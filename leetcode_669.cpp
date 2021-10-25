#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX_VALUE=0x3f3f3f3f;

int coinChange(vector<int> &coins, int amount){
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = MAX_VALUE;
        for (int j = 0; j < (int)coins.size(); j++){
            if (i >= coins[j] && dp[i - coins[j]] != MAX_VALUE){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // for_each(dp, dp + amount, [](int i) { cout << i; }), cout << endl;
    if(dp[amount] != MAX_VALUE) {
        return dp[amount];
    } else {
        return -1;
    }
}

int coinChange_2(vector<int> &coins, int amount) {
        // write your code here
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        for (int i = 0; i < coins.size(); i++) {
            for(int j = coins[i];j<=amount;j++)
            {
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount]==INT_MAX-1) return -1;
        return dp[amount];
    }

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount);
}