#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
int q[N][N];//   dp[i][j]表示前i个物品，背包容量是j的情况下的最大价值。
int v[N], w[N];
/*

*/
// int main() {
//     int n, V;
//     cin >> n >> V;
//     for(int i = 1; i <= n; i++) {
//         cin >> v[i] >> w[i];
//     }

//     for(int i = 1; i <= n;i++) {
//         for(int j = 0; j <= V; j++) {
//             q[i][j] = q[i - 1][j];
//             if(j >= v[i]) q[i][j] = max(q[i][j], q[i - 1][j - v[i]] + w[i]);
//         }
//     }
//     for(int i = 1; i <= n;i++) {
//         for(int j = 0; j <= V; j++) {
//             cout << q[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << q[n][V];
// }

/*
4 5
1 2
2 4
3 4
4 5


0 2 2 2 2 2 
0 2 4 6 6 6
0 2 4 6 6 8
0 2 4 6 6 8
8
*/

/*
滚动数组优化

*/

int f[1005];
// int v[1005];
// int w[1005];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
}