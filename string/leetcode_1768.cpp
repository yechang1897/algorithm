#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

string mergeAlternately(string word1, string word2) {
    int sz1 = (int)word1.size();
    int sz2 = (int)word2.size();
    int i = 0, j = 0;
    string res;
    while (i < sz1 && j < sz2) {
        res.push_back(word1[i]);
        res.push_back(word2[j]);
        i++;
        j++;
    }
    if(sz1 < sz2) {
        return res += word2.substr(j, sz2 - j);
    } else {
        return res += word1.substr(i, sz1 - i);
    }
}

int main() {
    string word1 = "ab", word2 = "pqcd";
    cout << mergeAlternately(word1, word2);
}