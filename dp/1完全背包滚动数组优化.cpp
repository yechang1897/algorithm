#include<iostream>

using namespace std;

const int S = 1005;

int f[S];

int N, V;

int v[S], w[S];

int main() {
    scanf("%d %d", &N, &V);
    for(int i = 1; i <= N; i++) scanf("%d %d", &v[i], &w[i]);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= V; j++) {
            if(j >= v[i]) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d", f[V]);
    return 0;
}