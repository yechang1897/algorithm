#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
typedef long long int ll;

ll N;
//高精度加法 + 高精度除法

ll fib(ll n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    ll a = 1, b = 1;
    for(ll i = 0; i < n - 2; i++) {
        ll t = a + b;
        a = b;
        b = t;
    }
    return b;
}

int main() {
    cin >> N;
    double res = 0;
    if(N > 20) {
        cout << "0.61803399" << endl;
        return 1;
    }
    ll f1 = fib(N);
    ll f2 = fib(N + 1);
    res = (double)f1 / f2;
    printf("%.8lf", res);
    return 1;
}