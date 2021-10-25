#include<iostream>
#include<vector>
using namespace std;

bool greater1(vector<int> a, vector<int> b) {
    for(int i = 0; i < 3; i++) {
        if(a[i] > b[i]) return false;
    }
    return true;
}

void add(vector<int> a, vector<int>& b) {
    for(int i = 0; i < 3; i++) {
        b[i] += a[i];
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> growup(m, vector<int>(3));
    vector<vector<int>> skill(n, vector<int>(3));
    for(int i = 0; i < m; i++) {
        cin >> growup[i][0] >> growup[i][1] >> growup[i][2];
    }
    for(int i = 0; i < n; i++) {
        cin >> skill[i][0] >> skill[i][1] >> skill[i][2];
    }

    vector<int> ans;
    vector<int> state(3, 0);
    int flag = 0;
    for(int i = 0; i < m; i++) {
        add(growup[i], state);
        // cout << growup[i][0] << endl;
        // cout << greater1(skill[flag], state) << endl;
        if(greater1(skill[flag], state)) {
            flag++;
            ans.push_back(i + 1);
        }
    }
    while(ans.size() < m) {
        ans.push_back(-1);
    }
    for(auto x : ans) cout << x << " ";
    return 0;
}