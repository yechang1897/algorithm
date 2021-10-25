#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int fa[N];
int n;
int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

int main() {
    cin >> n;
    for(int i = 0; i < N; i++) {
        fa[i] = i;
    }
    while(n--) {
        int a;
        cin >> a;
        a = get(a);
        cout << a << " ";
        fa[a] = a + 1;
    }
    puts("");
}