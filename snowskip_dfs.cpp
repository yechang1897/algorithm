#include<iostream>
#include<cstdio>
using namespace std;
 
int R, C;
int map[105][105];
int mark[105][105] = { 0 };
 
 
int dfs(int i, int j)
{
    int k;
    if (mark[i][j]){ 
        return mark[i][j];
    }
    if (i != 0 && map[i - 1][j] < map[i][j]){
        k = dfs(i - 1, j) + 1;
        if (k > mark[i][j]) {
            mark[i][j] = k;
        }
    }
    if (i != R - 1 && map[i + 1][j] < map[i][j]){
        k = dfs(i + 1, j) + 1;
        if (k>mark[i][j]) {
            mark[i][j] = k;
        } 
    }
    if (j != 0 && map[i][j - 1] < map[i][j]){
        k = dfs(i, j - 1) + 1;
        if (k>mark[i][j]){ 
            mark[i][j] = k;
        }
    }
    if (j != C - 1 && map[i][j + 1]<map[i][j]){
        k = dfs(i, j + 1) + 1;
        if (k>mark[i][j]) {
            mark[i][j] = k;
        }
    }
    return mark[i][j];
}
 
int main()
{
    int i, j, k, sum = 0;
    scanf("%d%d", &R, &C);
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            k = dfs(i, j);
            if (k>sum) sum = k;
        }
    }
    for (i = 0; i < R; i++){
        for (j = 0; j < C; j++){
            cout << mark[i][j] << " ";
        }
        cout << endl;
    }
    cout << sum + 1 << endl;
    return 0;
}