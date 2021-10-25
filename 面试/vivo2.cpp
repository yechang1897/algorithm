#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int N = 505;
int v[N];
int w[N];
int f[N];

int main() {
    int c;
    cin >> c;
    int sz = 1;
    while(1) {
        int vi;
        cin >> vi;
        v[sz++] = vi;
        if(getchar() == '\n') break;
    }
    sz = 1;
    while(1) {
        int wi;
        cin >> wi;
        w[sz++] = wi;
        if(getchar() == '\n') break;
    }
    for(int i = 1; i <= sz; i++) {
        for(int j = c; j >= v[i]; j--) {
           f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[c];
}