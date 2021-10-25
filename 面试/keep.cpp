#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<string> grid;
int n, m;
const int maxN = 105;

bool vis[maxN][maxN];

bool check() {

    if(grid[0][0] == grid[0][1] || grid[0][0] == grid[1][0]) {
        return false;
    }

    if(grid[n - 1][m - 1] == grid[n - 2][m - 1] || grid[n - 1][m - 1] == grid[n - 1][m - 2]) {
        return false;
    }

    if(grid[0][m - 1] == grid[1][m - 1] || grid[0][m - 1] == grid[0][m - 2]) {
        return false;
    }

    if(grid[n - 1][0] == grid[n - 2][0] || grid[n - 1][0] == grid[n - 1][1]) {
        return false;
    }

    for (int i = 1; i < m - 1; i++) {
        if(grid[0][i] == grid[0][i - 1] || grid[0][i] == grid[0][i + 1]) {
            return false;
        }
    }

    for (int i = 1; i < m - 1; i++) {
        if(grid[n - 1][i] == grid[n - 1][i - 1] || grid[n - 1][i] == grid[n - 1][i + 1]) {
            return false;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        if(grid[i][0] == grid[i + 1][0] || grid[i][0] == grid[i - 1][0]) {
            return false;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        if(grid[i][m - 1] == grid[i + 1][m - 1] || grid[i][m - 1] == grid[i - 1][m - 1]) {
            return false;
        }
    }
    for (int x = 2; x < n; x++)
    {
        for (int y = 2; y < m; y++)
        {
            if (grid[x + 1][y] == grid[x][y])
            {
                return false;
            }
            if (grid[x - 1][y] == grid[x][y])
            {
                return false;
            }
            if (grid[x][y + 1] == grid[x][y])
            {
                return false;
            }
            if (grid[x][y - 1] == grid[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

void fill(int x, int y, char color) {
    grid[x + 1][y] = color;
    grid[x - 1][y] = color;
    grid[x][y + 1] = color;
    grid[x][y - 1] = color;
}



vector<string> fun(int i , int j) {
    queue<pair<int, int>> que;
    que.push({i, j});
    bool flag = true;
    while(!que.empty()) {
        auto p = que.front();
        int x = p.first;
        int y = p.second;
        char color = grid[x][y];
        if (color == 'R'){
            color = 'W';
        }
        else {
            color = 'R';
        }
        fill(x, y, color);
        que.push({x - 1, y});
        que.push({x + 1, y});
        que.push({x, y - 1});
        que.push({x, y + 1});

        if(!check()) {
            flag = false;
            break;
        }
    }
    vector<string> res;
    if(flag)
        res = {"YES"};
    else
        res = {"NO"};
    for (int i = 0; i < n; i++) {
        res.push_back(grid[i]);
    }
    return res;
}

int main() {

}