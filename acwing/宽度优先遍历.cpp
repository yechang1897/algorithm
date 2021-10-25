#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e6 + 5;

int e[N], ne[N], h[N];
int idx = 0;
bool vis[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u) {
    queue<int> q;
    vis[u] = 1;
    q.push(u);
    while(q.size()) {
        int t = q.front();
        cout << t << " ";
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(!vis[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    bfs(1);
    return 0;
}