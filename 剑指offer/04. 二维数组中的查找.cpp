#include<iostream>
#include<vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < m && matrix[j][i] <= target; j++) {
            cout << j << " " << i << endl;
            if(matrix[j][i] == target) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix =  {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 20;
    cout << findNumberIn2DArray(matrix, target);
}