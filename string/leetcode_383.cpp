#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> ma;
    for(int i = 0; i < (int)magazine.size(); ++i) {
        if(ma.find(magazine[i]) == ma.end()) {
            ma[magazine[i]] = 1;
        } else {
            ma[magazine[i]]++;
        }
    }
    for(int i = 0; i < (int)ransomNote.size(); ++i) {
        if(ma[ransomNote[i]] != 0) {
            ma[ransomNote[i]]--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string ransomNote = "bg", magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
    cout << canConstruct(ransomNote, magazine);
}