#include<iostream>

using namespace std;

int cuttingRope(int n) {
    if(n < 4){
        return n - 1;
    }
    long res = 1;
    while(n > 4){
        res  = res * 3 % 1000000007;
        n -= 3;
    }
    return (int) (res * n % 1000000007);
}

int main() {
    int n = 1000;
    cout << cuttingRope(n);
    return 0;
}