#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 
vector<int> res;
int vis[15];

void dfs(const string& s, int k, int n, string& t) {
    if(k == n) {
        res.push_back(t);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i] || (i > 0 && (![vis[i - 1]] && s[i - 1] == s[i]))) continue;

        t.push_back(s[i]);
        vis[i] = 1;
        dfs(s, k + 1, n, t);
        t.pop_back();
        vis[i] = 0;
    }
}

vector<string> permutation(string s) {
    vector<int> res;
    memset(vis, 0, sizeof vis);
    dfs(s, 0, s.size(), "");
    return res;
}

int main() {

}