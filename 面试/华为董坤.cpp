#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;

unordered_set<char> s = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
//判断合法
bool check(string str) {
    int sz = str.size();
    if(sz != 2) {
        return false;
    }
    if(s.find(str[0]) == s.end()) {
        return false;
    }
    if(s.find(str[1]) == s.end()) {
        return false;
    }
    return true;
}
//转小写
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    string str;
    cin >> str;
    unordered_set<string> nums;
    stringstream ss(str);
    while(getline(ss, str, '-')) {
        string t = toLowerCase(str);
        if(check(t)) {
            nums.insert(t);
        }
    }
    int sz = nums.size();
    cout << (sz - 6 + 1) << endl;
}