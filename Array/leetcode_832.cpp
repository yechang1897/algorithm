#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int x = A.size();
    int y = A[0].size();
    for(int i = 0; i < x; i++) {
        reverse(A[i].begin(), A[i].end());
    }
    for(int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            A[i][j] > 0 ? A[i][j]-- : A[i][j]++;
        }
    }
    return A;
}

int main() {
    vector<vector<int>> A = {{1,1,0},{1,0,1},{0,0,0},{}};
    flipAndInvertImage(A);
}