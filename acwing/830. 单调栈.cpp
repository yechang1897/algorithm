#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int stk[N], tt;

int main() {
    int N;
    cin >> N;
    while(N--) {
        int i;
        cin >> i;
        while(tt && i <= stk[tt]) tt--;
        if(!tt) printf("-1 ");
        else printf("%d ", stk[tt]);
        stk[++tt] = i; 
    }
    return 0;
}