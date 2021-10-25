#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool check(string& a) {
    for(int i = 0; i < a.size() - 1; i++) {
        if(a[i] > a[i + 1]) return false;
    }
    return true;
}

int res = INT_MAX;
int vis[14];

void dfs(string& a, int k) {
    if(check(a)) {
        res = min(res, k);
        return;
    }
    //cout << a << endl;
    for(int i = 1; i <= a.size(); i++) {
        if(!vis[i]) {
            vis[i] = 1;
            reverse(a.begin(), a.begin() + i);
            dfs(a, k + 1);
            reverse(a.begin(), a.begin() + i);
            vis[i] = 0;
        }
        
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < Q; i++) {
        string str;
        cin >> str;
        dfs(str, 0);
        cout << res << endl;
        res = INT_MAX;
    }

    return 0;
}