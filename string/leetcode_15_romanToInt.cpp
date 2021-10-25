#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int romanToInt(string s) {
    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int first = 0, second = 1;
    int res = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(m[s[first]] >= m[s[second]]) {
            res += m[s[first]];
            first++;
            second++;
        } else {
            res += m[s[second]] - m[s[first]];
            first += 2;
            second += 2;
        }
    }
    return res;
}

int main(){
    string s = "MCMXCIVI";
    // cout << (typeid(s[0]) == typeid(char));
    cout << romanToInt(s);
}