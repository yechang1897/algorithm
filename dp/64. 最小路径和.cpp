#include<iostream>
#include<vector>

using namespace std;

const int N = 205;
int f[N][N];

int minPathSum(vector<vector<int>>& grid) {
    f[0][0] = grid[0][0];
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!i && !j) continue;
            if(!i) f[i][j] = f[i][j - 1] + grid[i][j];
            else if(!j) f[i][j] = f[i - 1][j] + grid[i][j];
            else if(i != 0 && j != 0)f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }
    return f[n - 1][m - 1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(grid);
}