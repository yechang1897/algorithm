#include<iostream>
#include<cmath>
using namespace std;

const int N = 3e4 + 10;
int T;
int fa[N], sz[N], dist[N];

int get(int x) {
    if(fa[x] == x){
        return x;
    }

    // int y = fa[x];
    // fa[x] = get(y);
    // dist[x] += dist[y];
    // return fa[x];

    // int y = fa[x];
    // fa[x] = get(y);
    // dist[x] += dist[y];
    // return fa[x];
    dist[x] += dist[fa[x]];
    fa[x] = get(fa[x]);
    return fa[x];
}

// int get2(int x) {
//     if (fa[x] != x) {
//         int p = get2(fa[x]);
//         d[x] += d[fa[x]];
//         fa[x] = p;
//     }
//     return fa[x];
// }

int main() {
    cin >> T;
    for(int i = 1; i <= 30000; i++) {
        fa[i] = i, sz[i] = 1; 
    }
    while(T--) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        int fb = get(b), fc = get(c);
        if(a == 'M') {            
            dist[fb] = sz[fc];
            sz[fc] += sz[fb];
            fa[fb] = fc;
        } else if(a == 'C') {
            if(fb == fc) {
                cout << max(0 , abs(dist[c] - dist[b]) - 1) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}