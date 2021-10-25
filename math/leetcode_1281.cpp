#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int subtractProductAndSum(int n) {
    int times = 1;
    int sum = 0;
    while(n > 0) {
        times *= (n % 10);
        sum += (n % 10);
        n /= 10;
    }
    return times - sum;
}

int main() {
    int n = 4421;
    cout << subtractProductAndSum(n);
}