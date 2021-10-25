#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int change(string s) {
    int flag = 0;
    int sz = s.size();
    int flag1 = 0;
    for(flag1 = 0; flag1 < sz; flag1++) {
        if(s[flag1] != '0') {
            break;
        }
    }
    if(flag1 == sz) {
        return 0;
    }
    while(s[flag] == '0') {
        s.erase(flag, 1);
    }
    int res = 0;
    for(int i = s.size() - 1; i >= 0; --i ) {
        res += (s[i] - '0') * pow(10, (int)s.size() - 1 - i);
    }
    return res;
}

vector<int> getNum(string s) {
    string temp; 
    vector<int> res;
    for(int i = 0; i < (int)s.size(); ++i) {
        if(s[i] < '0' || s[i] > '9' || i == (int)s.size() - 1) {
            if(temp.size() != 0) {
                cout << temp << endl;
                int tempNum = change(temp);
                res.push_back(tempNum);
                temp = "";
            }
        } else {
            temp.push_back(s[i]);
        }
    }
    return res;
}

bool isTrue(vector<int>)

void allSubset(vector<int>& nums) {
    for(int i = 0; i < )
}

int main() {
    string s = "a0125b1c0d00";
    for(int s : getNum(s)) {
        cout << s << " ";
    }
    cout << endl;
    // cout << change("000");
}