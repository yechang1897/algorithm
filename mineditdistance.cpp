#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int mineditdistance(string A, string B){
    int lengthA = A.size();
    int lengthB = B.size();
    int dp[lengthA + 1][lengthB + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= lengthA; i++) {
        dp[0][i] = i;
    }
    for (int j = 1; j <= lengthB; j++) {
        dp[j][0] = j;
    }
    for (int i = 1; i <= lengthA; i++) {
        for (int j = 1; j <= lengthB; j++) {
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1);
        }
    }
    return dp[lengthA][lengthB];
}

int main() {
    string A = "horse";
    string B = "rose";
    cout << mineditdistance(A, B);
}