#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <ctype.h>
using namespace std;

int maxDepth(string s) {
    vector<char> l;
    int res = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '(') {
            l.emplace_back(s[i]);
        } else if (s[i] == ')') {
            l.pop_back();
        }
        res = max((int)l.size(), res);
    }
    return res;
}

int main() {
    string s = "(1)+((2))+(((3)))";
    cout << maxDepth(s);
}