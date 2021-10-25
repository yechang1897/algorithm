#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

bool isGood(string s) {
    for(int i = 0 ; i <(int)s.size() - 1; ++i) {
        if(s[i] + 32 == s[i + 1] || s[i] - 32 == s[i + 1]) {
            return false;
        }
    }
    return true;
}

string makeGood(string s) {
    while(!isGood(s)) {
        int flag = 0;
        while (flag < (int)s.size() - 1) {
            if(s[flag] + 32 == s[flag + 1] || s[flag] - 32 == s[flag + 1]) {
                s.erase(s.begin() + flag);
                s.erase(s.begin() + flag);
            }
            flag++; 
        }
    }
    return s;
}


int main() {
    string s = "abBAcC";
    cout << makeGood(s);
}