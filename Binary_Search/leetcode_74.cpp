#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int lenX = (int)matrix.size();
    int lenY = matrix[0].size();
    int left = 0;
    int right = lenX * lenY - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(matrix[mid / lenY][mid % lenY] < target) {
            left = mid + 1;
        } else if(matrix[mid / lenY][mid % lenY] > target){
            right = mid - 1;
        } else {
            return true;
        }
    }
    return false;         
}

int main() {
    vector<vector<int>> matrix = {{1}};
    int target = 1;
    cout << searchMatrix(matrix, target);
}