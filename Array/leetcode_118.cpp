#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for(int i = 0; i < numRows; i++) {
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
    return res;     
}

int main() {
    int a = 5;
    for(vector<int> vec : generate(a)) {
        for(int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
}