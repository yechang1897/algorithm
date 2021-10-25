#include<iostream>
#include<string.h>
using namespace std;

int climbStairs(int n) {
    int f[n + 1];
    memset(f, 0, sizeof(n));
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    cout << climbStairs(3);
}