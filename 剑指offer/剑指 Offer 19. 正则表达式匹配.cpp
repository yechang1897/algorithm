#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    bool f[m + 1][n + 1];
    memset(f, false, sizeof f);
    f[0][0] = true;

    for(int j = 2; j <= n; j += 2) {
        f[0][j] = f[0][j - 2] && (p[j - 1] == '*');
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[j - 1] == '*') {
                if(f[i][j - 2]) f[i][j] = true;
                else if(f[i - 1][j] && s[i - 1] == p[j - 2]) f[i][j] = true;
                else if(f[i - 1][j] && p[j - 2] == '.') f[i][j] = true; 
            } else {
                if(f[i - 1][j - 1] && s[i - 1] == p[j - 1]) f[i][j] = true;
                else if(f[i - 1][j - 1] && p[j - 1] == '.') f[i][j] = true;
            }
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return f[m][n];
}

int main() {
    string s = "aa";
    string p = "a*";
    cout << isMatch(s, p);
}