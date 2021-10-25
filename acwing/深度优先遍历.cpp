#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1e6 + 5;

int e[N * 2], ne[N * 2], h[N];
bool vis[N];
int idx = 0;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(!vis[j]) dfs(j);
    }
}

int main() {
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i < n - 1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    return 0;

}