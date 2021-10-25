#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    char last = ' ';
    string str;
    getline(cin, str);
    int sz = str.size();
    vector<char> res;
    for(int i = 0; i < sz; i++) {
        // cout << i << endl;
        if(str[i] == ' ') continue;
        else if(str[i] != last) {
            res.push_back(str[i]);
            last = str[i];
        } else {
            continue;
        }        
    }
    for(auto x : res)
        cout << x;    
    return 0;
}