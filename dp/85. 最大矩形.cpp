#include<iostream>
#include<vector>
#include<string>

using namespace std;
const int N = 205;
int f[N][N][3];

int maximalRectangle(vector<vector<string>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> left(cols, 0);      // 最左边的1位置 左边界
        vector<int> right(cols, cols);  // 右边界
        vector<int> height(cols, 0);
        int maxArea = 0;
        for (int i = 0; i < rows; ++i) {
            int curLeft = 0;            // 遇到的最右边的0的序号加1
            int curRight = cols;        // 遇到的最左边的0的序号

            cout << i << " " << endl;
            for (int j = 0; j < cols; ++j) {
                if(matrix[i][j] == "1")
                    height[j] += 1;
                else
                    height[j] = 0;
                cout << height[j] << " ";
            }
            cout << endl;
            // 更新left
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == "1")
                    left[j] = max(left[j],curLeft);
                else{
                    left[j] = 0;
                    curLeft = j + 1;
                }
                cout << left[j] << " ";
            }
            cout << endl;
            // 更新right
            for (int j = cols-1; j >=0 ; --j) {
                if (matrix[i][j] == "1")
                    right[j] = min(right[j],curRight);
                else{
                    right[j] = cols;
                    curRight = j;
                }
                cout << right[j] << " ";
            }
            cout << endl;
            // 更新最大面积
            for (int j = 0; j < cols; ++j) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j]));
            }

        //    for(int k = 0; k < cols; k++) cout << height[k] << " " << left[k] << " " << right[k] << endl;
        }
        return maxArea;
}

int main() {
    vector<vector<string>> matrix = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    vector<vector<string>> matrix2 = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << maximalRectangle(matrix);
}