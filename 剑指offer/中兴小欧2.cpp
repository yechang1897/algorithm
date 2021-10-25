#include<iostream>
#include<algorithm>
using namespace std;

int palindrome(string s) {
    int sz = s.size();
    int res = 0;
    if(sz % 2 != 0) {
        int i = sz / 2 - 1, j = sz / 2 + 1;
        while(i >= 0 && j < sz) {
            res += abs(s[i] - s[j]);
            i--;
            j++;
        }

    } else {
        int i = sz / 2 - 1, j = sz / 2;
        while(i >= 0 && j < sz) {
            res += abs(s[i] - s[j]);
            i--;
            j++;
        }
    }
    return res;
}

int main() {
    string str = "ab";
    cout << palindrome(str);
    return 0;
}