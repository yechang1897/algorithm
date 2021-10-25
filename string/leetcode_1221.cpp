#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

int balancedStringSplit(string s) {
    stack<char> sta;
    sta.push(s[0]);
    int res = 0;
    for(int i = 1; i < (int)s.size(); ++i) {
        if((int)sta.size() == 0 || sta.top() == s[i]) {
            sta.push(s[i]);
        } else {
            sta.pop();
        }
        if((int)sta.size() == 0) {
            res++;
        }
    }
    return res;
}

int main() {
    string  s = "LLLLRRRR";
    cout << balancedStringSplit(s);
}