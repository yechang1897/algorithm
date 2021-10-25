#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int projectionArea(vector<vector<int>>& grid) {
    int xy = 0;
    int yz = 0;
    int xz = 0;
    int x = grid.size();
    int y = grid[0].size();
    xy = x * y;
    for(int i = 0; i < x; ++i) {
        for (int j = 0 ; j < y; ++j) {
            if(grid[i][j] == 0) {
                xy --;
            }
        }
    }
    cout << xy << endl;
    vector<int> max1(x, 0);
    for(int i = 0; i < x; ++i) {
        for (int j = 0 ; j < y; ++j) {
            max1[i] = max(max1[i], grid[i][j]);
        }
    }
    for (int i : max1) {
        yz += i;
    }
    cout << yz << endl;
    vector<int> max2(y, 0);
    for(int i = 0; i < y; ++i) {
        for (int j = 0 ; j < x; ++j) {
            max2[i] = max(max2[i], grid[j][i]);
            cout << grid[j][i] << endl;
        }
    }
    for (int i : max2) {
        xz += i;
    }
    cout << xz << endl;
    return xy + xz + yz;
}

int main() {
    vector<vector<int>> grid = {{2,3},{2,4}};
    cout << projectionArea(grid);
}