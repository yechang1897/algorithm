#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m;
int h[N], e[N], ne[N], w[N], idx = 0;
int dist[N];

bool vis[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if(vis[ver]) continue;
        vis[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > distance + w[j]) {
                dist[j] = distance + w[j];
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}

/**
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
**/