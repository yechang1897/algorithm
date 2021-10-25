#include<iostream>

using namespace std;

const int S = 1005;

int f[S][S];

int N, V;

int v[S], w[S];

int main() {
    scanf("%d %d", &N, &V);
    for(int i = 1; i <= N; i++) scanf("%d %d", &v[i], &w[i]);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    printf("%d", f[N][V]);
    return 0;
}
/**
*
4 5
1 2
2 4
3 4
4 5

10
*/

