#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int numSub(string s) {
    int sz = (int)s.size();
    vector<int> num(sz);
    int flag = 0;    
    for (int i = 0; i < sz; ++i) {
        if (s[i] == '1') {
            flag++;
            num[i] = flag;
        } else if (s[i] == '0') {
            flag = 0;
            num[i] = 0;
        }
    }
    for(int i = 0; i < sz - 1; ++i) {
        if(num[i] != 0 && num[i + 1] != 0) {
            num[i] = 0;
        }
    }
    int res = 0;
    for(int i = 0; i < sz; ++i) {
        if(num[i] != 0) {
            res += ((num[i] * (num[i] + 1)) / 2) % (int)(pow(10,9) + 7);
            cout << res << endl;
        }
    }
    return res;
}

int main() {
    string s = "0110111";
    cout << pow(10, 2) << endl;
    cout << numSub(s);
}