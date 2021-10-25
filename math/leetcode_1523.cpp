#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int countOdds(int low, int high) {
    if(low == high) return low % 2 == 0 ? 0 : 1;
    int minus = high - low - 1;
    int res = 0;
    if(low % 2 != 0 && high % 2 != 0) {
        res += 2 + minus / 2;
    } else {
        res = minus / 2 + 1;
    }
    return res;
}

int main() {
    int low = 8, high = 10;
    cout << countOdds(low, high);
}