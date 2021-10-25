#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int longestValidParentheses(string s) {
    if((int)s.size() == 1 && s[0] == '(') return 0;
    int res = 0;
    int temp = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(temp % 2 == 0) {
            if(s[i] == '(') {
                temp++;
                if(temp % 2 == 0) {
                    res = max(temp, res);
                }
            } else {
                temp = 0;
            }
        } else {
            if (s[i] == ')') {
                temp++;
                if(temp % 2 == 0) {
                    res = max(temp, res);
                }
            } else {
                temp = 1;
            }
        }
    }
    return res;
}

int longestValidParentheses_2(string s) {
    int res = 0;
    vector<int> dp((int)s.size(), 0);
    for(int i = 0; i < (int)s.size();i++) {
        if(s[i] == ')') {
            if(s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else {
                if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0)+ 2;
                }
            }
        }
        res = max(res, dp[i]);
    }
    return res;  
}

int main() {
    string s = ")()())";
    cout << longestValidParentheses_2(s);
}