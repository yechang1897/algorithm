#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> c(n, vector<bool>(n, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j + i - 1 < n; j++) {
            int l = j, r = j + i - 1;
            c[l][r] = s[l] == s[r] && (l + 1 > r - 1 || c[l + 1][r - 1]);
        }
    }
    for(auto x : c) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    vector<int> f(n + 1);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = INT_MAX;
        for (int j = 1; j <= i; j++) {
            if (c[j - 1][i - 1]) {
                f[i] = min(f[i], f[j - 1] + 1);
            }
        }
    }
    return f[n] - 1;
}

int main() {
    string s = "aab";
    cout << minCut(s);
}