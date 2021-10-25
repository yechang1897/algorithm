#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string say(string s) {
    string res;
    int count = 1;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == s[i + 1]) {
            count++;
        } else {
            res += string(1, count + '0') + string(1, s[i]);
            count = 1;
        }
    }
    return res;
}

string countAndSay(int n) {
    if(n == 1) return "1";
    return say(countAndSay(n - 1));
}

int main() {
    int n = 4;
    cout << countAndSay(n);
}