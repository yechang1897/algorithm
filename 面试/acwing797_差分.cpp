#include<iostream>
#include<algorithm>

using namespace std;

const int maxN = 100005;
int a[maxN], b[maxN];
int n, m;
/*
给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
*/
void insert(int b[], int l , int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(b, i, i, a[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    puts("");

    while(m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(b, l, r, c);
    }

    for(int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    puts("");

    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + b[i];
        cout << a[i] << " ";
    }
    puts("");
}