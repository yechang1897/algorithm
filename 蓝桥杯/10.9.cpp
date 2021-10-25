#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3e5 + 10;
int T;
int a[N];
int res;

int findMax(int s, int e) {
    return max(max(abs(a[s]), abs(a[s + 1])), abs(a[e]));
}

void transfer(int n) {
    for(int i = 2; i < n; i++) {
        int maxNum = findMax(i - 1, i + 1);
        if(abs(a[i - 1] + a[i]) < maxNum && abs(a[i] + a[i + 1]) < maxNum) {
            a[i - 1] += a[i];
            a[i + 1] += a[i];
            a[i] *= -1;
        }
    }
    res = *max_element(a + 1, a + n + 1);
}

int main() {
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        transfer(n);
        cout << res << endl;
    }
}