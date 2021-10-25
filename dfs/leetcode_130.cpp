#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(vector<vector<char>>& board, int i, int j) {
    board[i][j] = 'Y';
    for(int k = 0; i < 4; ++i) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O') {
            dfs(board, x, y);
        }
    }
}


void solve(vector<vector<char>>& board) {
    if(board.empty() || board[0].empty()) return;
    n = board.size();
    m = board[0].size();
    for(int i = 0; i < n; ++i) {
        if(board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if(board[i][m - 1] == 'O') {
            dfs(board, i, m - 1);
        }
    }
    for(int i = 0; i < m; ++i) {
        if(board[0][i] == 'O') {
            dfs(board, 0, i);
        }
        if(board[n - 1][i] == 'O') {
            dfs(board, n - 1, i);  
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << "";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if(board[i][j] == 'Y') {
                board[i][j] = 'O';
            }
        }
    }
}


int main() {
    vector<vector<char>> boards = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(boards);
}