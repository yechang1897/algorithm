#include<iostream>

using namespace std;

const int maxN = 1005;

int f[maxN];

int N, V;

int v[maxN], w[maxN];
//滚动数组优化的原理是，如果j是从小到大更新的话，f[j-v[i]]就已经更新了，不等价于f[i - 1][j - v[i]];

int main() {
    scanf("%d %d", &N, &V);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = V; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d", f[V]);
    return 0;
}