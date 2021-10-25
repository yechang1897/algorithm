#include<iostream>
using namespace std;

const int N = 107;
int que[N], a[N], hh, tt = -1;
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(hh <= tt && que[hh] < i - k + 1) hh++;
        while(hh <= tt && a[que[tt]] > a[i]) tt--;
        que[++tt] = i;
        if(i > k - 1) cout << a[que[hh]] << " ";
    }
    puts("");
    hh = 0, tt = -1;
    for(int i = 1; i <= n; i++) {
        if(hh <= tt && que[hh] < i - k + 1) hh++;
        while(hh <= tt && a[que[tt]] < a[i]) tt--;
        que[++tt] = i;
        if(i > k - 1) cout << a[que[hh]] << " ";
    }
    return 0;
}