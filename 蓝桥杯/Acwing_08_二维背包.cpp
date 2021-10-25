#include<iostream>
#include<algorithm>
using namespace std;

int f[1005][1005];
int v[1005];
int m[1005];
int w[1005];
/*
空间优化的二维背包
*/
// int main() {
//     int N, V, M;
//     cin >> N >> V >> M;
//     for(int i = 1; i <= N; i++) cin >> v[i] >> m[i] >> w[i];
//     for(int i = 1; i <= N; i++) {
//         for(int j = V; j >= v[i]; j--) {
//             for(int k = M; k >= m[i]; k--) {
//                 f[j][k] = max(f[j][k], f[j - v[i]][k - m[i]] + w[i]);
//             }
//         }
//     }
//     cout << f[V][M] << endl;
//     return 0;
// }

int dp[1005][1005][1005];
int main() {
    int N, V, M;
    cin >> N >> V >> M;
    for(int i = 1; i <= N; i++) cin >> v[i] >> m[i] >> w[i];
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= V; j++) {
            for(int k = 0; k <= M; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if(j >= v[i] && k >= m[i]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    cout << dp[N - 1][V - 1][M - 1] << endl;
    return 0;
}