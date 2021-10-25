#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;

int mininumTotal(vector<vector<int>> &triangle) {
    int X = triangle.size();
    // for (int i = 1; i < X; i++) {
    //     triangle[i][0] += triangle[i - 1][0];
    // }
    for (int i = 1; i < X; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if(j == i) {
                triangle[i][j] += triangle[i - 1][j - 1]; 
            } else {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < X; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
    return *min_element(triangle[X - 1].begin(), triangle[X - 1].end());
}

int mininumTotal_2(vector<vector<int>> &triangle) {
    int n=triangle.size();
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++)
            dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
    }
    return dp[0];
}

int main() {
    vector<vector<int>> triangle = {{2},
                                   {3, 4},
                                   {6, 5, 7},
                                   {4, 1, 8, 3}};
    cout << mininumTotal(triangle);
}