#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<vector<char>> b;
vector<vector<bool>> visit;
string w;
int sx, sy;

int dx[4] = {-1, 0 , 1, 0}, dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y, int u) {
    if(u == w.size()) return true;

    visit[x][y] = true;
    for(int i = 0; i < 4; ++i) {
        int x1 = x + dx[i], y1 = y + dy[i];
        if(x1 >= 0 && x1 < sx && y1 >= 0 && y1 < sy && !visit[x1][y1] && b[x1][y1] == w[u]) {
            if(dfs(x1, y1, u + 1)) {
                return true;
            }
        }
    }
    visit[x][y] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    sx = board.size();
    sy = board[0].size();
    b = board;
    visit = vector<vector<bool>>(sx, vector<bool>(sy, false));
    w = word;
    for(int i = 0; i < sx; ++i) {
        for(int j = 0; j < sy; ++j) {
            if(board[i][j] == word[0]) {
                if(dfs(i, j, 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word);
}