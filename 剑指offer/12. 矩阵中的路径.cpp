#include<iostream>
#include<vector>
#include<string>
using namespace std;

int row, col;

bool dfs(vector<vector<char>>& board, string& word, int i , int j, int k) {
    if(i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k]) return false;
    if(k == word.size() - 1) return true;
    board[i][j] = '\0';
    bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1)
    || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
    board[i][j] = word[k];
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    row = board.size();
    col = board[0].size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            return dfs(board, word, i, j, 0);
        }
    }
    return false;
}

int main() {
    // vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board  = {{'a', 'a'}};
    // string word = "ABCCED";
    string word = "aa";
    // cout << ("ABCCED" == "ABCCE") << endl;
    cout << exist(board, word);
}