#include<iostream>

using namespace std;

const int N = 5e4 + 10;

int fa[N];
int n, m, p;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int A, B;
    for(int i = 0; i < m; i++) {
        cin >> A >> B;
        fa[find(A)] = find(B);
    }

    for(int i = 0; i < p; i++) {
        int f, s;
        cin >> f >> s;
        if(find(f) == find(s)) cout << "YES";
        else cout << "NO";
        if(i != p - 1) cout << endl;
    }
}

/*
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
*/