#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int f[N];
int a[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[1] = a[1];
    int res = 0;
    for(int i = 2; i <= n; i++) {
        f[i] = max(f[i - 1] + a[i], a[i]);
        res = max(res, f[i]);
    }
    // for(int i = 1; i <= n; i++) cout << f[i] << " ";
    cout <<res <<endl;
    // cout << *max_element(f + 1, f + 1 + n) << endl;
}