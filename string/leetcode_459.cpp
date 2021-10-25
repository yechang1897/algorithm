#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool repeatedSubstringPattern(string s) {
    return (s + s).find(s, 1) != s.size();
}

int main() {
    string s = "ababc";
    cout << ((s + s).find(s, 1)) << endl;;
    cout << repeatedSubstringPattern(s);
}