#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<string>> res;
vector<string> path;

bool check(string s) {
    if(s.empty()) return false;
    int sz = s.size();
    if(sz == 1) return true;
    bool res = true;
    int l = 0, r = sz - 1;
    while(l < r) {
        if(s[l] != s[r]) {
            res = false;
            break;
        } else {
            l++, r--;
        }
    }
    return res;
}

void dfs(string now, int l, string& s){
    if(l == (int)s.size()) {
        if(check(now)) {
            path.push_back(now);
            res.push_back(path);
            path.pop_back();
        }
        return;
    }
    //在l处分割
    if(check(now)) {
        path.push_back(now);
        dfs("", l, s);
        path.pop_back();
    }
    //不在l分割
    dfs(now + s[l], l + 1, s);
}
 
vector<vector<string>> partition(string s) {
    dfs("", 0, s);
    return res;
}

int main() {
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (auto x : ans) {
        for (auto y : x) {
            cout << y <<" ";
        }
        cout << endl;
    }
    return 0;
}