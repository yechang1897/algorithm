#include<iostream>
#include<algorithm>

using namespace std;

//复杂度优化到O(n)
long long fib_2(long long a, long long b, int n) {
    if (n <= 2) return a;
    return fib_2(a + b, a, n - 1);
}

int main() {
    int N;
    cin >> N;
    cout << fib_2(1, 1, N);
}