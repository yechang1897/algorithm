#include<iostream>
#include<algorithm>
using namespace std;

int mapN[4][4] = {0};
int dp[4][4] = {0};

int main(){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mapN[i][j];
        }
    }
    dp[0][0] = mapN[0][0];
    int k = dp[0][0];
    for (int i = 1; i < 4; i++){
        k += mapN[i][0];
        dp[i][0] = k;
    }
    k = dp[0][0];
     for (int i = 1; i < 4; i++){
        k += mapN[0][i];
        dp[0][i] = k;
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            dp[i][j] = min(dp[i - 1][j] + mapN[i][j], dp[i][j - 1] + mapN[i][j]);
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[3][3];
}