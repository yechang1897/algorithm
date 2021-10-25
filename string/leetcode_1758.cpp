#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int minOperations(string s) {
    int sz = (int) s.size();
    int res = 0;
    string s1 = s;
    for (int i = 1; i < sz; ++i) {
        if (s[i] == s[i - 1]) {
            res++;
            s[i] = s[i - 1] == '0' ? '1' : '0';
        }
    }
    int res1 = 1;
    s1[0] = s1[0] == '1' ? '0' : '1';
    for (int i = 1; i < sz; ++i) {
        if (s1[i] == s1[i - 1]) {
            res1++;
            s1[i] = s1[i - 1] == '0' ? '1' : '0';
        }
    }
    return min(res, res1);
}

int main() {
    string s = "10010100";
    cout << minOperations(s);
}