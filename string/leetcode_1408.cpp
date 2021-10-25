#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cmath>

using namespace std;

bool myfunction(string s1, string s2) {
    return s1.size() < s2.size();
}

vector<string> stringMatching(vector<string>& words) {
    vector<string> res;
    sort(words.begin(), words.end(), myfunction);
    for(int i = 0; i < (int)words.size(); ++i) {
        for (int j = i + 1; j < (int)words.size();++j) {
            if(words[j].find(words[i])!= string::npos) {
                res.push_back(words[i]);
            }
        }
    }
    return res;
}

int main() {
    vector<string> words = {"leetcode","et","code"};
    vector<string> res = stringMatching(words);
    for (string i : res) {
        cout << i << " ";
    }
    cout << endl;
}