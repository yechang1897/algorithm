#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//复杂度为O(2^n);
int fib_1(int n) {
    if (n < 2) return n;
    return fib_1(n - 1) + fib_1(n - 2);
}
//复杂度优化到O(n)
int fib_2(int a, int b, int n) {
    if (n <= 2) return a;
    return fib_2(a + b, a, n - 1);
}
//动态规划做法
int fib_3(int n) {
    if (n < 2) return n;
    int p = 0, q = 1;
    int t = 0;
    for (int i = 1; i < n; ++i) {
        t = p + q;
        p = q;
        q = t;
        cout << t << endl;
    }
    return t;
}

vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> c{{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return c;
}

vector<vector<int>> matrix_pow(vector<vector<int>>& a, int n) {
    vector<vector<int>> ret{{1, 0}, {0, 1}};
    while (n > 0) {
        if (n & 1) {
            ret = matrix_multiply(ret, a);
        }
        n >>= 1;
        a = matrix_multiply(a, a);
    }
    return ret;
}

int fib_4(int n) {
    if (n < 2) {
        return n;
    }
    vector<vector<int>> q{{1, 1}, {1, 0}};
    vector<vector<int>> res = matrix_pow(q, n - 1);
    return res[0][0];
}

int main() {
    int n = 4;
    cout << fib_4(n);
}