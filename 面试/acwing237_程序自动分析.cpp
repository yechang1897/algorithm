#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;
int fa[N];
int t, n;
struct node{
    int x, y,e;
     bool operator < (const node &r) const{
        return e > r.e;
    }
}a[N];
vector<int> v;

int get(int x) {
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main() {
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        for(int j = 1; j <= min(N, 2 * n); j++) {
            fa[j] = j;
        }
        for(int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].e;
            v.push_back(a[i].x);
            v.push_back(a[i].y);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        bool flag = false;
        sort(a + 1, a + n + 1);
       
        for(int i = 1; i <= n; i++) {
            int x1 = lower_bound(v.begin(), v.end(), a[i].x) - v.begin() + 1;
            int y1 = lower_bound(v.begin(), v.end(), a[i].y) - v.begin() + 1;
            if(a[i].e) {
                cout << x1 << " " << y1 << endl;
                fa[get(x1)] = get(y1);
            } else {
                int fx = get(x1), fy = get(y1);
                if(fx == fy){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;       
}