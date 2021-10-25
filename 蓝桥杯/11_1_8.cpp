#include<iostream>
#include<string>
using namespace std;

typedef long long LL;

const int N = 100010, M = 150;
string s;
int Pre[N], Next[N], idx[M];

int main() {
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    for(int i = 1; i <= n; i++) {
        Pre[i] = idx[s[i]];
        idx[s[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        cout << Pre[i] << " ";
    }
    cout << endl;
    
    // cout << "test1" << endl;
    for(int i = 97; i <= 122; i++) idx[i] = n + 1;
    // cout << "test2" << endl;
    for(int i = n; i >= 1; i--) {
        Next[i] = idx[s[i]];
        idx[s[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        cout << Next[i] <<" ";
    }
    cout << endl;
    // cout << "test3" << endl;
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (LL)(i - Pre[i]) * (Next[i] - i);
        cout << ans << " ";
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}