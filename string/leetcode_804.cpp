#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cmath>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> s= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> res;
    for(int i = 0; i < (int)words.size(); ++i) {
        string temp = "";
        for (int j = 0; j < (int)words[i].size();++j) {
            temp += s[words[i][j] - 'a'];
        }
        res.emplace(temp);
    }
    return (int)res.size();    
}

int main() {
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << uniqueMorseRepresentations(words);
}