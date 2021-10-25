#include<iostream>
#include<algorithm>

using namespace std;

int n, m, K, x, y;

int a[15][15];

int res;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool visit[15][15];

void dfs(int x1, int y1, int K, int val) {
    if(!K && x1 == x && y1 == y) {
        // cout << val << endl;
        res = max(res, val);
        return;
    }
    if(!K) {
        // cout << val << endl;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x1 + dx[i], ny = y1 + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] && !visit[nx][ny]) {
            // cout << val << endl;
            visit[nx][ny] = true;
            dfs(nx, ny, K - 1, val + a[nx][ny]);
            visit[nx][ny] = false;
        } else if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny]) {
            // cout << val << endl;
            dfs(nx, ny, K - 1,val);
        }
    }
}

int main() {
    cin >> n >> m >> K >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    visit[x][y] = true;
    dfs(x, y, K, a[x][y]);
    cout << res << endl;
    return 0;
}