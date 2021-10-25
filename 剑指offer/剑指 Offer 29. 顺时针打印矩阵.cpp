#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int i = 0, j = 0;
    int m = matrix.size();
    int vis[m + 1][m + 1];
    int idx = 0;
    for(int k = 0; k < m * m; k++) {
        res.push_back(matrix[i][j]);
        vis[i][j] = 1;
        int x = i + dx[idx];
        int y = j + dy[idx];
        cout << i << " " << j << endl;
        cout << x << " " << y << endl;
        if(x < 0 || x >= m || y < 0 || y >= m || vis[x][y]) {            
            idx = (idx + 1) % 4;
        }
        i += dx[idx];
        j += dy[idx]; 
    }
    return res;    
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    for(auto x : spiralOrder(matrix)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}