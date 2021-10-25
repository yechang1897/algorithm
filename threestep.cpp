#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int totalStep(int steps){
    int dp[steps + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= steps; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[steps];
}

int main(){
    int steps = 5;
    cout << totalStep(steps);
}