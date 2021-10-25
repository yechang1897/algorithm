#include<iostream>
#include<algorithm>
#include<string>
#include<ctype.h>

using namespace std;
//isalnum 判断是否是数字和字符
bool isPalindrome(string s) {
    int len = s.length();
    int before = 0;
    int after = len - 1;
    // if(len == 2) {
    //     if(isalnum(s[0]) && isalnum(s[1])) {
    //         return s[0] == s[1] ? true : false;
    //     } else if (!isalnum(s[0]) && !isalnum(s[1])) {
    //         return s[0] == s[1] ? true : false;
    //     } else {
    //         return false;
    //     }
    // }
    while(before < after) {
        if(isalnum(s[before]) && isalnum(s[after])) {
            if(toupper(s[before]) == toupper(s[after])) {
                before++;
                after--;
            } else {
                return false;
            }     
        }
        if(!isalnum(s[before]) && before < after) {
            before++;
        }
        if(!isalnum(s[after]) && before < after) {
            after--;
        }
    }
    return before >= after ? true : false;
}

int main() {
    string s = "a.";
    // cout << isalpha('0');
    // cout << toupper('a');
    cout << isPalindrome(s);
}