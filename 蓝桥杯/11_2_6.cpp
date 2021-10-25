#include<iostream>
#include<string>
#include<stack>
using namespace std;

string s;

// int main() {
//     cin >> s;
//     int sz = s.size();
//     string res = "";
//     char t;
//     char p;
//     int n = 0;
//     t = s[0];
//     for(int i = 0; i < s.size(); i++) {
//         p = s[i];
//         if(p != t) {
//             res.push_back(t);
//             res += to_string(n);
//             t = p;
//             n = 1;
//             continue; 
//         }
//         n++;
        
//     }
//     if(s[sz - 1] == s[sz - 2]) {
//         res.push_back(p);
//         res += to_string(n);
//     } else {
//         res.push_back(p);
//         res += to_string(1);
//     }
//     cout << res << endl;
// }

void reverse(string& s){
    int sz = s.size();
    string str = "";
    for(int i = sz - 1; i >= 0; i--) {
        str.push_back(s[i]);
    }
    s = str;
}

int main() {
    cin >> s;
    stack<char> stk;
    string res;
    int sz = s.size();
    int i = 0;
    while(i < sz) {
        if('0' > s[i] || s[i] > '9') {
            stk.push(s[i]);
        } else {
            string t = "";
            char temp = stk.top();
            stk.pop();
            while(!stk.empty()) {
                t.push_back(stk.top());
                stk.pop();
            }
            reverse(t);
            int k = i;
            int num = 0;
            while('0' <= s[k] && s[k] <= '9') {
                num = num * 10 + (s[k] - '0');
                k++;
            }
            res.append(t);
            i = k;
            while(num--) {
                res.push_back(temp);
            }
            continue;
        }
        i++;
    }
    cout << res << endl;
}