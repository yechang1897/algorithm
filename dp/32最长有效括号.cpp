#include<iostream>
#include<string>

using namespace std;

const int N = 1e4 + 5;
int f[N];

int longestValidParentheses(string s) {
    int n = s.size();
    int res = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == ')') {
            if(s[i - 1] == '(') f[i] = (i >= 2 ? f[i - 2] : 0) + 2;
            else if(i - f[i - 1] > 0 && s[i - f[i - 1] - 1] == '(') f[i] = f[i - 1] + 2 + (i - f[i - 1] >= 2 ?  f[i - f[i - 1] - 2] : 0);
        }
        res = max(res, f[i]);
    }
    for(int i = 0; i < n; i++) {
        // cout << f[i] << " ";
    }
    return res;
}


int main() {
    string str = "))))((()((";
    cout << longestValidParentheses(str); 
}