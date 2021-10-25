#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int countSegments(string s) {
    int sz = (int)s.size();
    int res = 0;
    for (int i = 0; i < sz - 1; ++i) {
        if(s[i] != ' ' && res == 0) {
            res++;
        }
        if (s[i] == ' ' && s[i + 1] != ' ') {
            res++;
        }
    }
    // if (s[sz - 1]!= ' ') {
    //     res++;
    // }
    return res;
}

int main() {
    string s = "  Hello, my name is John ";
    cout << countSegments(s);
}