#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int maxRectInHistogram(int hist[], int n)       
{      
    int max_ = hist[0]; // 最大面积  
    int j = 0, k = 0, temp =0;
    for(int i=0; i<n; i++){    
            j = i, k = i;
            while(j < n&&hist[j] >= hist[i])j++;
            while(k >= 0&&hist[k] >=hist[i])k--;
            temp = (j-k-2 + 1)*hist[i];
            max_ = max(temp,max_);
    }      
    return max_;    
}

int maximalRectangle(vector<vector<int> > &matrix) {  
    if(matrix.size()==0) return 0;     
    int* hist = new int[matrix[0].size()];  
    memset(hist, 0, sizeof(int)*matrix[0].size());    
    int max_ = 0;    
    for(int i=0; i<(int)matrix.size(); i++){  
        for(int j=0; j<(int)matrix[0].size(); j++){  
            if(matrix[i][j]=='1')  *(hist+j) += 1;  
            else  *(hist+j) = 0;  
        }    
        max_ = max(max_, maxRectInHistogram(hist, matrix[0].size()) );  
    }     
    return max_;  
}   

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    vector<vector<int>> matrix;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = x3; i <= x4; i++) {
        for (int j = y3; j <= y4; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << maximalRectangle(matrix);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}