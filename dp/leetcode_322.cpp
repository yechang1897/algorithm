#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return amount;
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for(int i = 1; i <= amount; ++i) {
        for(int j = 0; j < (int)coins.size(); ++j) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    for(int i : dp) {
        cout << i << " ";
    }
    cout << endl;
    return dp[amount]  <= amount ? dp[amount] : -1;
}

int main() {
    vector<int> coins =  {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount);
}