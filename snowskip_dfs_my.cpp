#include<iostream>
#include<algorithm>

using namespace std;
int map[105][105];
int mark[105][105] = {0};
int R, C;

int dfs(int i, int j){
    int k = 0;
    if(mark[i][j]) {
        return mark[i][j];
    }
    if(i != 0 && map[i - 1][j] < map[i][j]) {
        k = dfs(i - 1, j) + 1;
        if (k > mark[i][j]) {
            mark[i][j] = k;
        }
    }
    if(i != R && map[i + 1][j] < map[i][j]) {
        k = dfs(i + 1, j) + 1;
        if (k > mark[i][j]) {
            mark[i][j] = k;
        }
    }
    if(j != 0 && map[i][j - 1] < map[i][j]) {
        k = dfs(i, j - 1) + 1;
        if (k > mark[i][j]) {
            mark[i][j] = k;
        }
    }
    if(i != C && map[i][j + 1] < map[i][j]) {
        k = dfs(i, j + 1) + 1;
        if (k > mark[i][j]) {
            mark[i][j] = k;
        }
    }
    return mark[i][j];
}

int main(){
    cin >> R >> C;
    int n;
    int maxN = -1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            n = dfs(i, j);
            maxN = max(n, maxN);
        }
    }
    cout << maxN + 1 << endl ;
}