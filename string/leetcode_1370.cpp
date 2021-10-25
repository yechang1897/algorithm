#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

string sortString(string s) {
    unordered_map<char, int> bucket(26);
    for(int i = 0; i < (int)s.size(); i++) {
        int temp = s[i] - 'a';
        if(bucket.find(temp) != bucket.end()) {
            bucket[temp]++;
        } else {
            bucket[temp] = 1;
        }
    }
    string res = "";
    int flag = 0;
    while(flag < (int)s.size()) {
        if(flag % 2 == 0) {
            for (int i = 0; i < 26; i++) {
                if (bucket.find(i) != bucket.end() && bucket[i] != 0) {
                    res.push_back(i + 'a');
                    bucket[i]--;
                }
            }
            flag++;
        } else {
            for (int i = 25; i >= 0; i--) {
                if (bucket.find(i) != bucket.end() && bucket[i] != 0) {
                    res.push_back(i + 'a');
                    bucket[i]--;
                }
            }
            flag++;
        }    
    }    
    return res;        
}

string sortString_2(string s) {
    vector<int> num(26);
    for (char &ch : s) {
        num[ch - 'a']++;
    }
    string ret;
    while (ret.length() < s.length()) {
        for (int i = 0; i < 26; i++) {
            if (num[i]) {
                ret.push_back(i + 'a');
                num[i]--;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (num[i]) {
                ret.push_back(i + 'a');
                num[i]--;
            }
        }
    }
    return ret;
}

string sortString_3(string s) {
    vector<int> bucket(26);
    for(char &c : s) {
        bucket[c - 'a']++;
    }
    string res;
    while(res.size() < s.size()) {
        for (int i = 0; i < 26; i++) {
            if (bucket[i] != 0) {
                res.push_back(i + 'a');
                bucket[i]--;
            }
        }
        for (int i = 25; i > 0; i--) {
            if (bucket[i] != 0) {
                res.push_back(i + 'a');
                bucket[i]--;
            }
        }
    }
    return res;
}

int main() {
    string s = "aaaabbbbcccc";
    cout << sortString_3(s);
}