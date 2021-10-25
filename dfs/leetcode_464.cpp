#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool dfs(int state, vector<bool>& dp, int maxChoosableInteger, int desiredTotal) {
    if(dp[state] != false) {
        return dp[state];
    }

    for(int i = 1; i <= maxChoosableInteger; i++) {
        int cur = 1 << (i - 1);
        if((cur & state) != 0) {
            continue;
        }

        if(i >= desiredTotal || !dfs(cur | state, dp, maxChoosableInteger, desiredTotal - i)) {
            return dp[state] = true;
        }
    }
    return dp[state] = false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
     if(desiredTotal <= maxChoosableInteger) return true;
     //所有数字累加都无法达到desiredTotal,直接返回false;
     if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;   
     vector<bool> dp((1 << maxChoosableInteger), false);
    //  for(auto item : dp) {
    //      cout << item << " ";
    //  }
    //  cout << endl;
     return dfs(0, dp, maxChoosableInteger, desiredTotal);
}



int main() {
    // int maxChoosableInteger = 10;
    // int desiredTotal = 11;
    // cout << canIWin(maxChoosableInteger, desiredTotal);
    const int i = 10;
    int *p = const_cast<int*>(&i);
    *p = 12;
    cout << *p << " " << i << endl;
}