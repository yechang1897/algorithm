#include<iostream>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int x = triangle.size();
    int y = triangle[x - 1].size();
    vector<vector<int>> f(x, vector<int>(y));
    f[0][0] = triangle[0][0];
    for(int i = 1; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            if(!j) f[i][j] = f[i - 1][j] + triangle[i][j]; 
            else if(i == j) f[i][j] = f[i - 1][j - 1] + triangle[i][j];
            else f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];
        }
    }

    //  for(int i = 0; i < x; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int res = INT_MAX;
    for(int i = 0; i < y; i++) {
        res = min(res, f[x - 1][i]);
    }
    return res;
}

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle);
    return 0;    
}
