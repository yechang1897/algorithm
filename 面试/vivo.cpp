#include<iostream>
#include<vector>

using namespace std;

bool check(int a) {
    if(a % 7 == 0) return true;
    while(a) {
        int t = a % 10;
        a /= 10;
        if(t == 7) return true;
    }
    return false;
}

int main() {
    vector<int> nums;
    string s;
    cin >> s;
    int res = 0;
    int t = 0;
    for(int i = 0; i < s.size(); i++) {        
        if(s[i] != ' ') {
           t = t * 10 +  (s[i] - '0'); 
        }  
        if(i == s.size() - 1) {
            if(check(t)) res ++;
            t = 0;
        }  
        if(s[i] == ' ') {
            if(check(t)) res ++;
            t = 0;
        }
    }
    cout << res << endl;
    return 0;
}