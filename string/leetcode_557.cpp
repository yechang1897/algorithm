#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>

using namespace std;

string reverseWords(string s) {
    vector<string> strs;
    char * p = strtok(s.data(), " ");
    while(p) {
        strs.push_back(p);
        p = strtok(NULL, " ");
    }
    for(int i = 0; i < (int)strs.size(); ++i) {
        reverse(strs[i].begin(), strs[i].end());
    }
    string res;
    for (int i = 0; i < (int)strs.size() - 1; ++i) {
        res += strs[i];
        res += " ";
    }
    res += strs[(int)strs.size() - 1];
    return res;
}

int main() {
    string s = "Let's take LeetCode contest";
    // cout << strtok(s.data(), " ");
    cout << reverseWords(s);
}