#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
    string str = "abcacbbaac";
    int sz = str.size();
    int f[sz + 1][sz + 1];
    memset(f, 0, sizeof f);

    for(int i = 0; i < sz; i++) f[i][i] = 1;

    for(int i = 2; i <= sz; i++) {
        for(int j = 0; j < sz - i + 1; j++) {
            int k = j + i - 1;
            if(str[j] == str[k] && (k - j) == 1) f[j][k] = 2;
            if(str[j] == str[k] && f[j + 1][k - 1] != 0) f[j][k] = f[j + 1][k - 1] + 2;
        }
        // for(int j = i + 1; j < sz; j++) {
        //     if(str[i] == str[j] && (j - i) == 1) {
        //         f[i][j] = 2;
        //     }
        //     if(str[i] == str[j] && f[i + 1][j - 1] != 0) f[i][j] = f[i + 1][j - 1] + 2;            
        // }
    }
    int res = 0;
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            res = max(res, f[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}