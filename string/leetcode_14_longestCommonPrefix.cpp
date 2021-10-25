#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int len = (int)strs.size();
    string res;
    bool flag = true;
    string temp = strs[0];
    int n = 0;
    while(n < (int)temp.length()) {
        for(int i = 1; i < len; i++) {
            if(strs[i][n] != temp[n]) {
                flag = false;
            }
        }
        if(flag) {
            res += temp[n];
        }
        n++;
    }
    return res; 
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs);
}