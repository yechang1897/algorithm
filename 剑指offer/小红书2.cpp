#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N = 0;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int vis[1000][1000];
int res = 0;

bool check(int m, int n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i == m && j == n)
                continue;
            if(!vis[i][j])
                return false;
        }
    }
    return true;
}

void dfs(int i, int j){

    if(check(i, j) && i == N - 1) res++;

    for (int k = 0; k < 4; k++) {
        int x = dx[k] + i, y = dy[k] + j;
        if (x >= 0 && x < N && y >= 0 && y < N && !vis[x][y]) {
            vis[i][j] = 1;
            dfs(x, y);
            vis[i][j] = 0;
        }             
    }
}

int main() {
    cin >> N;
    vector<string> seats(N);
    for (int i = 0; i < N; i++) {        
        cin >> seats[i];
    }
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (seats[i][j] == '#')
                vis[i][j] = 1;
        }
    }
    dfs(0, 0);
    cout << res << endl;
}