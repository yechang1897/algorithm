#include<iostream>

using namespace std;
const int N = 2019 * 2019 + 10;

bool isprime(int n) {
    if(n == 2) return true;

    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false; 
    }
    return true;
}

int main() {
    int res = 1;
    for(int i = 3; i <= N; i++) {
        if(isprime(i)) res++;
        if(res == 2019) {
            cout << i << endl;
            break;
        }
    } 
    cout << res << endl;
}
/*
17569
*/