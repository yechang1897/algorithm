#include<iostream>
#include<algorithm>
using namespace std;

int f[1005][1005];
int v[1005], w[1005];


// int main() {
//     int N, V;
//     cin >> N >> V;
//     for(int i = 1 ; i <= N; i++) cin >> v[i] >> w[i];
//     for(int i = 1; i <= N; i++) {
//         for(int j = 0; j <= V; j++) {
//             //不选当前物品
//             f[i][j] = f[i - 1][j];
//             //选择当前物品
//             if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//     cout << f[N][V] << endl;
// }

int dp[1005];

int main() {
    int N, V;
    cin >> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= V; j++) {
            if(j >= v[i]) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V];
}

/*
4 5
1 2
2 4
3 4
4 5
*/