#include<iostream>

using namespace std;

const int N = 305;
int f[N][N];
int s[N];

int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &s[i]), s[i] += s[i - 1];
    
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            f[i][j] = 1e8;
            for(int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    printf("%d", f[1][n]);
    return 0;
}

/**
4
1 3 5 2

22
**/