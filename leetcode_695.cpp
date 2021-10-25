#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxAreaOfIsland(vector<vector<int>> &grid) {
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> dp(R);
    for(int i = 0; i < R; i++) {
        dp[i].resize(C);
    }
    dp[0][0] = grid[0][0];
    for (int j = 1; j < C; j++) {
        if (grid[0][j] == 0) {
            dp[0][j] = 0;
        } else if(grid[0][j] == 1){
            dp[0][j] = grid[0][j];
            if(dp[0][j - 1] != 0){
                dp[0][j] = dp[0][j - 1] + 1;
                for (int k = j - 1; k >= 0; k--) {
                    if (dp[0][k] != 0) {
                        dp[0][k] = dp[0][j];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i < R; i++)
    {
        if (grid[i][0] == 0) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = grid[i][0];
            if(dp[i - 1][0] != 0){
                dp[i][0] = dp[i - 1][0] + 1;
                for (int j = i - 1; j >= 0; j--) {
                    if(dp[j][0] != 0) {
                        dp[j][0] = dp[i][0];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    int maxIsland = -1;
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if(grid[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                if(grid[i - 1][j - 1] != 0){
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
                    for (int k = j - 1; k >= 0; k--) {
                        if(dp[i][k] != 0) {
                            dp[i][k] = dp[i][j];
                        } else {
                            break;
                        }
                    }
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
                    for (int k = j - 1; k >= 0; k--) {
                        if(dp[i][k] != 0) {
                            dp[i][k] = dp[i][j];
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(maxIsland < dp[i][j]) {
                maxIsland = dp[i][j];
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return maxIsland;
}

vector<vector<int>> visit;
vector<vector<int>> grids;

int dfs(int R, int C) {
    if(R < 0 || C < 0 || R >= (int)grids.size() || C >= (int)grids[0].size() || visit[R][C] || grids[R][C] == 0) {
        return false;
    }
    visit[R][C] = true;
    return 1 + dfs(R + 1, C) + dfs(R, C + 1) + dfs(R - 1, C) + dfs(R, C - 1);
}

int maxAreaIsland_2(vector<vector<int>> &grid) {
    grids = grid;
    vector<vector<int>> temp(grids.size(), vector<int>(grids[0].size(), 0));
    visit = temp;
    int res = 0;
    for (int i = 0; i <(int) grids.size(); i++) {
        for (int j = 0; j <(int) grids[0].size(); j++) {
            res = max(res, dfs(i, j));
        }
    }
    return res;
}


int main() {
    // vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    vector<vector<int>> grid = {{0,1,1}};
    // vector<vector<int>> grid = {{0},{1}};
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5;j++) {
    //         cin >> grid[i][j];
    //     }
    // }
    cout << maxAreaIsland_2(grid);
    return 0;
}