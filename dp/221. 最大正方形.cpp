#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maximalSquare(vector<vector<string>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> f(m + 1, vector<int>(m + 1));
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(matrix[i - 1][j - 1] == "0")
                f[i][j] = 0;
            else {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]);
                if(f[i][j] <= f[i - 1][j - 1])
                    f[i][j] = f[i][j] + 1;
                if(!f[i][j])
                    f[i][j] = 1;
            }
            res = max(res, f[i][j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return res * res;
}


int main() {
    vector<vector<string>> matrix = {{"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}};
    // vector<vector<string>> matrix = {{"0", "0", "0", "1"}, {"1", "1", "0", "1"}, {"1", "1", "1", "1"}, {"0", "1", "1", "1"}, {"0", "1", "1", "1"}};
    cout << maximalSquare(matrix);
    return 0;
}