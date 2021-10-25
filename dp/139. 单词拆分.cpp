#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;



bool wordBreak(string s, vector<string>& wordDict) {
    int sz = s.size();
    vector<bool> f(sz + 1);
    /*
    f[i] 代表从字符串0 - i - 1位置的可以被拆分成wordDict中的单词
    f[0] = true 表示空串肯定可以找到。
    枚举切分点，保证f[j] 且s[j - i - 1]能够在wordDict中找到 则f【i】为true
    f[j]
    */    
    unordered_set<string> hash;
    for(int i = 0; i < wordDict.size(); i++) {
        hash.insert(wordDict[i]);
    }
    
    f[0] = true;
    for (int i = 1; i <= sz; i++) {
        for(int j = 0; j < i; j++) {
            if(f[j] && hash.find(s.substr(j, i - j)) != hash.end()) f[i] = true;
        }
    }
    return f[sz];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout << wordBreak(s, wordDict);
    return 0;
}