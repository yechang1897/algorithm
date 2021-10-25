#include<iostream>
using namespace std;

int n, m;

int res = 0;
//会超时
void dfs(int i, int j) {
    if(i > n || j > m) return;
    if(i % 2 == 0 && j % 2 == 0) return; 
    
    if(i == n && j == m) {
        res++;
        return;
    }   
    dfs(i + 1, j);
    dfs(i, j + 1);
}

//记忆化搜索

int vis[35][35];

int dfs2(int i, int j) {
    if(i > n || j > m) return 0;

    if(i & 1 || j & 1) {
        if(vis[i][j]) return vis[i][j]; 
        vis[i][j] += dfs2(i + 1, j);
        vis[i][j] += dfs2(i, j + 1);
    }
    return vis[i][j];
}

int f[35][35];

int getAll(int n, int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=m; j++) {
            if(i % 2 == 0 && j % 2 == 0) continue;
            if(i == 1) f[i][j] = 1;
            if(j == 1) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[n][m];
}

int main() {
    cin >> n >> m;

    dfs(1, 1);
    vis[n][m] = n & 1 || m & 1;
    cout  << dfs2(1, 1) << endl;
    cout << res << endl;
    cout << getAll(n, m) << endl;
}