#include<iostream>

using namespace std;

const int maxN = 100005;
int value[maxN];
int sum[maxN];
/*
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]
*/
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> value[i];
        sum[i] = sum[i - 1] + value[i];
    }
    while(m--) {
        int l, r;
        cin >> l >> r;
        int res = sum[r] - sum[l - 1];
        cout << res << endl;
    }
    return 0;
}