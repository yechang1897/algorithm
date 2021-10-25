#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e6 + 5;

int e[N], ne[N], h[N], d[N];
int idx = 0;
int n, m;
vector<int> res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void toposort(){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(d[i] == 0)   q.push(i);
    while(!q.empty()){
        int v = q.front();  q.pop();
        res.push_back(v);
        for(int i = h[v]; i != -1; i = ne[i]){
            if( --d[e[i]] == 0)
                q.push(e[i]);
        }
    }
}

int main(void){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    toposort();
    if(res.size() == n){
        for(int i = 0; i < n; i++)
        cout << res[i] << " ";
        cout << endl;
    }
    else
        cout << -1;
    return 0;
}