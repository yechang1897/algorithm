#include<iostream>

using namespace std;

int addBit(int m, int n) {
        int res = 0;
        int cnt = 0;
        string str = to_string(m);
        for(int i = 0; i < str.size(); i++) {
           cnt += str[i] - '0';
        }
        res += cnt;
        cnt = 0;
        str = to_string(n);
        for(int i = 0; i < str.size(); i++) {
            cnt += str[i] - '0';
        }
        res += cnt;
        return res;
    }

bool vis[105][105];

int dfs(int i, int j, int m, int n, int k) {
    if(i >= m || j >= n || addBit(i, j) > k || vis[i][j]) return 0;
    vis[i][j] = true;
    return 1 + dfs(i + 1, j, m, n, k) + dfs(i, j + 1, m, n, k);    
}

int movingCount(int m, int n, int k) {
    return dfs(0, 0, m, n, k);   
}

int main() {
    int m = 2, n = 3, k = 1;
    cout << movingCount(m, n, k);
    return 0;
}