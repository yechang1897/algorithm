#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxLCS(string A, string B) {
    int lengthA = A.length();
    int lengthB = B.length();
    vector<vector<int>> dp(lengthA + 1, vector<int>(lengthB + 1, 0));

    // cout << dp[0][0] << endl;
    // for (int i = 0; i < lengthB; i++) {
    //     if(A[i] == B[0]) {
    //         dp[0][i] = 1;
    //     } else {
    //         dp[0][i] = 0;
    //     }
    // }

    for (int i = 1; i <= lengthA; i++)
    {
        for (int j = 1; j <= lengthB; j++)
        {
            dp[i][j] = A[i - 1] == B[j - 1] ? max(dp[i][j],dp[i - 1][j - 1]  + 1 ) : max(dp[i - 1][j],dp[i][j - 1]);
            // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // if(A[i - 1] == B[j - 1]) {
            //     dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            // }
        }
    }

    for (int i = 1; i <= lengthA; i++)
        {
            for (int j = 1; j <= lengthB; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    return dp[lengthA][lengthB];
}

int longestCommonSubsequence(string text1, string text2) {
        int lengthA = text1.length();
        int lengthB = text2.length();
        vector<vector<int>> dp(lengthA + 1, vector<int>(lengthB + 1, 0));

        for (int i = 1; i <= lengthA; i++)
        {
            for (int j = 1; j <= lengthB; j++)
            {
                dp[i][j] = text1[i - 1] == text2[j - 1] ? max(dp[i - 1][j],dp[i][j - 1])+1  : max(dp[i - 1][j],dp[i][j - 1]);
            }
        }

        for (int i = 1; i <= lengthA; i++)
        {
            for (int j = 1; j <= lengthB; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[lengthA][lengthB];
    }

int main() {
    string A =  "bsbininm";
        string B = "jmjkbkjkv";
    cout << longestCommonSubsequence(A, B) << endl;
    cout << maxLCS(A,B) << endl;
    return 0;
}