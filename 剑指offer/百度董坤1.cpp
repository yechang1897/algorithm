#include<iostream>
#include<vector>
using namespace std;

int main() {
    int M,N;
    cin >> M >> N;
    vector<vector<int>> nums(M, vector<int>(N));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> nums[i][j];
        }
    } 
    vector<vector<int>> res(M * M, vector<int>(N * N));
    for(int i = 0; i < M * M; i++) {
        for(int j = 0; j < N * N; j++) {
            int x = i / M;
            int y = j / N;
            res[i][j] = nums[x][y];
        }
    }
    for(int i = 0; i < M * M; i++) {
        for(int j = 0; j < N * N; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}