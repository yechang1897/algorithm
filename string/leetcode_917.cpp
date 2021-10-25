#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <ctype.h>
using namespace std;

string reverseOnlyLetters(string S) {
    int l = 0; 
    int r = (int)S.size();
    while(l < r) {
        while(!isalpha(S[l]) && l < r) {
            l++;
        }
        while(!isalpha(S[r]) && l < r) {
            r--;
        }
        char temp = S[l];
        S[l] = S[r];
        S[r] = temp;
        l++;
        r--;
    }
    return S;
}

int main() {
    string str = "7_28]";
    cout << reverseOnlyLetters(str);
}