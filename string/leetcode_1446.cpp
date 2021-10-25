#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cmath>

using namespace std;

int maxPower(string s) {
    int res = 0;
    int temp = 1;
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        if(s[i] == s[i + 1]) {
            temp++;
        } else {
            temp = 1;
        }
        res = max(temp, res);
    }
    return res;
}

int main() {
    string s = "abbcccddddeeeeedcba";
    cout << maxPower(s);
}