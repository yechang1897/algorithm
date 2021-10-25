#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string modifyString(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '?') {
            int flag = 0;
            if (i == 0) {
                while(true) {
                    if('a' + flag == s[i + 1]) {
                        flag++;
                    } else {
                        s[i] = 'a' + flag;
                        break;
                    }
                }
            } else if (i == (int)s.size() - 1) {
                while(true) {
                    if('a' + flag == s[i - 1]) {
                        flag++;
                    } else {
                        s[i] = 'a' + flag;
                        break;
                    }
                }
            } else {
                while(true) {
                    if('a' + flag == s[i - 1] || 'a' + flag == s[i + 1]) {
                        flag++;
                    } else {
                        s[i] = 'a' + flag;
                        break;
                    }
                }
            }
        }
    }
    return s;
}

int main() {
    string s = "j?qg??b";
    cout << modifyString(s);
}