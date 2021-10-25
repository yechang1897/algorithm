#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int father1[N];

int get(int x) {
    if(father1[x] == x) {
        return x;
    }
    return father1[x] = get(father1[x]); 
}


void merger(int x, int y) {
    x = get(x);
    y = get(y);
    if(x != y) {
        father1[y] = x;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int water[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &water[i]);
    }
    for(int i = 1; i <= n; i++) {
        father1[i] = i;
    }
    while(m--) {
        int m1, m2;
        scanf("%d %d", &m1, &m2);
        merger(m1, m2);
    }
    int f[n][2];
    for(int i = 0; i < n; i++) {
       f[i][0] = 0;
       f[i][1] = 0;
    }
    for(int i = 0; i < n; i++) {
        f[get(i + 1)][0] = f[get(i + 1)][0] + water[i];        
        f[get(i + 1)][1] = f[get(i + 1)][1] + 1; 
    }
    for(int i = 0; i < n; i++) {
        f[i][0] = f[get(i + 1)][0];
        f[i][1] = f[get(i + 1)][1];
    }
    for(int i = 0; i < n; i++) {
        double res = f[i][0] * 1.0 / f[i][1];
        printf("%.2f ", res);
    }
    return 0;
}