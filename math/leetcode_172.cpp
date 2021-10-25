#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int trailingZeroes(int n) {
    int zero = 0;
    while (n > 0) {
        n /= 5;
        zero += n;
    }
    return zero;
}


int trailingZeroes_2(int n) {
    int zeroCount = 0;
    // We need to use long because currentMultiple can potentially become
    // larger than an int.
    long currentMultiple = 5;
    while (n >= currentMultiple) {
        zeroCount += (n / currentMultiple);
        currentMultiple *= 5;
    }
    return zeroCount;
}



int main() {
    int n = 100;
    cout << trailingZeroes_2(n);
}