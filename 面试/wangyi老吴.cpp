#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

char m[10][10];
int R, C;
int Y;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int visit[10][10];
int endX, endY;
int minS = INT_MAX;

void dfs(int i, int j, int step) {
    if(m[i][j] == 'T') {
        minS = min(minS, step);
        return;
    }
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if(0 <= x  && x < R && 0 <= y && y < C && m[x][y] != '#' && !visit[x][y]) {
            visit[x][y] = 1;
            dfs(x, y, step + 1);
            visit[x][y] = 0;
        }
            
    }
}

vector<vector<int>> all;
vector<int> nums;

void enmueration(int k, int m) {
    if((int)nums.size() > m || (nums.size() + (Y - k + 1)) < m) 
        return;
    if(k == Y + 1) {
        all.push_back(nums);
        return;
    }
    enmueration(k + 1, m);
    nums.push_back(k);
    enmueration(k + 1, m);
    nums.pop_back();
}

int main() {
    int X;
    cin >> R >> C >> Y >> X;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> m[i][j];
        }
    }
    char t[10][10];
    memcpy(t,m,sizeof(m));
    int sX,sY;
    vector<pair<int,int>> backup;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(m[i][j] == 'S') {
                sX = i, sY = j;
            }
            if(m[i][j] == '?') {
                backup.push_back(make_pair(i, j));
            }
        }    
    }
    enmueration(1,X);
    int ans = 0;
    visit[sX][sY] = 1;
    for(int i = 0 ; i < all.size(); i++) {
        memcpy(m,t,sizeof(t));
        for(int j = 0; j < X; j++) {
            int x = backup[all[i][j] - 1].first;
            int y = backup[all[i][j] - 1].second;
            m[x][y] = '#';
        }
        dfs(sX, sY, 1);
        if(minS == INT_MAX) {
            minS = -1;
        }
        ans = max(ans, minS);
        minS = INT_MAX;
    }
    cout << ans << endl;
}