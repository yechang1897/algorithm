#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> res;
    for(int i = 0; i <= rowIndex; i++) {
        vector<int> temp;
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                temp.push_back(1);
            } else {
                temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }
        res.push_back(temp);
    }
    return res.back();    
}

int main() {
    int rowIndex = 3;
    for(int i : getRow(rowIndex)) {
        cout << i <<" ";
    }
}