#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

bool isValid(string s) {
    stack<char> sta;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else {
            if((int)sta.size() == 0) {
                return false;
            }
            if (s[i] == ')' && sta.top() != '(') {
                return false;
            }
            if (s[i] == ']' && sta.top() != '[') {
                return false;
            }
            if (s[i] == '}' && sta.top() != '{') {
                return false;
            }
            sta.pop();
        }
    }
    return (int)sta.size() == 0 ? true : false;
}

int main () {
    string s = "{[]}";
    cout << isValid(s);
}