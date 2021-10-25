#include<iostream>
#include<cstring>
using namespace std;
const int N = 105;
int e[N], ne[N], h[N], idx;
bool vis[N];
int ans = N;
int n;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//遍历
void dfs(int a) {
    vis[a] = true;
    cout << a << endl;
    for(int i = h[a]; i != - 1; i = ne[i]) {
        int b = e[i];
        if(!vis[b]) dfs(b);
    }
}

int dfs2(int a) {
    vis[a] = true;
    int size = 0, sum = 0;
    for(int i = h[a]; i != -1; i = ne[i]) {
        int b = e[i];
        if(vis[b]) continue;
        int s = dfs2(b);
        sum += s;//累加子树结点的个数
        size = max(size, s);// 或许子树中最大节点个数
    }
    size = max(size, n - sum - 1);// 看当前子树与补树的大小是否相等
    ans = min(ans, size);//获取结果
    return sum + 1;//返回当前包含根节点的节点个数
}

int main() {
    cin >> n;
    // n--;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs2(1);
    cout << ans << endl;
    return 0;
}