#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    int sz = (int) words.size();
    int sz2 = (int) chars.size();
    vector<int> times(26, 0);
    for(int i = 0; i < sz2; ++i) {
        times[chars[i] - 'a']++;
    }
    // for(int i : times) {
    //     cout << i << " ";
    // }
    int res = 0;
    for(int i = 0; i < sz; ++i) {
        vector<int> temp = times;
        // for(int i : temp) {
        //     cout << i << " ";
        // }
        // cout << endl;
        int j;
        for(j = 0; j < (int)words[i].size(); ++j) {
            if(temp[words[i][j] - 'a'] == 0) {
                break;
            } else if(temp[words[i][j] - 'a'] != 0) {
                temp[words[i][j]]--;
            }
        }
        if(j == (int)words[i].size()) {
            res += words[i].size();
        }    
    }
    return res;
}

int main() {
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";
    cout << countCharacters(words,chars);
}