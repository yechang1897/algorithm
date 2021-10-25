#include<iostream>
#include<vector>
using namespace std;

int visit[11][11];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

// bool check(int i, int j) {
//     if(i == 0 || j == 0) return true;
//     for(int k = 0; k < 4; k++) {
//         int x = i + dx[k], y = j + dx[k];

//         if(visit[x][y] != 1) return true;
//     }
//     return false;
// }

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int i = 0, j = 0;
    int m = matrix.size(), n = matrix[0].size();
    int dt = 0;
    vector<int> res;
    int flag = m * n;
    for(int k = 0; k < flag; k++) {
        // cout << i << " " << j << endl;
        res.push_back(matrix[i][j]);
        visit[i][j] = 1;
        int ni = i + dx[dt], nj = j + dy[dt];
        cout << ni << " " << nj << endl;
        cout << (ni < 0 || ni >= m || nj < 0 || nj >= n || visit[ni][nj]) << endl;
        if(ni < 0 || ni >= m || nj < 0 || nj >= n || visit[ni][nj]) {
            dt = (dt + 1) % 4;
        }
        // cout << dt << endl;
        i += dx[dt];
        j += dy[dt];
    }
    return res;
}

int main() {
    vector<vector<int>>  matrix = {{1,2,3},{4,5,6},{7,8,9}};

    for(auto x : spiralOrder(matrix)) {
        cout << x << " ";
    }
    return 0;
}