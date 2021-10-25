#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<vector<string>> ans;
vector<string> path;

bool check(string &now) {
    if(now.empty()) return false;
    int i = 0, j = now.size() - 1;
    while(i < j) {
        if(now[i] != now[j]) return false;
        i++, j--;
    }
    return true;
}

void dfs(string now, int u, string &s) {
    if(u == s.size()) {
        if(check(now)) {
            path.push_back(now);
            ans.push_back(path);
            path.pop_back();
        }
        return;
    }
    if(check(now)) {
        path.push_back(now);
        dfs("", u, s);
        path.pop_back();
    }
    dfs(now + s[u], u + 1, s);
}

vector<vector<string>> partition(string s) {
    dfs("", 0, s);
    return ans;
}

int main() {
    string s = "aab";
    for(auto vec : partition(s)) {
        for(auto str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
}