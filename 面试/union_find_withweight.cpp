#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int fa[N], sz[N], dist[N];
int n;

void init() {
    for(int i = 1; i <= n; i++) {
        fa[i] = i, sz[i] = 1, dist[i] = 0;
    }
}

int get(int x) {
    if(fa[x] == x) {
        return x;
    }
    int y = fa[x];
    fa[x] = get(y);
    dist[x] += dist[y];
    return fa[x];
}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if(a != b) {
        fa[a] = b;
        dist[a] = size[b];
        size[b] += size[a];
    }
}