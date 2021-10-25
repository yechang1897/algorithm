#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;


bool halvesAreAlike(string s) {
    unordered_set<char> vol = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int sz = (int)s.size();
    string before = s.substr(0, sz / 2);
    string after = s.substr(sz / 2, sz);
    int befNum = 0;
    int aftNum = 0;
    for (int i = 0 ; i < sz / 2; ++i) {
        if(vol.find(before[i]) != vol.end()) {
            befNum++;
        }
        if(vol.find(after[i]) != vol.end()) {
            aftNum++;
        }
    }
    return befNum == aftNum ? 1 : 0;
}

int main() {
    string s = "textbook";
    cout << halvesAreAlike(s);
}