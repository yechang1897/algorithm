#include<iostream>

using namespace std;

const int maxN = 1005;

int f[maxN][maxN];

int N, V;

int v[maxN], w[maxN];

int main() {
    scanf("%d %d", &N, &V);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    printf("%d", f[N][V]);
    return 0;
}