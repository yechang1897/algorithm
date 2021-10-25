#include<iostream>
#include<vector>
using namespace std;

char firstUniqChar(string s) {
    vector<pair<char,int>> cs;
    for(int i = 0; i < s.size(); i++) {
        int j;
        for(j = 0; j < cs.size(); j++) {
            if(s[i] == cs[j].first){ 
                cs[j].second++;
                break;
            }
        }
        if(j == cs.size()) {
            // auto x = make_pair(s[i], 1);
            // cout << x.first << " " << x.second << endl;
            cs.push_back({s[i], 1});
        }
    }
    // cout << cs.size() << endl;
    for(int i = 0; i < cs.size(); i++) {
        if(cs[i].second == 1) return cs[i].first;
    }
    return ' ';
}

int main() {
    string s = "abaccdeff";
    cout << firstUniqChar(s);
    return 0;
}