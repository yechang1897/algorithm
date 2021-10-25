#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 21;

int grid[maxN][maxN];
int zeroCount = 0;
bool vis[maxN][maxN];
int M, N;
int res = INT_MAX;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int m, int n, int t, int price) {
    if(t == zeroCount) {
        cout << t << endl;
        cout << price << endl;
        res = min(res, price);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int x = m + dx[i];
        int y = n + dy[i];
        if(x < 0 || x >= M || y < 0 || y >= N || vis[x][y])
            continue;
        if(grid[x][y] == 0) t++;
        if(grid[x][y] != 0) price += grid[x][y];
        vis[x][y] = true;
        dfs(x, y, t, price);
        vis[x][y] = false;
    }
}

int main() {
    cin >> M >> N;
    memset(grid, -1, sizeof grid);
    memset(vis, false, sizeof vis);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 0) zeroCount++;
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 0){
                dfs(i, j, 1, 0);
                vis[i][j] = true;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}