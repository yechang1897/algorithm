#include<iostream>
using namespace std;

const int N = 1000005;
int a[N];
int n;

/*
求n的第k位数字: n >> k & 1
返回n的最后一位1：lowbit(n) = n & -n
*/

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        int  t = 0;
        for(int j = 0; j <= 11; j++) {
            if(a[i] >> j & 1) t++;
        }
        cout << t << " ";
    }
    puts("");

    return 0;
}