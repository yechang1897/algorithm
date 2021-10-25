#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int getMax(vector<string>& value_matrix, int row, int col) {
    vector<vector<int>> nums;
    for(int i = 0; i < value_matrix.size();i++) {
        string str = value_matrix[i];
        vector<int> temp;
        temp.clear();
        int t = 0;
        for(int j = 0; j < str.size();j++) {
            if(str[j] == ',') {
                temp.push_back(t);
                t = 0;
            } else {
                t = t * 10 + (str[j] - '0');
            }
        }
        temp.push_back(t);
        nums.push_back(temp);
    }
    int res = INT_MIN, s, e, s2, e2;
    s = (row) ? row - 1: row;
    e = (row == (nums[0].size() - 1)) ? row : row + 1;
    s2 = (col) ? col - 1 : col;
    e2 = (col == nums.size() - 1) ? col : col + 1;
    for(int i = s; i <= e; i++) {
        for(int j = s2; j <= e2; j++) {
            if(i == row && j == col) continue;
            res = max(res, nums[i][j]);
        }
    }
    return res;
}

int main() {
    vector<string> value_matrix = {"6,2,8,6,7", "5,8,1,4,9", "1,3,5,2,1", "4,1,1,4,1", "3,6,5,2,1"};
    cout << getMax(value_matrix, 2, 2);
}