#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e3 + 5;
int g[N][N];
int dist[N];
bool vis[N];
int n, m;

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < n - 1; i++) {
        int t = -1;
        for(int j = 0; j <= n; j++) {
            if(!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        for(int j = 0; j <= n; j++) {
            dist[j] = min(dist[j], (dist[t] + g[t][j]));
        }
        vis[t] = true;
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w);
    }
    cout << dijkstra();
    return 0;
}
