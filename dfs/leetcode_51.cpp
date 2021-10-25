#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;

vector<vector<string>> solveNQueens(int n) {
    
}

int main() {
    int n = 4;
    vector<vector<int>> res;
    res = solveNQueens(n);
    for (vector v : res) {
        for (int i : v) {
            cout << i " ";
        }
        cout << endl;
    }
}