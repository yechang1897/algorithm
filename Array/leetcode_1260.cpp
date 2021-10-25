#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    k %= (m * n);
    deque<int> temp;
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp.push_back(grid[i][j]);
        }
    }
    for(int i = 0; i < k; ++i) {
        int num = temp.back();
        temp.pop_back();
        temp.push_front(num);
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            grid[i][j] = temp[i * n + j];
        }
    }
    return grid;
}

int main() {
    vector<vector<int>> grid = {{1},{2},{3},{4},{7},{6},{5}};
    int  k = 23;
    vector<vector<int>> res = shiftGrid(grid, k);
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}