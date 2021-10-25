#include<iostream>

using namespace std;

int addBit(int m, int n) {
    int res = 0;
    int cnt = 0;
    string str = to_string(m);
    for(int i = 0; i < str.size(); i++) {
        cnt += str[i] - '0';
    }
    res += cnt;
    cnt = 0;
    str = to_string(n);
    for(int i = 0; i < str.size(); i++) {
        cnt += str[i] - '0';
    }
    res += cnt;
    return res;
}

int movingCount(int m, int n, int k) {
    int res = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0;j < n; j++) {
            if(addBit(i, j) <= k){ 
                res++;
                cout << addBit(i, j) << endl;
            }
        }
    }
    return res;
}

int main() {
    int m = 16, n = 8, k = 4;
    // cout << addBit(10, 7) << endl;
    cout << movingCount(m, n, k);
    return 0;
}