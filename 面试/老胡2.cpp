#include<iostream>
#include<cstring>
#include<string>
#include<unordered_set>
using namespace std;

const int N = 13;
int vis[N][N];
int res;
int n, m;

unordered_set<string> set;



void setKinds() {
    string res = "";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res += to_string(vis[i][j]);
        }
    }
    set.insert(res);
}

void dfs(int i, int j) {
    if(i > n || j > m) return; 
    
    if(i == n && j == m) {
        // cout << "test" << endl;
        setKinds();
        return;
    }

    
    
    if(vis[i + 1][j] != 1 && vis[i + 1][j] != -1)
        dfs(i + 1, j);
    if(vis[i][j + 1] != 1 && vis[i][j + 1] != -1)
        dfs(i, j + 1);
    
    if(vis[i + 1][j - 1] != 1 && vis[i][j] != 1) {
        vis[i + 1][j] = 1;
        dfs(i + 1, j);
        vis[i + 1][j] = 0;
    }
   
    if(vis[i][j] != 1 && vis[i - 1][j + 1] != 1) {
        vis[i][j + 1] = 1;
        dfs(i, j + 1);
        vis[i][j + 1] = 0;
    }    
}

int main() {    
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if(a == 0) vis[i][j] = -1;
        }
    }
    dfs(0, 0);
    cout << set.size();
}