#include<iostream>
#include<vector>

using namespace std;

int changeCoin(vector<int> coins, int amount) {
    int n = coins.size();
    vector<vector<int>> f(n + 1, vector<int>(amount + 1));
    for(int i = 0; i <= n; i++) f[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i - 1])
                f[i][j] = f[i - 1][j] + f[i][j - coins[i - 1]];
            else 
                f[i][j] = f[i - 1][j];
        }
    }
    
    return f[n][amount];    
}

int changeCoin2(vector<int> coins, int amount) {
    int n = coins.size();
    vector<int> f(amount + 1, 0);
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i - 1])
                f[j] = f[j] + f[j - coins[i - 1]];
            cout << f[j] << " ";
        }
        cout << endl;
    }
    return f[amount];
}

int main() {
    vector<int> coins = {5,10,25,1};
    int amount = 15;
    // cout << changeCoin(coins, amount) << endl;
    cout << changeCoin2(coins, amount) << endl;
    return 0;
}