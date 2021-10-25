#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string breakPalindrome(string palindrome) {
    if (palindrome.size() <= 1) return "";
    for (int i = 0, n = palindrome.size(); i <= int (0.5 * n); i ++) {
        if (i == int (0.5 * n)) {palindrome[n - 1] = 'b'; break;}
        if (palindrome[i] != 'a') {palindrome[i] = 'a'; break;}
    }
    return palindrome;
}

int main() {
    string palindrome = "abccba";
    cout <<breakPalindrome(palindrome);
}