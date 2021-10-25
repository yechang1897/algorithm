#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    int sz = (int)s.size();
    int ans = -1;
    unordered_map<int, int> hash;
    for (int i = 0; i < sz; ++i) {
        if (!hash.count(s[i])) {
            hash[s[i]] = i; 
        }
        else {
            ans = max(ans, i - hash[s[i]] - 1);
        }
    }
    return ans; 
}

int main() {
    string s = "cabbac";
    cout << maxLengthBetweenEqualCharacters(s);
}