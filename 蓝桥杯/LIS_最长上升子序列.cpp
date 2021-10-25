#include<iostream>

using namespace std;

const int N = 2505;
int a[N];
int f[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int res = 0;
    for(int i = 1; i <= n + 1; i++) {
        f[i] = 1;
        for(int j = i; j >= 0; j--) {
            if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    for(int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << endl;
    cout << res << endl;
    return 0;
}