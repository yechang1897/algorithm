#include<iostream>
#include<vector>
using namespace std;

int a[8][8];
int fa[8];
int vis[8];

void build(char b, char c) {
    int f = b - 'a' + 1;
    int s = c - 'a' + 1;
    a[f][s] = 1;
}

int get(int x) {
   return fa[x] == x ? x : fa[x] = get(fa[x]);
}

int res;

void dfs(int l, int r) {
    if(l == r) {
        //初始化并查集
        for(int i = 1; i <= 7; i++) {
            fa[i] = i;
        }
        
        for(int i = 1; i <= 7; i++) {
            for(int j = 1; j <= 7; j++) {
                int fi = get(i), fj = get(j);
                if(a[i][j] && vis[i] && vis[j]) {
                    if(fi != fj) fa[fi] = fj;
                }
            }           
        }

        int cnt = 0;
        for(int i = 1; i <= 7; i++) {
            if(fa[i]==i && vis[i]) {
                cnt++;
            }
        }
        
        if(cnt == 1) res++;
        return;
    }

    dfs(l + 1, r);
    vis[l] = 1;
    dfs(l + 1, r);
    vis[l] = 0;
}

int main() {
    build('a', 'b');
    build('a', 'f');
    build('b', 'c');
    build('b', 'g');
    build('c', 'g');
    build('c', 'd');
    build('d', 'e');
    build('e', 'f');
    build('e', 'g');
    build('f', 'g');
    // cout << res;
    dfs(1, 8);
    // vector<int> n = {1, 3};
    // cout << check(n) << endl;
    // cout << ans << endl;
    cout << res << endl;
}