#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 10005;

int n, m;
int e[N], w[N], ne[N], h[N], idx = 0;
int dist[N];
bool vis[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c,ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(q.size()) {
       int t = q.front();
       q.pop();
       vis[t] = false;

       for(int i = h[t]; i != -1; i = ne[i]) {
           int j = e[i];
           if(dist[j] > dist[t] + w[i]) {
               dist[j] = dist[t] + w[i];
               if(!vis[j]) {
                   q.push(j);
                   vis[j] = true;
               }
           }
       } 
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = spfa();

    if (t == -1) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}