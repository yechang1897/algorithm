#include<iostream>

using namespace std;

int f[105];

int numWays(int n) {
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
    }
    return f[n];
}

int main() {
    int n = 2;
    cout << numWays(n) << endl;
}