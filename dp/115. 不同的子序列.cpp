#include<iostream>
#include<string>
#include<vector>

using namespace std;

int numDistinct(string s, string t) {
    int ss = s.size();
    int st = t.size();

    vector<vector<unsigned long long >> f(ss + 1, vector<unsigned long long>(st + 1, 0));

    for(int i = 0; i <= ss; i++) {
        f[i][0] = 1;
    }

    for(int i = 1; i <= ss; i++) {
        for(int j = 1; j <= st; j++) {
            f[i][j] = f[i - 1][j];
            if(s[i - 1] == t[j - 1]) {
                f[i][j] += f[i - 1][j - 1];
            }
        }
    }

    for(int i = 0; i <= ss; i++) {
        for(int j = 0; j <= st; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    return f[ss][st];
}

int main() {
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t);
    return 0;
}