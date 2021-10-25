#include<iostream>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge{
    int a, b, w;
} edges[M];


int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n] > 0x3f3f3f3f / 2 ? -1 : dist[n];
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    int res = bellman_ford();
    cout << res << endl;
}

/**
3 3 1
1 2 1
2 3 1
1 3 3
**/