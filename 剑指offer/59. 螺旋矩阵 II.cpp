#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    vector<vector<bool>> vis(n, vector<bool>(n));
    int x = 0, y = 0;
    int dt = 0;
    for(int i = 1; i <= n * n; i++) {
        res[x][y] = i;
        vis[x][y] = true;
        int nx = x + dx[dt], ny = y + dy[dt];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) dt = (dt + 1) % 4;
        x += dx[dt];
        y += dy[dt];
    }
    return res;
}

int main() {
    // for(auto x : generateMatrix(3)){
    //     for(auto y : x) 
    //         cout << y << " ";
    //     cout << endl;
    // }
    long i = 19;
    long L = 5;
    float f = 9.8f;
    double d = 1.2;
    string s = "123";
    L = f + i;
    f = L + i;
    s = s + i + f + d;
    s = s + i;
    return 0;   
}