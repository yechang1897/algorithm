#include<iostream>
#include<string>

using namespace std;
//还可以用栈方法
string minRemoveToMakeValid(string s) {
    int flag = 0;
    int i = 0;
    while(i < (int)s.size()) {
        if(s[i] == ')') {
            flag--;
        } else if (s[i] == '(') {
            flag++;
        }
        if(flag < 0 && s[i] == ')') {
            s.erase(s.begin() + i);
            flag++;
            continue;
        }
        i++;
    }
    cout << s << endl;
    cout << flag << endl;
    i = (int)s.size();
    while(i >= 0) {
        if(flag > 0 && s[i] == '(') {
            s.erase(s.begin() + i);
            flag--;
            continue;
        }
        i--;
    }
    return s;
}

int main() {
    string s = "())()(((";
    cout << minRemoveToMakeValid(s);
}