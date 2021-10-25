#include<iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    //int a = 12, b = 8;
    // cout << gcd(a, b);
    int res = 0;
    for(int i = 1; i <= 2020; i++) {
        for(int j = 1; j <= 2020; j++) {
            if(gcd(i, j) == 1) res++;
        }
    }
    cout << res << endl;
}
/*
res = 2481215  2481215
*/
