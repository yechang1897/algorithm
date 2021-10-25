#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

bool isPowerOfTwo(int n) {
    int flag = 0;
    if(n == 1) return true;
    long temp = 2;
    while((temp << flag) < n) {
        flag++;
    }
    return (2 << flag) == n ? true : false;
}

int main() {
    int n = 16;
    cout << isPowerOfTwo(n);
}