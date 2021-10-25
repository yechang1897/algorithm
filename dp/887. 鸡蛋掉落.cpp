#include<iostream>
#include<cstring>
using namespace std;
//复杂度太高
int f(int k, int n) {
    if(k == 1 || n == 1 || n == 0) return n;

    int minNum = n;
    for(int i = 1; i <= n; i++) {
        int tMin = max(f(k - 1, i - 1), f(k, n - i));
        minNum = min(minNum, 1 + tMin);
    }
    return minNum;
}


//复杂的还是太高
int superEggDrop(int k, int n) {
    //return f(k, n);
    int f[k + 1][n + 1];
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i++) {
        f[0][i] = 0;
        f[1][i] = i;
    }

    for(int i = 1; i <= k; i++) {
        f[i][0] = 0;
    }

    for(int i = 2; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            int t = n * n;
            for(int x = 1; x <= j; x++) {
                t = min(t, 1 + max(f[i - 1][x - 1], f[i][j - x]));
            }
            f[i][j] = t;
        }

    }
    return f[k][n];
}

int superEggDrop2(int K, int N) {
    int dp[K + 1][N + 1];
    memset(dp, 0, sizeof dp);
    for (int m = 1; m <= N; m++) {
        dp[0][m] = 0; // zero egg
        for (int k = 1; k <= K; k++) {
            dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
            if (dp[k][m] >= N) {
                return m;
            }
        }
    }
    return N;
}




int main() {
    int k = 7, n = 5000;
    cout << superEggDrop2(k, n) << endl;
    return 0;
}