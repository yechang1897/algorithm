#include<iostream>
#include<vector>
using namespace std;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int res = 0;
int temp = 0;
bool vis[105][105];
void dfs(vector<vector<int>> grid, int i, int j) {
    // cout << i << " " << j << endl;
    if(!grid[i][j]) return;
    
    
    res = max(temp, res);
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !vis[x][y]) {
            vis[i][j] = true;
            temp += grid[i][j];
            res = max(res, temp);
            dfs(grid, x, y);
            temp -= grid[i][j];  
            vis[i][j] = false;          
        }
    }

}

int getResourse(vector<vector<int>> grid) {
    int ans = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size();j++){
            temp = 0;
            res = 0;
            dfs(grid, i, j);
            ans = max(res, ans);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{0, 6, 0}, {5, 8 ,7}, {0, 9, 0}};
    cout << getResourse(grid);
}