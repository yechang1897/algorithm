#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<char> allows[7][7];

bool dfs(string& last, string now) {
    if(last.size() == 1) {
        return true;
    }
    if(now.size() + 1 == last.size()) {
        return dfs(now, "");
    }

    int a = last[now.size()] - 'A', b = last[now.size() + 1] - 'A';
    for(auto c : allows[a][b]) {
        if(dfs(last, now + c)) {
            return true;
        }
    }
    return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
    for(auto item : allowed) {
        int a = item[0] - 'A', b = item[1] - 'A', c = item[2];
        allows[a][b].push_back(c);
    }
    return dfs(bottom, "");
}

int main() {
    // string bottom = "AABA";
    string bottom = "BCD";
    vector<string> allowed = {"BCG", "CDE", "GEA", "FFF"};
    cout <<  pyramidTransition(bottom, allowed);
}