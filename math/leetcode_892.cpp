#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
    int N = (int)grid.size();
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            //上面漏出的表面积
            res += i - 1 >= 0 ? max(grid[i][j] - grid[i - 1][j], 0) : grid[i][j];
            //下面露出的表面积
            res += i + 1 < N ? max(grid[i][j] - grid[i + 1][j], 0): grid[i][j];
            //左边漏出的表面积
            res += j - 1 >= 0 ? max(grid[i][j] - grid[i][j - 1], 0) : grid[i][j];
            //右边漏出的表面积
            res += j + 1 < N ? max(grid[i][j] - grid[i][j + 1], 0) : grid[i][j];
            res += grid[i][j] > 0 ? 2 : 0;
        }
    }
    return res;
}

int main() {
    // vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> grid = {{2,2,2},{2,1,2},{2,2,2}};
    cout << surfaceArea(grid);
}