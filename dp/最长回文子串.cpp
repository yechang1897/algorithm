#include<iostream>
#include<string.h>
#include<string>


using namespace std;
const int N = 1005;
bool f[N][N];

string longestPalindrome(string s) {
    int n = (int)s.size();

    for(int i = 0; i < n; i++) {
        f[i][i] = true;
    }

    for(int L = 2; L <= n; L++) {
        for(int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            if(s[i] == s[j] && i != j - 1) f[i][j] = f[i + 1][j - 1];
            else if(s[i] != s[j]) f[i][j] = false;
            else if(s[i] == s[j]&& i == j - 1) f[i][j] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
           cout << f[i][j] << " ";
        }
        cout << endl;
    }

    int maxN = -1;
    string res;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(f[i][j] == true) {
                if(maxN < j - i + 1) {
                    maxN = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return res;
}

int main() {
    string s = "ababd";
    cout << longestPalindrome(s) << endl;
    return 0;
}
