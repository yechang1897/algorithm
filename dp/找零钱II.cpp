#include<iostream>
#include<vector>

using namespace std;
/**
给定不同面额的硬币 coins 和一个总金额 amount,
计算可以凑成总金额所需的最少的硬币个数(每种硬币的数量可认为是无限的),
如果没有任何一种硬币组合能组成总金额，返回 -1。
 
 
示例 1：coins = [1, 2, 5], amount = 11
最少硬币个数：3, 11=5+5+1
 
示例 2：coins = [2], amount = 3
最少硬币个数：-1, 无解
 
示例 3：coins = [1], amount = 0
最少硬币个数：0, 不需要找零
**/

int changeCoin3(vector<int> coins, int amount) {
    int n = coins.size();
    vector<vector<int>> f(n + 1, vector<int>(amount + 1));
    for(int i = 1; i <= amount; i++) f[0][i] = INT_MAX;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i - 1])
                f[i][j] = min(f[i - 1][j], f[i][j - coins[i - 1]] + 1);
            else 
                f[i][j] = f[i - 1][j];
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= amount; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return f[n][amount];
}


int changeCoin4(vector<int> coins, int amount) {
    int n = coins.size();
    vector<int> f(amount + 1);
    for(int i = 1; i <= amount; i++) f[i] = INT_MAX;
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = coins[i - 1]; j <= amount; j++) {
            f[j] = min(f[j], f[j - coins[i - 1]] + 1);
            cout << f[j] << " ";
        }
        cout << endl;
    }
    return f[amount];
}

int main() {
    vector<int> coins = {1, 5, 10, 20};
    int amount = 15;
    cout << changeCoin3(coins, amount);
    return 0;
}