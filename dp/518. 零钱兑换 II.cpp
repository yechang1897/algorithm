#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//不重不漏，先遍历coins集合
int change(int amount, vector<int>& coins) {
    int f[amount + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for(int i = 0; i < coins.size(); i++) {
        for(int j = 0; j <= amount; j++) {
            if(j >= coins[i]) f[j] += f[j - coins[i]];
        }
    }
    // for(int i = 0; i <= amount; i++) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;
    return f[amount];
}

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(amount, coins);
    return 0;
}