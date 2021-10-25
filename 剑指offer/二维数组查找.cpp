#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    int target;
    cin >> target;
    int row = 0, col = m - 1;
    while(row < n && col > 0) {
        if(nums[row][col] == target) {
            cout << "true" << endl;
            return 0;
        }
        else if(nums[row][col] > target) col--;
        else row++;
    }
    cout << "false" << endl;
    return 0;
}
