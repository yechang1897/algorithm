#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return amount;
    vector<int> f(amount + 1, amount + 1);
    f[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i < coins[j]) break;
            f[i] = min(f[i], f[i - coins[j]] + 1);
        }
    }

    for(auto x : f) cout << x << " ";
    cout << endl;
    return f[amount] < amount ? f[amount] : -1;
}

int main() {
    vector<int> coins = {2};
    int amount = 3;
    cout << coinChange(coins, amount);
    return 0;
}