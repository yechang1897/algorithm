#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
    vector<vector<int>> res;
    int x = A[0].size();
    int y = A.size();
    for (int i = 0; i < x; i++) {
        vector<int> temp;
        for (int j = 0; j < y; j++) {
            temp.push_back(A[j][i]);
        }
        res.push_back(temp);
    }
    return res;
}

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> res = transpose(A);
    for(vector<int> v : res) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}