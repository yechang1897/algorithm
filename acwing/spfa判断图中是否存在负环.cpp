#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 10005;
int n, m;
int e[N], ne[N], h[N], w[N], idx = 0;
int dist[N], cnt[N];
bool vis[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true;
    }

    while(q.size()) {
        auto t = q.front();

        q.pop();

        vis[t] = false;

        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!vis[j]) {
                    q.push(j);
                    vis[j] = true;
                }  
            }
        }
    }
    return false;
}

int main() {
	cin>>n>>m;
	memset(h,-1,sizeof(h));
	for(int i=0;i<m;i++) {
		int a,b,c;	cin>>a>>b>>c;
		add(a,b,c);
	}
	if(spfa()) puts("Yes");
	else puts("No");
	return 0;
} 