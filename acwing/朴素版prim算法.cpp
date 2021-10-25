#include<iostream>
#include<cstring>
using namespace std;

const int N = 10005, INF = 0x3f3f3f3f;;

int n, m;
int g[N][N];
int dist[N];
bool vis[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for(int i = 0;  i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        if(i && dist[t] == INF) return INF;

        if(i) res += dist[t];
        vis[t] = true;

        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    
    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        // 平行边只选边权最小的那个边
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}