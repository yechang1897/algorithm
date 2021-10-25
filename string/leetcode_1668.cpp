#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

vector<int> getNext(string p) {
    int lenp = (int)p.size();
    vector<int> next(lenp, 0);
    next[0] = -1;
    int j = 0;
    int k = -1; 
    while(j < lenp - 1) {
        if(k == -1 || p[j] == p[k]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int kmp(string s, string p) {
    int lens = (int) s.size();
    int lenp = (int) p.size();
    vector<int> next;
    next = getNext(p);
    int i = 0;
    int j = 0;
    while (i < lens && j < lenp) {
        if (j == - 1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == lenp) {
        return i - j;
    } else {
        return -1;
    }
}

int maxRepeating(string sequence, string word) {
    int count = 0 ;
    string words = word;
    while(kmp(sequence, words) != -1) {
        count++;
        words += word;
    }
    return count;
}

int main() {
    string sequence = "aaabaaaabaaabaaaabaaaabaaaabaaaaba", word = "aaaba";
    cout << maxRepeating(sequence, word);
}